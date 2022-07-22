#include <climits>
#include <iomanip>
#include <iostream>
#include <queue>
#include <sstream>
#include <string>

#define MARKER -919293

class TreeNode {
public:
  int value;
  TreeNode *left;
  TreeNode *right;

  TreeNode() : value{0}, left{nullptr}, right{nullptr} {}
  TreeNode(int val) : value{val}, left{nullptr}, right{nullptr} {}
  ~TreeNode() = default;
};

class BinarySearchTree {
public:
  /**
   * @brief Add a new value 'val' to the binary search tree iteratively.
   *
   * @param TreeNode*
   * @param val
   * @return TreeNode*
   */
  TreeNode *insert_ite(TreeNode *root, int val) {
    // if tree is empty, add val to the root node:
    if (root == nullptr) {
      return new TreeNode(val);
    }

    TreeNode *new_node = new TreeNode(val);
    TreeNode *cur_node = root;

    while (cur_node != nullptr) {
      // new value is less than current node value, follow left subtree:
      if (val < cur_node->value) {
        // if an empty reference is found, fill it with new_node:
        if (cur_node->left == nullptr) {
          cur_node->left = new_node;
          break;
        }
        // otherwise, go down the left path:
        cur_node = cur_node->left;
      }
      // new value is larger than current node value, follow right subtree:
      else if (val > cur_node->value) {
        // if an empty reference is found, fill it with new_node:
        if (cur_node->right == nullptr) {
          cur_node->right = new_node;
          break;
        }
        // otherwise, go down the right path:
        cur_node = cur_node->right;
      }
      // do nothing:
      else
        break;
    }

    return root;
  }

  /**
   * @brief Add a new value 'val' to the binary search tree recursively.
   *
   * @param TreeNode*
   * @param val
   * @return TreeNode*
   */
  TreeNode *insert_rec(TreeNode *root, int val) {
    if (root == nullptr)
      return new TreeNode(val);

    if (val < root->value)
      root->left = insert_rec(root->left, val);
    else if (val > root->value)
      root->right = insert_rec(root->right, val);

    return root;
  }

  /**
   * @brief Delete a value 'val' from the binary search tree.
   *
   * @param TreeNode*
   * @param val
   * @return TreeNode*
   */
  TreeNode *remove(TreeNode *root, int val) {
    // tree is empty or value was not found:
    if (root == nullptr)
      return nullptr;
    // found node with the target value:
    if (root->value == val) {
      // case #1 - node has no children, i.e. it is a leaf node:
      //    remove it by setting it to nullptr:
      if (root->left == nullptr && root->right == nullptr)
        return nullptr;

      // case #2 - node doesn't have one of its children (subtrees):
      //    replace it by the existing children:
      if (root->left == nullptr)
        return root->right;
      if (root->right == nullptr)
        return root->left;

      // case #3 - node has both children:
      //    find its right child leftmost child (leftmost_node):
      TreeNode *leftmost_node = root->right;
      while (leftmost_node->left != nullptr)
        leftmost_node = leftmost_node->left;
      //    replace target node value by leftmost_node's value:
      root->value = leftmost_node->value;
      //    remove leftmost_node from its original location:
      root->right = remove(root->right, leftmost_node->value);

      // return updated tree:
      return root;
    }
    // target node value is less than current node's, proceed looking left:
    if (val < root->value) {
      root->left = remove(root->left, val);
      return root;
    }
    // target node value is greater than current node's, proceed looking right:
    if (val > root->value) {
      root->right = remove(root->right, val);
      return root;
    }

    return nullptr;
  }

  /**
   * @brief Retrive node with a given value. Search iteratively.
   *
   * @param TreeNode*
   * @param val
   * @return TreeNode*
   */
  TreeNode *get_node_ite(TreeNode *root, int val) {
    if (root == nullptr)
      return nullptr;

    TreeNode *cur_node = root;
    while (cur_node != nullptr) {
      if (cur_node->value == val)
        break;

      if (val < cur_node->value)
        cur_node = cur_node->left;
      else
        cur_node = cur_node->right;
    }

    return cur_node;
  }
  /**
   * @brief Retrive node with a given value. Search recursively.
   *
   * @param TreeNode*
   * @param val
   * @return TreeNode*
   */
  TreeNode *get_node_rec(TreeNode *root, int val) {
    if (root != nullptr) {
      if (root->value == val)
        return root;
      if (val < root->value)
        return get_node_rec(root->left, val);
      if (val > root->value)
        return get_node_rec(root->right, val);
    }
    return nullptr;
  }

  /**
   * @brief Get the min node value present in the tree.
   *
   * @param TreeNode*
   * @return int
   */
  int get_min_val(TreeNode *root) {
    if (root == nullptr)
      return INT_MAX;

    TreeNode *leftmost = root;
    while (leftmost->left != nullptr)
      leftmost = leftmost->left;

    return leftmost->value;
  }

  /**
   * @brief Get the max node value present in the tree.
   *
   * @param TreeNode*
   * @return int
   */
  int get_max_val(TreeNode *root) {
    if (root == nullptr)
      return INT_MAX;

    TreeNode *rightmost = root;
    while (rightmost->right != nullptr)
      rightmost = rightmost->right;

    return rightmost->value;
  }

  /**
   * @brief Get the height of the tree.
   *
   * @param TreeNode*
   * @return int
   */
  int get_height_1(TreeNode *root) {
    // a node can be NULL if:
    //  1. the tree is empty, return -1 to indicate that.
    //  2. the previous node is a leaf node, return -1 in order to
    //      not take current node into account in the height sum.
    if (root == nullptr)
      return -1;
    // for each node, recursively call get_height_1 for both of its children
    // until a leaf node is reached, from where the stack is unwound and the
    // resulting height is calculated for the current subtree:
    int l = get_height_1(root->left);
    int r = get_height_1(root->right);
    // once we get the heights for the current subtree's children,
    // we compare their height values, get the max height between them and
    // increment the height to account for one more level:
    return std::max(l, r) + 1;
  }

  /**
   * @brief Get the height of the tree. Simplification of get_height_1.
   *
   * @param TreeNode*
   * @return int
   */
  int get_height_2(TreeNode *root) {
    // a node can be NULL if:
    //  1. the tree is empty, return -1 to indicate that.
    //  2. the previous node is a leaf node, return -1 in order to
    //      not take current node into account in the height sum.
    if (root == nullptr)
      return -1;
    // for each node, recursively call get_height_2 for both of its children
    // until a leaf node is reached, from where the stack is unwound and the
    // resulting height is calculated for the current subtree. we then compare
    // their height values, get the max height between them and increment the
    // height to account for one more level:
    return std::max(get_height_2(root->left), get_height_2(root->right)) + 1;
  }

  /**
   * @brief Get the min tree height.
   *
   * @param TreeNode*
   * @return int
   */
  int get_min_height(TreeNode *root) {
    if (root == nullptr)
      return -1;

    int l = get_height_1(root->left);
    int r = get_height_1(root->right);

    return std::min(l, r) + 1;
  }

  /**
   * @brief Get the max tree height. Same as get_height_1 and get_height_2.
   *
   * @param TreeNode*
   * @return int
   */
  int get_max_height(TreeNode *root) {
    return get_height_2(root);
  }

  /**
   * @brief Check whether a node is a leaf node, i.e has no children.
   *
   * @param TreeNode*
   * @return true
   * @return false
   */
  bool is_leaf(TreeNode *root) {
    if (root == nullptr)
      return false;

    return ((root->left == nullptr) && (root->right == nullptr));
  }

  /**
   * @brief Get the total sum of all the leaf nodes.
   *
   * @param TreeNode*
   * @return int
   */
  int get_leaf_sum(TreeNode *root) {
    if (root == nullptr)
      return 0;

    if (is_leaf(root)) {
      return root->value;
    }

    int sum_l = get_leaf_sum(root->left);
    int sum_r = get_leaf_sum(root->right);

    return sum_l + sum_r;
    // return (get_leaf_sum(root->left) + get_leaf_sum(root->right));
  }

  /**
   * @brief Get whether a given value is present in the tree or not.
   *
   * @param TreeNode*
   * @param val
   * @return true
   * @return false
   */
  bool is_present(TreeNode *root, int val) {
    TreeNode *found = get_node_ite(root, val);

    return (found != nullptr);
  }

  /**
   * @brief Get whether the tree is empty or not.
   *
   * @param TreeNode*
   * @return true
   * @return false
   */
  bool is_empty(TreeNode *root) {
    return (root == nullptr);
  }

  /**
   * @brief Check if the tree is balanced (|max_height - min_height| <= 1).
   *
   * @param TreeNode*
   * @return true
   * @return false
   */
  bool is_balanced_1(TreeNode *root) {
    // a tree is balanced if the difference between any of its subtrees
    // is at most 1:
    if (root == nullptr)
      return true;

    return (abs(get_min_height(root) - get_max_height(root)) <= 1);
  }

  /**
   * @brief Check if the tree is balanced (|max_height - min_height| <= 1).
   *
   * @param TreeNode*
   * @return true
   * @return false
   */
  bool is_balanced_2(TreeNode *root) {
    // a tree is balanced if the difference between any of its subtrees
    // is at most 1:
    if (root == nullptr)
      return true;

    int balance_factor = abs(get_min_height(root) - get_max_height(root));

    return (balance_factor <= 1);
  }

  /**
   * @brief Method [1/2] for checking if tree follows the BST properties, i.e left < root < right.
   *
   * @param TreeNode*
   * @return true
   * @return false
   */
  bool is_bst(TreeNode *root) {
    return is_bst_helper(root, INT_MIN, INT_MAX);
  }
  /**
   * @brief Method [2/2] for checking if tree follows the BST properties, i.e left < root < right.
   *
   * @param TreeNode*
   * @return true
   * @return false
   */
  bool is_bst_helper(TreeNode *root, int min, int max) {
    if (root == nullptr)
      return true;

    if ((root->value <= min) || (root->value >= max))
      return false;

    bool l_subtree_ok = is_bst_helper(root->left, min, root->value);
    bool r_subtree_ok = is_bst_helper(root->right, root->value, max);

    return (l_subtree_ok && r_subtree_ok);
  }

  /**
   * @brief In-order traversal: left subtree -> root -> right subtree
   *
   * @param TreeNode*
   */
  void in_order_traversal(TreeNode *root) {
    if (root != nullptr) {
      in_order_traversal(root->left);
      std::cout << root->value << "   ";
      in_order_traversal(root->right);
    }
  }

  /**
   * @brief Pre-order traversal: root -> left subtree -> right subtree
   *
   * @param TreeNode*
   */
  void pre_order_traversal(TreeNode *root) {
    if (root != nullptr) {
      std::cout << root->value << "   ";
      in_order_traversal(root->left);
      in_order_traversal(root->right);
    }
  }

  /**
   * @brief Post-order traversal: left subtree -> right subtree -> root
   *
   * @param TreeNode*
   */
  void post_order_traversal(TreeNode *root) {
    if (root != nullptr) {
      in_order_traversal(root->left);
      in_order_traversal(root->right);
      std::cout << root->value << "   ";
    }
  }

  /**
   * @brief Level-order traversal: root level -> 1st children level -> 2nd children level ..
   *
   * @param TreeNode*
   */
  void level_order_traversal(TreeNode *root) {
    if (root != nullptr) {
      std::queue<TreeNode *> q;
      q.push(root);

      while (!q.empty()) {
        TreeNode *cur_node = q.front();
        q.pop();

        std::cout << cur_node->value << "   ";

        if (cur_node->left != nullptr)
          q.push(cur_node->left);

        if (cur_node->right != nullptr)
          q.push(cur_node->right);
      }
    }
  }

  /**
   * @brief Method for serializing (tree-->string) the tree.
   *
   * @param TreeNode*
   * @return std::string
   */
  std::string serialize_bst(TreeNode *root) {
    // IMPORTANT: For regular binary trees, we cannot use in-order traversal
    // to serialize and deserialize a binary tree because the in-order
    // sequence may not be unique.

    // if we've reached a NULL node, store the MARKER in its place to indicate that:
    if (root == nullptr) {
      std::string s = std::to_string(MARKER) + ' ';
      return s;
    }

    // store current node value and recur for its children:
    std::string serialized_tree = (std::to_string(root->value) + " " + serialize_bst(root->left) + serialize_bst(root->right));

    return serialized_tree;
  }

  /**
   * @brief Method [1/2] for deserializing (string-->tree) a string.
   *
   * @param std::string
   * @return TreeNode*
   */
  TreeNode *deserialize_bst(std::string bst_str) {
    std::stringstream ss{bst_str};

    TreeNode *root;

    deserialize_bst_helper(ss, root);

    return root;
  }
  /**
   * @brief Method [2/2] for deserializing (string-->tree) a string.
   *
   * @param std::string
   * @return TreeNode*
   */
  void deserialize_bst_helper(std::stringstream &ss, TreeNode *&root) {
    std::string tk;
    std::getline(ss, tk, ' ');

    int node_value = std::stoi(tk);

    if (node_value != MARKER) {
      root = new TreeNode(node_value);

      deserialize_bst_helper(ss, root->left);
      deserialize_bst_helper(ss, root->right);
    }
  }
};

int main() {
  std::cout << std::boolalpha;

  BinarySearchTree bst;
  TreeNode *root = nullptr;

  std::cout << "...insertion tests: \n";
  root = bst.insert_ite(root, 10);
  root = bst.insert_ite(root, 5);
  root = bst.insert_rec(root, 15);
  root = bst.insert_rec(root, 0);
  root = bst.insert_ite(root, 11);
  root = bst.insert_ite(root, 8);
  root = bst.insert_rec(root, 19);

  std::cout << "level_order_traversal: ";
  bst.level_order_traversal(root);
  std::cout << "\n";
  std::cout << "in_order_traversal: ";
  bst.in_order_traversal(root);
  std::cout << "\n\n";

  std::cout << "...deletion tests: \n";
  root = bst.remove(root, 8); // node has no children
  std::cout << "level_order_traversal: ";
  bst.level_order_traversal(root);
  std::cout << "\n";
  std::cout << "in_order_traversal: ";
  bst.in_order_traversal(root);
  std::cout << "\n";

  root = bst.remove(root, 5); // node has one children
  std::cout << "level_order_traversal: ";
  bst.level_order_traversal(root);
  std::cout << "\n";
  std::cout << "in_order_traversal: ";
  bst.in_order_traversal(root);
  std::cout << "\n";

  root = bst.remove(root, 10); // node has both children
  std::cout << "level_order_traversal: ";
  bst.level_order_traversal(root);
  std::cout << "\n";
  std::cout << "in_order_traversal: ";
  bst.in_order_traversal(root);
  std::cout << "\n\n";

  root = bst.insert_rec(root, -93);
  root = bst.insert_ite(root, 4);
  root = bst.insert_ite(root, 8);
  root = bst.insert_rec(root, 33);
  root = bst.insert_rec(root, 16);
  std::cout << "level_order_traversal: ";
  bst.level_order_traversal(root);
  std::cout << "\n";
  std::cout << "in_order_traversal: ";
  bst.in_order_traversal(root);
  std::cout << "\n\n";

  std::cout << "...node retrival tests: \n";
  TreeNode *node_1 = bst.get_node_ite(root, 19);
  std::cout << "node value: " << node_1->value << "\n"
            << "node left child value: " << (node_1->left ? node_1->left->value : INT_MAX) << "\n"
            << "node right child value: " << (node_1->right ? node_1->right->value : INT_MIN) << "\n";
  std::cout << "\n";
  TreeNode *node_2 = bst.get_node_rec(root, 4);
  std::cout << "node value: " << node_2->value << "\n"
            << "node left child value: " << (node_2->left ? node_2->left->value : INT_MAX) << "\n"
            << "node right child value: " << (node_2->right ? node_2->right->value : INT_MIN) << "\n";
  std::cout << "\n\n";

  std::cout << "...min and max retrival tests: \n";
  std::cout << "Min. value in BST: " << bst.get_min_val(root) << "\n";
  std::cout << "Max. value in BST: " << bst.get_max_val(root) << "\n";
  std::cout << "\n\n";

  std::cout << "...tree height retrival tests: \n";
  std::cout << "Tree height (v1): " << bst.get_height_1(root) << "\n";
  std::cout << "Tree height (v2): " << bst.get_height_1(root) << "\n";
  std::cout << "\n\n";

  std::cout << "...min/max height retrival test: \n";
  root = bst.insert_rec(root, 45);
  root = bst.insert_rec(root, 73);
  std::cout << "Min Tree height: " << bst.get_min_height(root) << "\n";
  std::cout << "Max Tree height: " << bst.get_max_height(root) << "\n";
  std::cout << "\n\n";

  std::cout << "level_order_traversal: ";
  bst.level_order_traversal(root);
  std::cout << "\n";
  std::cout << "in_order_traversal: ";
  bst.in_order_traversal(root);
  std::cout << "\n\n";

  std::cout << "...leaf node check: \n";
  TreeNode *node_3 = bst.get_node_rec(root, 73);
  std::cout << "Is leaf node: " << bst.is_leaf(node_3) << "\n";
  std::cout << "\n\n";

  std::cout << "...leaf sum test: \n";
  std::cout << "Leaf sum: " << bst.get_leaf_sum(root) << "\n";
  std::cout << "\n\n";

  std::cout << "...tree balance test:\n";
  std::cout << "Tree is balanced: " << bst.is_balanced_1(root) << "\n";
  std::cout << "Tree is balanced: " << bst.is_balanced_2(root) << "\n";

  root = bst.remove(root, 73);
  std::cout << "Tree is balanced: " << bst.is_balanced_1(root) << "\n";
  std::cout << "Tree is balanced: " << bst.is_balanced_2(root) << "\n";
  std::cout << "\n\n";

  std::cout << "...tree is a bst test:\n";
  root->value = 1000;
  std::cout << "Tree is a BST: " << bst.is_bst(root) << "\n";
  root->value = 13;
  std::cout << "Tree is a BST: " << bst.is_bst(root) << "\n";
  std::cout << "\n\n";

  std::cout << "...tree serialization test:\n";
  std::string tree_serialized = bst.serialize_bst(root);
  std::cout << "Tree serialized: \n\t"
            << tree_serialized
            << "\n";
  std::cout << "\n\n";

  std::cout << "...tree deserialization test:\n";
  TreeNode *new_root = bst.deserialize_bst(tree_serialized);
  std::cout << "Tree de-serialized: \n";
  bst.level_order_traversal(new_root);
  std::cout << "\n\n";

  return 0;
}