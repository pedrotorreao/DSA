/******************************************************************************
 -- Trees - Binary Search Tree: A complete implementation
*******************************************************************************/

#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>

class Node {
public:
  int data;
  Node *left, *right;

  Node(int value)
      : data{value}, left{nullptr}, right{nullptr} {}
};

class BST {
public:
  Node *insertValue_Iter(Node *root, int value);
  Node *insertValue_Rec(Node *root, int value);
  Node *removeValue(Node *root, int value);
  Node *getNode(Node *root, int value);
  Node *deSerializeTree(std::string bst_str);

  bool searchValue(Node *root, int value);
  bool isBST(Node *root);
  bool isBalanced_1(Node *root);
  bool isBalanced_2(Node *root);
  bool isLeafNode(Node *root);

  int getMinValue(Node *root);
  int getMaxValue(Node *root);
  int getHeight_1(Node *root);
  int getHeight_2(Node *root);
  int getMinHeight(Node *root);
  int getMaxHeight(Node *root);
  int getLeafSum(Node *root);

  void inOrder(Node *root);
  void preOrder(Node *root);
  void postOrder(Node *root);
  void levelOrder(Node *root);

  std::string serializeBST(Node *root);
};

Node *BST::insertValue_Iter(Node *root, int value) {
  if (root == nullptr) {
    return new Node(value);
  }

  Node *current = root;

  while (current != nullptr) {
    if (value < current->data) {
      if (current->left == nullptr) {
        current->left = new Node(value);
        break;
      }
      current = current->left;
    } else if (value > current->data) {
      if (current->right == nullptr) {
        current->right = new Node(value);
        break;
      }
      current = current->right;
    } else
      break;
  }

  return root;
}

Node *BST::insertValue_Rec(Node *root, int value) {
  if (root == nullptr) {
    return new Node(value);
  } else if (value < root->data) {
    root->left = insertValue_Rec(root->left, value);
  } else if (value > root->data) {
    root->right = insertValue_Rec(root->right, value);
  } else {
    return nullptr;
  }
}

Node *BST::removeValue(Node *root, int value) {
  if (root == nullptr)
    return nullptr;

  // found target node:
  if (root->data == value) {
    // case #1 - node has no children:
    //    remove it by setting it to nullptr
    if (root->left == nullptr && root->right == nullptr)
      return nullptr;

    // case #2 - node doesn't have one of its children (subtrees):
    //    replace it by its existent child
    if (root->left == nullptr)
      return root->right;
    if (root->right == nullptr)
      return root->left;

    // case #3 - node has both children:
    //    find its right child leftmost child (leftmost)
    Node *leftmost = root->right;
    while (leftmost->left != nullptr)
      leftmost = leftmost->left;
    //    replace target node value by leftmost's value
    root->data = leftmost->data;
    //    remove leftmost from its original place
    root->right = removeValue(root->right, leftmost->data);
    //    return updated tree:
    return root;
  }
  // target node value is less than current node':
  if (value < root->data) {
    root->left = removeValue(root->left, value);
    return root;
  }
  // target node value is greater than current node':
  if (value > root->data) {
    root->right = removeValue(root->right, value);
    return root;
  }

  return nullptr;
}

Node *BST::getNode(Node *root, int value) {
  if (root == nullptr)
    return nullptr;

  if (root->data == value)
    return root;

  if (value < root->data)
    return getNode(root->left, value);

  if (value > root->data)
    return getNode(root->right, value);
}

Node *BST::deSerializeTree(std::string bst_str) {}

bool BST::searchValue(Node *root, int value) {
  // if root is a valid node:
  if (root != nullptr) {
    // target node found:
    if (value == root->data)
      return true;
    // target node value is less than current node':
    if (value < root->data)
      return searchValue(root->left, value);
    // target node value is greater than current node':
    if (value > root->data)
      return searchValue(root->right, value);
  }
  return false;
}

bool BST::isBST(Node *root) {
  return isBST_Helper(root, INT_MIN, INT_MAX);
}
bool isBST_Helper(Node *node, int min, int max) {
  if (node == nullptr)
    return true;

  if ((node->data <= min) || (node->data >= max))
    return false;

  return (isBST_Helper(node->left, min, node->data) && isBST_Helper(node->right, node->data, max));
}

bool BST::isBalanced_1(Node *root) {}
bool BST::isBalanced_2(Node *root) {}
bool BST::isLeafNode(Node *root) {
  if (root == nullptr)
    return false;

  return ((root->left == nullptr) && (root->right == nullptr));
}

int BST::getMinValue(Node *root) {
  // if tree is empty, return max. integer value as indicative:
  if (root == nullptr)
    return INT_MAX;

  // since this is a BST, the minimum value will the value at
  // the leftmost position, traverse the tree to it and return
  // its value:
  Node *leftmost = root;
  while (leftmost->left != nullptr)
    leftmost = leftmost->left;

  return leftmost->data;
}

int BST::getMaxValue(Node *root) {
  // if tree is empty, return min. integer value as indicative:
  if (root == nullptr)
    return INT_MIN;

  // since this is a BST, the maximum value will the value at
  // the rightmost position, traverse the tree to it and return
  // its value:
  Node *rightmost = root;
  while (rightmost->right != nullptr)
    rightmost = rightmost->right;

  return rightmost->data;
}

int BST::getHeight_1(Node *root) {
  // node can be NULL:
  //  1. if the tree is empty, we return -1 to indicate that.
  //  2. if the previous node is a leaf node, we return -1 so we
  //     don't take this node into account in the height sum.
  if (root == nullptr)
    return -1;
  // for each node, we recursively call getHeight() for both of
  // its children until we get to a leaf node from where we unwind
  // the stack building the resulting sum:
  int l_child = getHeight_1(root->left);
  int r_child = getHeight_1(root->right);
  // once we get to the leaf nodes for both children of a given node,
  // we compare their height values, get the max height between them and
  // increment the height to account for one more level:
  return ((l_child > r_child) ? (l_child + 1) : (r_child + 1));
}
int BST::getHeight_2(Node *root) {}
int BST::getMinHeight(Node *root) {}
int BST::getMaxHeight(Node *root) {}
int BST::getLeafSum(Node *root) {}

void BST::inOrder(Node *root) {
  // traversal order:
  //    left --> root --> right
  if (root != nullptr) {
    inOrder(root->left);
    std::cout << root->data << "   ";
    inOrder(root->right);
  }
}

void BST::preOrder(Node *root) {
  // traversal order:
  //     root --> left --> right
  if (root != nullptr) {
    std::cout << root->data << "   ";
    inOrder(root->left);
    inOrder(root->right);
  }
}

void BST::postOrder(Node *root) {
  // traversal order:
  //     left --> right --> root
  if (root != nullptr) {
    inOrder(root->left);
    inOrder(root->right);
    std::cout << root->data << "   ";
  }
}

void BST::levelOrder(Node *root) {
  // traversal order:
  //     level 0: root
  //        --> level 1: nodes 1 edge away
  //            --> level 2: nodes 2 edges away ...
  if (root != nullptr) {
    // queue to store current node' children,
    // i.e. nodes one step away:
    std::queue<Node *> q;
    q.push(root);

    // iterate while there are still nodes to traverse:
    while (!q.empty()) {
      // get the next node to traverse:
      Node *current = q.front();
      q.pop();

      std::cout << root->data << "   ";

      // push its children to the queue so they can be
      // traversed next:
      if (current->left != nullptr)
        q.push(current->left);
      if (current->right != nullptr)
        q.push(current->right);
    }
  }
}

std::string BST::serializeBST(Node *root) {}

int main() {
  //.. test cases

  return 0;
}
