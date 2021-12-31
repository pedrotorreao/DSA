#include <iostream>
#include <queue>
#include <cmath>

class Node
{
public:
  int value;
  Node *left;
  Node *right;

  Node(int data) : value{data}, left{nullptr}, right{nullptr} {}
  ~Node() = default;
};

class BST
{
public:
  Node *insert(Node *root, int d)
  {
    if (root == nullptr)
      return new Node(d);

    if (d < root->value)
      root->left = insert(root->left, d);
    else if (d > root->value)
      root->right = insert(root->right, d);
    else
    {
      std::cout << "--CANNOT HAVE REPEATED NODES--\n";
      return root;
    }
    return root;
  }
  Node *remove(Node *root, int d)
  {
    if (root == nullptr)
      return nullptr;

    if (root->value == d)
    {
      if (root->left == nullptr && root->right == nullptr) // no children
        return nullptr;

      if (root->left == nullptr) // no left subtree
        return root->right;
      if (root->right == nullptr) // no right subtree
        return root->left;

      Node *current = root->right;

      while (current->left != nullptr)
        current = current->left;

      root->value = current->value;
      root->right = remove(root->right, current->value);

      return root;
    }
    if (d < root->value)
    {
      root->left = remove(root->left, d);
      return root;
    }
    if (d > root->value)
    {
      root->right = remove(root->right, d);
      return root;
    }
    return nullptr;
  }
  bool search(Node *root, int d)
  {
    if (root != nullptr)
    {
      Node *current = root;
      while (current != nullptr)
      {
        if (current->value == d)
          return true;
        if (d < current->value)
        {
          if (current->left == nullptr)
            return false;
          current = current->left;
        }
        else if (d > current->value)
        {
          if (current->right == nullptr)
            return false;
          current = current->right;
        }
      }
    }
    return false;
  }

  int minValue(Node *root)
  {
    Node *current = root;

    while (current->left != nullptr)
      current = current->left;

    return current->value;
  }
  int maxValue(Node *root)
  {
    Node *current = root;

    while (current->right != nullptr)
      current = current->right;

    return current->value;
  }

  int getHeight(Node *root)
  {
    if (!root)
      return -1;

    int l = getHeight(root->left);
    int r = getHeight(root->right);

    return (l > r) ? (l + 1) : (r + 1);
  }
  int getHeight_2(Node *root)
  {
    if (root == nullptr)
      return -1;

    return std::max(getHeight_2(root->left), getHeight_2(root->right)) + 1;
  }
  int minHeight(Node *root)
  {
    if (!root)
      return -1;

    int l = getHeight(root->left);
    int r = getHeight(root->right);

    return (l < r) ? (l + 1) : (r + 1);
  }
  int maxHeight(Node *root)
  {
    return getHeight(root);
  }

  bool isBalanced_1(Node *root)
  {
    return (minHeight(root) > (maxHeight(root) - 1));
  }
  bool isBalanced_2(Node *root)
  {
    if (!root)
      return true;

    int balanceFactor = abs(getHeight(root->left) - getHeight(root->right));

    return (balanceFactor <= 1);
  }

  int leafSum(Node *root)
  {
    if (root == nullptr)
      return 0;

    if (isLeaf(root))
      return root->value;

    int total{0};

    total = leafSum(root->left) + leafSum(root->right);

    return total;
  }
  bool isLeaf(Node *node)
  {
    return (node->left == nullptr && node->right == nullptr);
  }

  void inOrder(Node *root)
  {
    if (root != nullptr)
    {
      inOrder(root->left);
      std::cout << root->value << "  ";
      inOrder(root->right);
    }
  }
  void preOrder(Node *root)
  {
    if (root != nullptr)
    {
      std::cout << root->value << "  ";
      preOrder(root->left);
      preOrder(root->right);
    }
  }
  void postOrder(Node *root)
  {
    if (root != nullptr)
    {
      postOrder(root->left);
      postOrder(root->right);
      std::cout << root->value << "  ";
    }
  }
  void levelOrder(Node *root)
  {
    if (root != nullptr)
    {
      std::queue<Node *> q;
      q.push(root);

      while (!q.empty())
      {
        Node *current = q.front();
        q.pop();

        std::cout << current->value << "  ";
        if (current->left)
          q.push(current->left);
        if (current->right)
          q.push(current->right);
      }
    }
  }
};

int main()
{
  std::cout << std::boolalpha;

  BST bst;

  Node *root = nullptr;

  root = bst.insert(root, 15);
  root = bst.insert(root, 7);
  root = bst.insert(root, 21);
  root = bst.insert(root, 5);
  root = bst.insert(root, 12);
  root = bst.insert(root, 18);
  root = bst.insert(root, 28);

  bst.inOrder(root);
  std::cout << "\n";

  root = bst.insert(root, 7);

  bst.inOrder(root);
  std::cout << "\n";

  root = bst.remove(root, 5);

  bst.inOrder(root);
  std::cout << "\n";

  root = bst.insert(root, 3);
  root = bst.insert(root, 1);

  bst.inOrder(root);
  std::cout << "\n";

  root = bst.remove(root, 12);

  bst.inOrder(root);
  std::cout << "\n";

  root = bst.remove(root, 15);

  bst.inOrder(root);
  std::cout << "\n";

  root = bst.insert(root, 5);
  root = bst.insert(root, 4);
  root = bst.insert(root, 10);

  bst.inOrder(root);
  std::cout << "\n";

  std::cout << "Min. value: " << bst.minValue(root) << "\n";
  std::cout << "Max. value: " << bst.maxValue(root) << "\n";
  std::cout << "Tree height: " << bst.getHeight(root) << "\n";
  std::cout << "Tree height v2: " << bst.getHeight_2(root) << "\n";
  std::cout << "Min. height: " << bst.minHeight(root) << "\n";
  std::cout << "Max. height: " << bst.maxHeight(root) << "\n";

  std::cout << "Tree is balanced: " << bst.isBalanced_1(root) << "\n";
  std::cout << "Tree is balanced: " << bst.isBalanced_2(root) << "\n";

  std::cout << "-- In order traversal: ";
  bst.inOrder(root);
  std::cout << "\n";

  std::cout << "-- Pre order traversal: ";
  bst.preOrder(root);
  std::cout << "\n";

  std::cout << "-- Post order traversal: ";
  bst.postOrder(root);
  std::cout << "\n";

  std::cout << "-- Level order traversal: ";
  bst.levelOrder(root);
  std::cout << "\n";

  std::cout << "Leaf sum: " << bst.leafSum(root);
  std::cout << "\n";

  return 0;
}
