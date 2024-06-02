/***
Problem: LC 547. Number Of Provinces
(https://leetcode.com/problems/number-of-provinces/description/)

--Problem statement:
  There are n cities. Some of them are connected, while some are not. If city a is connected
  directly with city b, and city b is connected directly with city c, then city a is connected
  indirectly with city c.

  A province is a group of directly or indirectly connected cities and no other cities outside
  of the group.

  You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth
  city are directly connected, and isConnected[i][j] = 0 otherwise.

  Return the total number of provinces.

  > Example 1:
    Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
    Output: 2

  > Example 2:
    Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
    Output: 3

--Inputs:
  int[][]: n x n matrix

--Output:
  int: total number of provinces

--Constraints:
    :: 1 <= n <= 200
    :: n == isConnected.length
    :: n == isConnected[i].length
    :: isConnected[i][j] is 1 or 0.
    :: isConnected[i][i] == 1
    :: isConnected[i][j] == isConnected[j][i]

--Time complexity:
    O(N^3) in the worst case, where 'N' is the number of nodes, since the 'Union' and 'Find' operations
    can take O(N) time without optimizations and we perform up to O(N^2) comparisons. However, by optimizing
    the algorithm with path compression and union by rank, the amortized time complexity of each Union-Find
    operation can be reduced to nearly O(1), making the algorithm run in nearly O(N^2) time.

--Space complexity:
    O(N), due to the space allocated for the parent array.

*/
#include <iostream>
#include <vector>

class UnionFind {
  std::vector<int> parent;
  std::vector<int> rank;
  int setCount;

public:
  UnionFind(int n) {
    this->setCount = n; // initially, each node is its own set
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

    // if the union was successful, one existing set was merged to another,
    // so we decrement the number of individual sets:
    --this->setCount;
  }

  int countSets(void) {
    return this->setCount;
  }
};

class Solution {
public:
  int findCircleNum(std::vector<std::vector<int>> &isConnected) {
    const int N = isConnected.size();

    UnionFind uf(N);

    for (int r{0}; r < N; ++r) {
      for (int c{0}; c < N; ++c) {
        // if there is a connection between cities 'r' and 'c', they belong to the
        // same province, so merge them to the same set:
        if (isConnected.at(r).at(c) == 1) {
          uf.Union(r, c);
        }
      }
    }
    return uf.countSets();
  }
};

int main() {
  Solution sol;

  std::vector<std::vector<int>> m;
  int numOfProvinces{0};

  m = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
  numOfProvinces = sol.findCircleNum(m);
  std::cout << ">> Number of provinces: " << numOfProvinces << "\n";

  m = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  numOfProvinces = sol.findCircleNum(m);
  std::cout << ">> Number of provinces: " << numOfProvinces << "\n";

  return 0;
}