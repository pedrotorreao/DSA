/*********************************************************************************************/
/* Problem: LC 133. Clone Graph ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a reference of a node in a connected undirected graph. Return a deep copy (clone) of
  the graph. Each node in the graph contains a value (int) and a list (List[Node]) of its
  neighbors.

    class Node {
        public int val;
        public List<Node> neighbors;
    }

  Test case format: For simplicity, each node's value is the same as the node's index (1-indexed).
  For example, the first node with val == 1, the second node with val == 2, and so on. The graph
  is represented in the test case using an adjacency list. An adjacency list is a collection of
  unordered lists used to represent a finite graph. Each list describes the set of neighbors of
  a node in the graph.

  The given node will always be the first node with val = 1. You must return the copy of the given
  node as a reference to the cloned graph.

  > Example 1:
    Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
    Output: [[2,4],[1,3],[2,4],[1,3]]
    Explanation: There are 4 nodes in the graph.
      1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
      2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
      3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
      4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).

  > Example 2:
    Input: adjList = [[]]
    Output: [[]]
    Explanation:
      Note that the input contains one empty list. The graph consists of only one node with val = 1
      and it does not have any neighbors.

  > Example 3:
    Input: adjList = []
    Output: []
    Explanation: This an empty graph, it does not have any nodes.

--Inputs:
  -Node*: source node of the original graph.

--Output:
  -Node*: source node of the deep copied graph.

--Constraints:
    :: The number of nodes in the graph is in the range [0, 100].
    :: 1 <= Node.val <= 100
    :: Node.val is unique for each node.
    :: There are no repeated edges and no self-loops in the graph.
    :: The Graph is connected and all nodes can be visited starting from the given node.

--Reasoning: See comments below.

--Time complexity: O(V), if I'm not mistaken, where V is the number of nodes in the graph.

--Space complexity: O(V), for storing the copies of the nodes.

*/

/******************************************************************************
LC 133. Clone Graph
*******************************************************************************/
#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
void displayVec(const std::vector<T> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}

class Node {
public:
  int val;
  std::vector<Node *> neighbors;
  Node() {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val) {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

Node *cloneGraph(Node *node) {
  // graph does not exist - return null:
  if (node == nullptr)
    return nullptr;
  // graph is empty - return an empty graph:
  if (node->val == 0)
    return new Node();
  // graph has only one node - return a copy of it:
  if (node->neighbors.size() == 0)
    return new Node(node->val);

  // stack for storing nodes that we'll be processing later:
  std::stack<Node *> st;
  // hash set to track whether a node has been visited or not:
  std::unordered_set<Node *> visited;
  // hash map to create copies for each node traversed:
  std::unordered_map<Node *, Node *> hm;

  // src - node from which we'll begin the taversal/copy:
  Node *src = node;

  st.push(src);        // add first node to the stack
  visited.insert(src); // and mark it as visited

  // - 1st loop: creates a copy of each node
  // iterate while there are nodes to be processed in the stack:
  while (!st.empty()) {
    Node *curr = st.top();
    st.pop();
    // map current node to a copy of it:
    hm[curr] = new Node(curr->val);
    // iterate over current node' neighbors and add them to the
    // stack if they have not been visited before:
    for (auto &node : (curr->neighbors)) {
      if (!visited.count(node)) {
        st.push(node);
        visited.insert(node);
      }
    }
  }

  // clear hash set for the 2nd loop:
  visited.clear();

  st.push(src);        // add first node to the stack
  visited.insert(src); // and mark it as visited

  // - 2nd loop: responsible for copying the neighbors
  // iterate while there are nodes to be processed in the stack:
  while (!st.empty()) {
    Node *curr = st.top();
    st.pop();
    // new_curr is the copy created previously of current node:
    Node *new_curr = hm[curr];
    // now we only mark a node as visited when we have processed all of its neighbors
    // and added its copies to new_curr neighbors array:
    if (!visited.count(new_curr)) {
      // iterate over the current node' neighbors and push their copies to new_curr'
      // neighbors vector:
      for (auto &node : (curr->neighbors)) {
        st.push(node);
        visited.insert(node);

        (new_curr->neighbors).push_back(hm[node]);
      }
      // mark new_curr as visited so we don't visit the same node more than once:
      visited.insert(new_curr);
    }
  }

  // return the copy of the src node:
  return hm[src];
}

void dfs(Node *src);

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);

  n1->neighbors.push_back(n2);
  n1->neighbors.push_back(n4);
  n2->neighbors.push_back(n1);
  n2->neighbors.push_back(n3);
  n3->neighbors.push_back(n2);
  n3->neighbors.push_back(n4);
  n4->neighbors.push_back(n1);
  n4->neighbors.push_back(n3);

  Node *clone = cloneGraph(n1);

  dfs(clone);

  return 0;
}

void dfs(Node *src) {
  std::stack<Node *> q;
  std::unordered_set<Node *> visited;
  std::vector<int> traversal;

  Node *source = src;

  q.push(source);
  visited.insert(source);

  while (!q.empty()) {
    Node *current_vertex = q.top();
    q.pop();

    traversal.push_back(current_vertex->val);

    for (auto &node : current_vertex->neighbors) {
      if (!visited.count(node)) {
        q.push(node);
        visited.insert(node);
      }
    }
  }
  displayVec(traversal);
}