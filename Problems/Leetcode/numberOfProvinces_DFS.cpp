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
    O(N^2), since we need to traverse all the elements in the NxN matrix.

--Space complexity:
    O(N), due to the space allocated for the visited array.

*/
#include <iostream>
#include <vector>

class Solution {
public:
  int findCircleNum(std::vector<std::vector<int>> &isConnected) {
    const int N = isConnected.size();

    std::vector<bool> visited(N, false);

    int provincesCounter = 0;

    for (int i{0}; i < N; ++i) {
      // if a city has not been visited yet, explore all its connected cities by
      // performing a DFS search:
      if (visited.at(i) == false) {
        visitedConnectedProvinces_DFS(isConnected, visited, i, N);

        // increment the counter to account for the new province found:
        ++provincesCounter;
      }
    }
    return provincesCounter;
  }

  void visitedConnectedProvinces_DFS(std::vector<std::vector<int>> &graph,
                                     std::vector<bool> &visited,
                                     int i, const int N) {
    for (int j{0}; j < N; j++) {
      // if city j is connected to city i and city j has not been visited yet,
      // explore all of its connections, which belong to the same province:
      if (graph.at(i).at(j) == 1 && visited.at(j) == false) {
        visited.at(j) = true;

        visitedConnectedProvinces_DFS(graph, visited, j, N);
      }
    }
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