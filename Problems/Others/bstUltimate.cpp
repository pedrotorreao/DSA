/******************************************************************************
 -- Trees - Binary Search Tree: A complete implementation
*******************************************************************************/

#include <iomanip>
#include <iostream>
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

bool BST::searchValue(Node *root, int value) {}
bool BST::isBST(Node *root) {}
bool BST::isBalanced_1(Node *root) {}
bool BST::isBalanced_2(Node *root) {}
bool BST::isLeafNode(Node *root) {}

int BST::getMinValue(Node *root) {}
int BST::getMaxValue(Node *root) {}
int BST::getHeight_1(Node *root) {}
int BST::getHeight_2(Node *root) {}
int BST::getMinHeight(Node *root) {}
int BST::getMaxHeight(Node *root) {}
int BST::getLeafSum(Node *root) {}

void BST::inOrder(Node *root) {}
void BST::preOrder(Node *root) {}
void BST::postOrder(Node *root) {}
void BST::levelOrder(Node *root) {}

std::string BST::serializeBST(Node *root) {}

int main() {
  //.. test cases

  return 0;
}
