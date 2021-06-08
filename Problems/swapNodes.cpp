/******************************************************************************
Problem: Tree - Swap Nodes (HR)
*******************************************************************************/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node
{
public:
  int value;
  int level;
  Node *left;
  Node *right;
  Node(int nodeVal, int nodeLvl)
  {
    value = nodeVal;
    level = nodeLvl;
  }
};

class Tree
{
public:
  Node *buildTree(const vector<vector<int>> &indexes, int &lvl)
  {
    Node *root = new Node(1, 1);

    queue<Node *> nodeIndexes;
    nodeIndexes.push(root);

    Node *current = nullptr;

    for (size_t i{0}; i < indexes.size(); i++)
    {
      current = nodeIndexes.front(); // get first element in the queue
      nodeIndexes.pop();             // and remove it from queue

      if (current->value != -1)
      {
        int leftChild = indexes.at(i).at(0);
        int rightChild = indexes.at(i).at(1);

        lvl = current->level + 1; // children level = parent level + 1

        // check for null (value = -1) nodes:
        current->left = ((leftChild != -1) ? new Node(leftChild, lvl) : new Node(-1, lvl));
        current->right = ((rightChild != -1) ? new Node(rightChild, lvl) : new Node(-1, lvl));

        // push children to the queue:
        nodeIndexes.push(current->left);
        nodeIndexes.push(current->right);
      }
      else
      { // -1 = null nodes, skip them to avoid assigning children to a null node.
        i--;
      }
    }
    return root;
  }

  void inOrder(Node *root, vector<int> &res)
  { // left subtree -> root -> right subtree
    if (root->value != -1)
    {
      inOrder(root->left, res);
      res.push_back(root->value);
      inOrder(root->right, res);
    }
  }

  Node *swapHelper(Node *parentNode, int parentLevel)
  {
    if (parentNode->value == -1)
      return parentNode;

    // if we are at the correct tree level, swap nodes:
    if (parentNode->level == parentLevel)
    {
      Node *temp = parentNode->left;
      parentNode->left = parentNode->right;
      parentNode->right = temp;
    }

    // if not, keep descending through the tree:
    swapHelper(parentNode->left, parentLevel);
    swapHelper(parentNode->right, parentLevel);

    return parentNode;
  }
};

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries)
{
  Tree t;
  Node *root = nullptr;
  int lvl = 0;

  vector<vector<int>> solution;

  // build tree:
  root = t.buildTree(indexes, lvl);

  for (size_t i{0}; i < queries.size(); i++)
  {
    int k = queries.at(i);
    for (size_t j{1}; j * k < lvl; j++)
    {
      // swap nodes at k, 2k, 3k, ...:
      root = t.swapHelper(root, j * k);
    }
    // perform in-order traversal and push order to the solution array:
    vector<int> res;
    t.inOrder(root, res);
    solution.push_back(res);
  }

  return solution;
}

int main()
{
  vector<vector<int>> id{
      {2, 3}, {4, -1}, {5, -1}, {6, -1}, {7, 8}, {-1, 9}, {-1, -1}, {10, 11}, {-1, -1}, {-1, -1}, {-1, -1}};
  vector<int> qr{2, 4};
  vector<vector<int>> res;

  res = swapNodes(id, qr);
  cout << res.size() << "\n";

  for (size_t i{0}; i < res.size(); i++)
  {
    for (size_t j{0}; j < res[i].size(); j++)
    {
      std::cout << res[i][j] << " ";
    }
    std::cout << "\n";
  }

  return 0;
}
