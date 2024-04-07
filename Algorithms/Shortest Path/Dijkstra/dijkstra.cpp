#include <algorithm>
#include <iostream>
#include <limits>
#include <numeric>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

typedef std::pair<int, int> vwpair;

struct myComp {
  constexpr bool operator()(
      std::pair<int, int> const &a,
      std::pair<int, int> const &b)
      const noexcept {
    return a.second > b.second;
  }
};

template <typename T>
void displayVec(const std::vector<T> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}

void buildPath(std::vector<int> &predecessor, int source, int end, std::vector<int> &path) {
  for (int i{end}; i != -1; i = predecessor.at(i)) {
    path.push_back(i);
  }

  std::reverse(path.begin(), path.end());
}

void dijkstra(std::unordered_map<int, std::vector<std::pair<int, int>>> &graph, int source, int end) {
  std::vector<bool> visited(graph.size() + 10, false);
  std::vector<int> prev(graph.size() + 10, -1);
  std::vector<int> dist(graph.size() + 10, std::numeric_limits<int>::max());

  std::priority_queue<vwpair, std::vector<vwpair>, myComp> pq;

  pq.push(std::make_pair(source, dist.at(source)));

  visited.at(source) = true;
  dist.at(source) = 0;

  while (!pq.empty()) {
    int curr_vertex = (pq.top()).first;
    int curr_weight = (pq.top()).second;
    pq.pop();

    visited.at(curr_vertex) = true;

    auto neighbors = graph.at(curr_vertex);

    for (const auto &node : neighbors) {
      int v_to = node.first;
      int w_to = node.second;

      if (!visited[v_to]) {
        if (dist.at(curr_vertex) + w_to < dist.at(v_to)) {
          dist.at(v_to) = dist.at(curr_vertex) + w_to;

          prev.at(v_to) = curr_vertex;
          pq.push(std::make_pair(v_to, dist.at(v_to)));
        }
      }
    }
  }

  std::vector<int> path;

  buildPath(prev, source, end, path);

  std::cout << "Shortest path from " << source << " to " << end << " costs " << dist.at(end) << ": ";
  displayVec(path);
}

int main() {
  std::unordered_map<int, std::vector<vwpair>> g_1{
      {1, {{2, 50}, {3, 45}, {4, 10}}},
      {2, {{3, 10}, {4, 15}}},
      {3, {{5, 30}}},
      {4, {{1, 10}, {5, 15}}},
      {5, {{2, 20}, {3, 30}}},
      {6, {{5, 3}}}};
  // g_1[1] = {{2,50},{3,45},{4,10}};
  // g_1[2] = {{3,10},{4,15}};
  // g_1[3] = {{5,30}};
  // g_1[4] = {{1,10},{5,15}};
  // g_1[5] = {{2,20},{3,30}};
  // g_1[6] = {{5,3}};
  // Should output 0 -> 1 -> 3 -> 5 -> 2 -> 4
  dijkstra(g_1, 1, 5);
  dijkstra(g_1, 1, 6);
  dijkstra(g_1, 1, 3);

  return 0;
}

/*
let adjList1 = {
  0: ["1", "3", "5"],
  1: ["0", "2", "4"],
  2: ["1"],
  3: ["0", "4", "5"],
  4: ["1", "3"],
  5: ["0", "3"],
};
bfs(adjList1);

// (2): Should output 0 -> 11 -> 2 -> 4 -> 9 -> 7 -> 19 -> 3 -> 1
let adjList2 = {
  0: ["11", "2", "4"],
  1: ["3", "7", "19"],
  2: ["0", "4", "7", "19"],
  3: ["9", "7", "1"],
  4: ["0", "2"],
  7: ["2", "11", "9", "1", "19"],
  9: ["11", "3", "7"],
  11: ["0", "9", "7"],
  19: ["2", "7", "1"],
};
*/