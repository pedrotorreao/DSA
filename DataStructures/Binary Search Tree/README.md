## Binary Search Tree - BST

See source code examples [here](/DataStructures/Binary%20Search%20Tree/src/).

### Definition

A tree is a hierarchical data structure composed of nodes in which each node has a `data` property and `references` to the its children. See below an example written in C++ for a binary tree node:

```cpp
class TreeNode {
  public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) : data{val}, left{nullptr}, right{nullptr} {}
};
```

**Properties**

- each tree has a `root` node
- the `root` has no parent node
- `root` node may have zero or more `child` nodes
- each `child` node may have their own children/subtrees
- trees cannot contain cycles

**Terminologies**

See below a few common terms when working with trees:

- _`root`_: entry point to the tree, this node has no parent.
- _`edge`_: link connecting two nodes, `parent` to `child`, usually represented by a reference/pointer.
- _`leaf`_: node which has no children.
- _`sibling`_: children of the same parent node.
- _`ancestor`_: usually the parent node, but it can be any node that comes before in the hierarchical structure.
- _`predecessor`_: immediate previous node in in-order traversal.
- _`sucessor`_: immediate next node in in-order traversa.
- _`depth of a node`_: length (total number of edges) of the path from _`root`_ to the target node.
- _`height of a node`_: length (total number of edges) of the path from the node to the deepest leaf.
- _`depth of a binary tree`_: length (total number of edges) from the `root` node to the most distant (deepest) leaf node.
- _`height of a binary tree`_: largest number of edges from the root to the most distant leaf node. Similar concept to the depth of the tree.

**Tree vs Binary Tree**

A binary tree is a tree in which a node may have up to two children. So, while binary trees are a type of tree, not all trees are binary trees. _(img)_

**Binary Tree vs Binary Search Trees**

A binary search tree is a binary tree in which each node fits a specific ordering property. For each node `n`,

> `n.leftchild.value < n.value < n.rightchild.value`

_(img)_

**Complete Binary Tree**

A binary tree in which all levels are fully filled, except for perhaps the last level which must have all of its nodes inserted as left as possible, i.e. the tree must be filled from left to right. _(img)_

**Full Binary Trees**

Binary tree in which every node other than the leaves has two children. This way, every node must have either both or no children, i.e. there are no nodes with only one child. _(img)_

**Perfect Binary Trees**

Binary trees which are both _full_ and _complete_, so all `leaf` nodes are at the same level, and each level is filled with its maximum number of nodes. _(img)_

### Binary Tree Traversal

To explain the different ways a binary tree can be traversed, let's use the following example:

_(img)_

- **In-order traversal**

For these, the binary tree is traversed in the following order:

> left subtree --> root --> right subtree

Traversal result:

Algorithm:

```cpp
void inOrderTraversal(TreeNode *root){
  if(root != nullptr){
    inOrderTraversal(root->left);
    std::cout << root->value << "  ";
    inOrderTraversal(root->right);
  }
}
```

Note: if the binary tree being traversed is a binary search tree, the nodes will be visited in ascending order.

- **Pre-order taversal**

For these, the binary tree is traversed in the following order:

> root --> left subtree --> right subtree

Traversal result:

Algorithm:

```cpp
void preOrderTraversal(TreeNode *root){
  if(root != nullptr){
    std::cout << root->value << "  ";
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
  }
}
```

Note: in this type of traversal the `root` node is always the first node visited.

- **Post-order traversal**

For these, the binary tree is traversed in the following order:

> left subtree --> right subtree --> root

Traversal result:

Algorithm:

```cpp
void postOrderTraversal(TreeNode *root){
  if(root != nullptr){
    inOrderTraversal(root->left);
    inOrderTraversal(root->right);
    std::cout << root->value << "  ";
  }
}
```

Note: in this type of traversal the `root` node is always the last node visited.

- **Level-order traversal**

For these, the binary tree is traversed in the following order:

> root level --> 1st level children --> 2nd level children ...

Traversal result:

Algorithm:

```cpp
void levelOrderTraversal(TreeNode *root){
  if(root != nullptr){
    std::queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()){
      Node* current = q.front(); q.pop();

      std::cout << current->value << "  ";

      if(current->left != nullptr)
        q.push(current->left);

      if(current->right != nullptr)
        q.push(current->right);
    }
  }
}
```

### Example

...

### Pseudocode

...

### Time complexity

...

### Space complexity

...

### References

...

### [Data Structures & Algorithm - Index](../../../README.md)
