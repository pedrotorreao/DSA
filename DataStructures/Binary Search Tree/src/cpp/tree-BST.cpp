#include <stdio.h>
#include <iostream>
#include <vector>

class Node
{
public:
  int value;
  Node *left;
  Node *right;

  Node(int data)
  {
    value = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinarySearchTree
{
public:
  Node *insert(Node *root, int d)
  {
    if (root == nullptr)
    {
      return new Node(d);
    }

    Node *currentNode = root;

    while (currentNode != nullptr)
    {
      if (d < currentNode->value)
      {
        if (currentNode->left == nullptr)
        {
          currentNode->left = new Node(d);
          return root;
        }
        else
        {
          currentNode = currentNode->left;
        }
      }
      else if (d > currentNode->value)
      {
        if (currentNode->right == nullptr)
        {
          currentNode->right = new Node(d);
          return root;
        }
        else
        {
          currentNode = currentNode->right;
        }
      }
    }
  }

  bool lookup(Node *root, int d)
  {
    if (root != nullptr)
    {
      Node *currentNode = root;

      while (currentNode != nullptr)
      {
        if (currentNode->value == d)
        {
          std::cout << "\n"
                    << d << " is on the tree!"
                    << "\n";
          return true;
        }
        if (d < currentNode->value)
        {
          if (currentNode->left == nullptr)
          {
            std::cout << "\n"
                      << d << " is NOT on the tree!"
                      << "\n";
            return false;
          }
          currentNode = currentNode->left;
        }
        else if (d > currentNode->value)
        {
          if (currentNode->right == nullptr)
          {
            std::cout << "\n"
                      << d << " is NOT on the tree!"
                      << "\n";
            return false;
          }
          currentNode = currentNode->right;
        }
      }
    }
  }

  Node *remove(Node *root, int d)
  {
    if (root == nullptr)
    {
      return nullptr;
    }
    // if we found the value:
    if (root->value == d)
    {
      // node has no children:
      if ((root->left == nullptr) && (root->right == nullptr))
      {
        return nullptr;
      }
      // node has no left child, replace it w/ right child:
      if (root->left == nullptr)
      {
        return root->right;
      }
      // node has no right child, replace it w/ left child:
      if (root->right == nullptr)
      {
        return root->left;
      }
      // node has both children, find its right child leftmost child:
      Node *currentNode = root->right;
      while (currentNode->left != nullptr)
      {
        currentNode = currentNode->left;
      }
      // replace removed node with right child leftmost child and remove
      // right child leftmost child from its original place:
      root->value = currentNode->value;
      root->right = remove(root->right, currentNode->value);

      return root;
    }
    // value to remove is less than node value, search left subtree:
    if (d < root->value)
    {
      root->left = remove(root->left, d);
      return root;
    }
    // value to remove is more than node value, search right subtree:
    if (d > root->value)
    {
      root->right = remove(root->right, d);
      return root;
    }
  }

  int minValue(Node *root)
  {
    Node *currentNode = root;
    while (currentNode->left != nullptr)
    {
      currentNode = currentNode->left;
    }
    return currentNode->value;
  }

  int maxValue(Node *root)
  {
    Node *currentNode = root;
    while (currentNode->right != nullptr)
    {
      currentNode = currentNode->right;
    }
    return currentNode->value;
  }

  int getHeight(Node *root)
  {
    if (root == nullptr)
    {
      return -1;
    }
    int l = getHeight(root->left);
    int r = getHeight(root->right);

    return (l > r) ? (l + 1) : (r + 1);
  }

  void levelOrder(Node *root)
  {
    std::vector<Node *> q; // could use a STL queue here, but I don't remember :P

    if (root != nullptr)
    {
      q.push_back(root);
      while (q.size())
      {
        Node *current = q.at(0);           // dequeue
        q.erase(q.begin(), q.begin() + 1); //get rid of vec(0)

        std::cout << current->value << " ";

        if (current->left)
          q.push_back(current->left);
        if (current->right)
          q.push_back(current->right);
      }
    }
  }

  void inOrder(Node *root)
  {
    if (root != nullptr)
    {
      inOrder(root->left);
      std::cout << root->value << " ";
      inOrder(root->right);
    }
  }

  void preOrder(Node *root)
  {
    if (root != nullptr)
    {
      std::cout << root->value << " ";
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
      std::cout << root->value << " ";
    }
  }
};

int main()
{
  BinarySearchTree bst;

  Node *root = nullptr;

  root = bst.insert(root, 5);
  root = bst.insert(root, 3);
  root = bst.insert(root, 8);
  root = bst.insert(root, 2);
  root = bst.insert(root, 7);
  root = bst.insert(root, 10);

  std::cout << "\n--- in order traversal: ";
  bst.inOrder(root);

  std::cout << "\n--- pre order traversal: ";
  bst.preOrder(root);

  std::cout << "\n--- post order traversal: ";
  bst.postOrder(root);

  std::cout << "\n--- level order traversal: ";
  bst.levelOrder(root);

  bst.lookup(root, 10);
  bst.lookup(root, 1);

  root = bst.remove(root, 5);

  std::cout << "\n--- level order traversal: ";
  bst.levelOrder(root);

  int min = bst.minValue(root);
  std::cout << "\nMin value: " << min << "\n";

  int max = bst.maxValue(root);
  std::cout << "\nMax value: " << max << "\n";

  int h = bst.getHeight(root);
  std::cout << "\nTree height: " << h << "\n";

  std::cout << "\n--- in order traversal: ";
  bst.inOrder(root);

  return 0;
}