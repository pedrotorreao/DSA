/*********************************************************************************************/
/* Problem: Redundant Connection (LC) ********/
/*********************************************************************************************/
/*
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
    n == edges.length
    3 <= n <= 1000
    edges[i].length == 2
    1 <= ai < bi <= edges.length
    ai != bi
    There are no repeated edges.
    The given graph is connected.

--Reasoning: See comments below.

--Time complexity: 
  O(N * α(N)), where N is number of vertices in the graph. Using both path compression and union by 
  size ensures that the amortized time per UnionFind operation is only α(n), which is optimal, 
  where α(n) is the inverse Ackermann function. This function has a value α(n) < 5 for any value of 
  n that can be written in this physical universe, so the disjoint-set operations take place in 
  essentially constant time.

--Space complexity: O(N), where N is the number of vertices.

*/

#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <vector>

void displayVec(const std::vector<int> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "   ";
  }
  std::cout << "\n";
}

class UnionFind {
private:
  std::vector<int> parent;
  std::vector<int> size;

public:
  int find(int set) {
    if (set == parent.at(set))
      return set;
    // path compression:
    return parent.at(set) = find(parent.at(set));
  }

  int unite(int set_1, int set_2) {
    int parent_1 = find(set_1);
    int parent_2 = find(set_2);

    if (parent_1 == parent_2)
      return false; // set_1 and set_2 belong to the same set already

    // merge set w/ lower rank/size to the one w/ higher rank:
    if (size.at(parent_1) > size.at(parent_2)) {
      parent.at(parent_2) = parent_1;
      size.at(parent_1) += size.at(parent_2);
    } else {
      parent.at(parent_1) = parent_2;
      size.at(parent_2) += size.at(parent_1);
    }
    return true;
  }
  // constructor: also make_set()
  UnionFind(int n) {
    parent.resize(n + 1);
    size.resize(n + 1);

    for (int i{0}; i < n; ++i) {
      parent.at(i) = i;
      size.at(i) = 1;
    }
  }
};

std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges) {
  int n = edges.size();

  UnionFind ds(n);

  for (const auto &edge : edges) {
    // union() will be successful if vertices do not already belong to the same
    // set; otherwise, vertices already belong to the same set and current edge
    // is not needed:
    bool union_done = ds.unite(edge.at(0), edge.at(1));
    if (!union_done)
      return {edge.at(0), edge.at(1)};
  }
  return std::vector<int>();
}

int main() {
  std::vector<std::vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};

  std::vector<int> res = findRedundantConnection(edges);

  displayVec(res);

  return 0;
}
/*
------------------------------------ SOLUTIONS AND ANALYSIS FROM LC -------------------------------------
#1:
Idea:
    A valid tree is an undirected graph which has exactly N-1 edges to connect N vertices in the tree.
    Since the given tree has a redundant edge, so there is N edges in the given input.
    Number of vertices N = len(edges).
    There is a data structure called UnionFind or Disjoint-set which has 2 basic operations:
        --uf.find(u), which outputs a unique id so that two nodes have the same id if and only if they are 
        in the same connected component.
        --uf.union(u, v), which connects the components with id find(u) and find(v) together. If it already 
        connected then return False, else return True.
    Then we iterate edge [u, v] in edges, if u and v is already connected in the UnionFind then we return 
    that redundant edge.

Implementation:
  class UnionFind {
      vector<int> parent, size;
    public:
      UnionFind(int n) {
        parent.resize(n); size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i; size[i] = 1;
        }
      }
      int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]); // Path compression
      }
      bool Union(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false; // Return False if u and v are already union
        if (size[pu] > size[pv]) { // Union by larger size
            size[pu] += size[pv];
            parent[pv] = pu;
        } else {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return true;
      }
  };

  class Solution {
    public:
      vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf(n);
        for (auto& e : edges)
            if (!uf.Union(e[0]-1, e[1]-1)) return {e[0], e[1]};
        return {};
      }
  };

Complexity:
  Time: O(N * α(N)), where N is number of vertices in the graph.
  Explanation: Using both path compression and union by size ensures that the amortized time per UnionFind 
  operation is only α(n), which is optimal, where α(n) is the inverse Ackermann function. This function has 
  a value α(n) < 5 for any value of n that can be written in this physical universe, so the disjoint-set 
  operations take place in essentially constant time.
  Reference: https://en.wikipedia.org/wiki/Disjoint-set_data_structure or 
  https://www.slideshare.net/WeiLi73/time-complexity-of-union-find-55858534 for more information.
  Space: O(N)

---------   ---------   ---------   ---------   ---------   ---------   ---------   ---------   ---------   

#2:
This solution uses disjoint set or union-find method. Let's take the following example and see how the 
code works:
  [[1,2], [1,3], [2,3]]

	    1
		 / \
		2 - 3

The parent subset array created is as follows. The 0 slot is not used. By -1 we mean that each vertex stands 
on its own and parents have not been determined yet.
 0   1   2   3  
-1  -1  -1  -1

For edge [1,2] - find(ss, 1) returns 1, find(ss, 2) returns 2. Since both are not equal, we unionize them 
as follows:
 0   1   2   3  
-1  -1   1  -1
It means, "we made the vertex 1 a parent of 2"

For edge [1,3] - find(ss, 1) returns 1, find(ss, 3) returns 3. Since both are not equal, we unionize them 
as follows:
 0   1   2   3  
-1  -1   1   1
It means, "we made the vertex 1 a parent of 3"

Now comes the edge [2, 3] - find(ss, 2) returns 1 and find(ss, 3) returns 1. Both are equal => this edge is 
causing the cycle and it must be the answer.
  class Solution {
    public:
      // Find the subset a vertex belongs to: 
      int find(vector<int> &ss, int x) {
        if (ss[x] == -1) return x;
        return find(ss, ss[x]);
      }

      // Unionize two subsets:
      void _union(vector<int> &ss, int x, int y) {
        int xp = find(ss, x);
        int yp = find(ss, y);
        if (xp != yp) ss[yp] = xp;
      }
    
      // We use disjoint set (or Union-Find) to detect a cycle in an undirected graph:
      vector<int> findRedundantConnection(vector<vector<int> >& e) {
        // Create parent subsets and initialize them to -1 - this means the subsets contain only one item - i.e 
        // ss[i] only contains vertex i:
        vector<int> ss; ss.push_back(-1);
        for (int i = 0; i < e.size(); i++) { ss.push_back(-1); }
        
        // We go through each edge one by one. We find the subset that the vertices of an edge belongs to. If 
        // they belong to two different subsets, we merge them into one set using Union. Now, if both vertices
        // are in the same subset, we got a cycle - we return it.
        for (int i = 0; i < e.size(); ++i) {
          int x = find(ss, e[i][0]), y = find(ss, e[i][1]);            
          if (x == y) return { e[i][0], e[i][1] };
          _union(ss, x, y);
        }
        
        // No redundant edge found:
        return vector<int>();
    }
};
*/
