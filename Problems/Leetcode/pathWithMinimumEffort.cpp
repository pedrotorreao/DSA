/***
Problem: LC 1631. Path With Minimum Effort
(https://leetcode.com/problems/path-with-minimum-effort/description/)

--Problem statement:
You are a hiker preparing for an upcoming hike. You are given 'heights', a 2D array of size rows x columns,
where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0),
and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down,
left, or right, and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.

Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

  > Example 1:
      Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
      Output: 2
      Explanation:
        The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
        This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

  > Example 2:
      Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
      Output: 1
      Explanation:
        The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than
        route [1,3,5,3,5].

  > Example 3:
      Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
      Output: 0
      Explanation: This route does not require any effort.

--Inputs:
    int[][]: a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col).

--Output:
    int: minimum effort required to travel from the top-left cell to the bottom-right cell.

--Constraints:
    :: rows == heights.length
    :: columns == heights[i].length
    :: 1 <= rows, columns <= 100
    :: 1 <= heights[i][j] <= 10^6

--Reasoning: This approach is based on the Dijkstra's algorithm. See comments below.

--Time complexity:
    O(E*log(V)), where E is the number of edges and V is the number of vertices. In this case, we can assume E ≈ V ≈ R*C.

--Space complexity:
    O(R*C), where R and C are the number of rows and columns respectively. This is due to the 'efforts' 2D vector.

*/
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

struct Edge {
  int x, y, effort;
  Edge(int x, int y, int diff) : x(x), y(y), effort(diff) {}
};

struct comp_func {
  bool operator()(const Edge &a, const Edge &b) {
    return a.effort > b.effort;
  }
};

class Solution {
  const std::vector<int> dx{-1, 0, 1, 0}; // {x-1, x, x+1, x}
  const std::vector<int> dy{0, -1, 0, 1}; // {y, y-1, y, y+1}
public:
  int minimumEffortPath(std::vector<std::vector<int>> &heights) {
    const int R = heights.size(), // rows
        C = heights.at(0).size(); // columns

    // priority queue - min heap:
    std::priority_queue<Edge, std::vector<Edge>, comp_func> pq;
    // matrix for storing the min cost to get to each cel (row, col):
    std::vector<std::vector<int>> efforts(R, std::vector<int>(C, std::numeric_limits<int>::max()));
    // set the effort to top-right cell to 0, since this is our starting point:
    efforts.at(0).at(0) = 0;
    // push starting node to our priority queue:
    pq.push(Edge(0, 0, 0));

    while (!pq.empty()) {
      Edge current = pq.top();
      pq.pop();

      // skip if a better effort to the current node has already been found:
      if (current.effort > efforts.at(current.x).at(current.y))
        continue;

      // if we got to the bottom-left cell, we are done traveling and current.effort holds our result:
      if (current.x == R - 1 && current.y == C - 1)
        return current.effort;

      for (int i{0}; i < 4; i++) {
        // explore up/down/left/right from current cell:
        int newX = current.x + dx.at(i),
            newY = current.y + dy.at(i);

        // skip if new coordinates are out of bounds:
        if (newX < 0 || newX >= R || newY < 0 || newY >= C)
          continue;

        // calculate the effort to get from [current.x, current.y] to [newX, newY], newEffort holds the maximum
        // absolute difference between two consecutive nodes up until [newX, newY]:
        int newEffort = std::max(current.effort, std::abs(heights.at(newX).at(newY) - heights.at(current.x).at(current.y)));

        // relaxation: in case we've found a path to get to [newX, newY] with a smaller effort, update its efforts[newX][newY]
        // value and add the updated Edge(newX, newY, newEffort) to the priority queue:
        if (newEffort < efforts.at(newX).at(newY)) {
          efforts.at(newX).at(newY) = newEffort;
          pq.push(Edge(newX, newY, newEffort));
        }
      }
    }
    return 0;
  }
};

int main() {
  Solution sol;

  std::vector<std::vector<int>> heights;
  int minEffort{0};

  heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
  minEffort = sol.minimumEffortPath(heights);
  std::cout << ">> Minimum effort: " << minEffort << "\n";

  heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
  minEffort = sol.minimumEffortPath(heights);
  std::cout << ">> Minimum effort: " << minEffort << "\n";

  heights = {{1, 2, 1, 1, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 2, 1, 2, 1}, {1, 1, 1, 2, 1}};
  minEffort = sol.minimumEffortPath(heights);
  std::cout << ">> Minimum effort: " << minEffort << "\n";

  return 0;
}