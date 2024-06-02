/***
Problem: LC 785. Is Graph Bipartite?
(https://leetcode.com/problems/is-graph-bipartite/description/)

--Problem statement:
  There is an undirected graph with 'n' nodes, where each node is numbered between '0' and 'n - 1'.
  You are given a 2D array graph, where 'graph[u]' is an array of nodes that node 'u' is adjacent to.
  More formally, for each 'v' in 'graph[u]', there is an undirected edge between node 'u' and node 'v'.
  The graph has the following properties:
    - There are no self-edges (graph[u] does not contain 'u').
    - There are no parallel edges (graph[u] does not contain duplicate values).
    - If 'v' is in graph[u], then 'u' is in graph[v] (the graph is undirected).
    - The graph may not be connected, meaning there may be two nodes 'u' and 'v' such that there is no path
    between them.

  A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every
  edge in the graph connects a node in set A and a node in set B.
  Return true if and only if it is bipartite.

  > Example 1:
    Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
    Output: false
    Explanation: There is no way to partition the nodes into two independent sets such that every edge connects
    a node in one and a node in the other.

  > Example 2:
    Input: graph = [[1,3],[0,2],[1,3],[0,2]]
    Output: true
    Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.

--Inputs:
  int[][]: a 2D array graph.

--Output:
  bool: true if and only if it is bipartite.

--Constraints:
    :: 1 <= n <= 200
    :: n == isConnected.length
    :: n == isConnected[i].length
    :: isConnected[i][j] is 1 or 0.
    :: isConnected[i][i] == 1
    :: isConnected[i][j] == isConnected[j][i]

--Reasoning:
    To check if a graph can be bipartitioned, we can use the Union Find (Disjoint Set Union) algorithm. Initially,
    we consider each node as a distinct set, i.e. every node is in its own group. Next, we check each edge in the graph.
    The main aspect here is to determine whether adjacent nodes (i.e, connected by an edge) belong to different sets.
    If they are in the same set, the bipartition condition is not satisfied. Otherwise, for edges connecting nodes in
    separate sets, we merge these sets by performing a union operation, which groups the nodes in a way that allows for
    a possible bipartition. The graph can be considered bipartite if, after evaluating all edges, no adjacent nodes are
    found in the same set.

--Time complexity:
    O(E), where 'E' is the number of edges in the graph, since each edge is processed only once. Also, by optimizing
    the algorithm with path compression and union by rank, the amortized time complexity of each Union-Find
    operation can be reduced to nearly O(1).

--Space complexity:
    O(V), where 'V' is the number of vertices/nodes in the graph, due to the space allocated for the parent array.

*/
#include <iostream>
#include <vector>

class UnionFind {
  std::vector<int> parent;
  std::vector<int> rank;

public:
  UnionFind(int n) {
    this->MakeSet(n);
  }
  ~UnionFind() = default;

  void MakeSet(int n) {
    this->parent.resize(n + 1);
    this->rank.resize(n + 1);

    for (int i{0}; i < n; i++) {
      // initially, each node is its own parent:
      this->parent.at(i) = i;
      // all nodes begin with the same rank 1:
      this->rank.at(i) = 1;
    }
  }

  // retrieve the representative of the set to which 'x' belongs to:
  int Find(int x) {
    if (parent.at(x) != x) {
      // optimization - path compression:
      parent.at(x) = this->Find(parent.at(x));
    }
    return parent.at(x);
  }

  // join the sets containing elements 'x' and 'y':
  void Union(int x, int y) {
    int xSet = this->Find(x); // set representative of 'x'
    int ySet = this->Find(y); // set representative of 'y'

    // if the set representatives are the same, 'x' and 'y' are already
    // part of the same set, so this edge is a redundant connection:
    if (xSet == ySet) {
      return;
    }

    // optimization - union by rank:
    if (rank.at(xSet) < rank.at(ySet)) {
      parent.at(xSet) = ySet;
    } else if (rank.at(xSet) > rank.at(ySet)) {
      parent.at(ySet) = xSet;
    } else {
      parent.at(ySet) = xSet;
      rank.at(xSet) += 1;
    }
  }
};

class Solution {
public:
  bool isBipartite(const std::vector<std::vector<int>> &graph) {
    const int N = graph.size();

    UnionFind uf(N);

    for (int i{0}; i < N; i++) {
      if (graph.at(i).size() == 0)
        continue;

      std::vector<int> adjNodes = graph.at(i);

      for (int j{0}; j < adjNodes.size(); j++) {
        if (uf.Find(i) == uf.Find(adjNodes.at(j)))
          return false;

        uf.Union(graph.at(i).at(0), graph.at(i).at(j));
      }
    }

    return true;
  }
};

int main() {
  std::cout << std::boolalpha;

  Solution sol;

  std::vector<std::vector<int>> m;
  bool isBipartite{false};

  m = {{1, 2, 3}, {0, 2}, {0, 1, 3}, {0, 2}};
  isBipartite = sol.isBipartite(m);
  std::cout << ">> Graph is bipartite: " << isBipartite << "\n";

  m = {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
  isBipartite = sol.isBipartite(m);
  std::cout << ">> Graph is bipartite: " << isBipartite << "\n";

  return 0;
}