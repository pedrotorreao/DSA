/***
Problem: LC 684. Redundant Connection - Alternative approach
(https://leetcode.com/problems/redundant-connection/description/)

--Problem statement:
  In this problem, a tree is an undirected graph that is connected and has no cycles. You are
  given a graph that started as a tree with n nodes labeled from 1 to n, with one additional
  edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge
  that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi]
  indicates that there is an edge between nodes ai and bi in the graph.
  Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there
  are multiple answers, return the answer that occurs last in the input.
  > Example:
      Input: edges = [[1,2],[1,3],[2,3]]
      Output: [2,3]
  > Example:
      Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
      Output: [1,4]

--Inputs:
  -vector<int>: array 'edges' of length n where edges[i] = [ai, bi]

--Outputs:
  -vector<int>: array representing the edge that should be removed.

--Constraints:
    :: n == edges.length
    :: 3 <= n <= 1000
    :: edges[i].length == 2
    :: 1 <= ai < bi <= edges.length
    :: ai != bi
    :: There are no repeated edges.
    :: The given graph is connected.

--Reasoning:
  The Union-Find algorithm is very effective for cycle detection in graphs. Initially, each node is considered
  as its own individual/disjoint set. As we go through the list of edges of the graph, we use the Union-Find approach to
  determine if the nodes connected by the current edge already belong to the same set. If they do, it indicates the presence
  of a cycle, and this edge is the redundant one. Otherwise, unite these two sets, meaning connect the nodes without forming a
  cycle.
    >> We focus on progressively merging nodes into larger sets while waiting for the edge that connects nodes already in
    the same set.

  This approach is efficient because the "Union" and "Find" operations can be optimized to almost constant time complexity
  with path compression and union by rank.

--Time complexity:
  O(N * α(N)), where N is number of vertices in the graph. Using both path compression and union by
  size ensures that the amortized time per UnionFind operation is only α(n), which is optimal,
  where α(n) is the inverse Ackermann function. This function has a value α(n) < 5 for any value of
  n that can be written in this physical universe, so the disjoint-set operations take place in
  essentially constant time.

--Space complexity: O(N), where N is the number of vertices.

*/

#include <iostream>
#include <vector>

void displayVec(const std::vector<int> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "   ";
  }
  std::cout << "\n";
}

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
  void Union(int x, int y, bool &isRedundant) {
    int xSet = this->Find(x); // set representative of 'x'
    int ySet = this->Find(y); // set representative of 'y'

    // if the set representatives are the same, 'x' and 'y' are already
    // part of the same set, so this edge is a redundant connection:
    if (xSet == ySet) {
      isRedundant = true;
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

    isRedundant = false;
    return;
  }
};

class Solution {
public:
  static std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
    const int N = edges.size();

    UnionFind uf(N);

    bool isRedundant{false};
    std::vector<int> redundantEdge;

    for (int i{0}; i < N; i++) {
      uf.Union(edges[i][0], edges[i][1], isRedundant);
      if (isRedundant)
        redundantEdge = edges[i];
    }

    return redundantEdge;
  }
};

int main() {
  std::vector<std::vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};

  std::vector<int> res = Solution::findRedundantConnection(edges);

  displayVec(res);

  return 0;
}
