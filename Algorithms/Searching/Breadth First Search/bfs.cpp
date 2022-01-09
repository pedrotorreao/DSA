#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

template <typename T>
void displayVec(const std::vector<T> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}

void bfs(std::unordered_map<int, std::vector<int>> &graph)
{
  std::vector<bool> visited(graph.size(), false);
  std::vector<int> traversal;
  std::queue<int> q;

  auto g_it = graph.begin();
  int source = g_it->first;

  q.push(source);
  visited[source] = true;

  while (!q.empty())
  {
    int current_vertex = q.front();
    q.pop();

    std::vector<int> neighbors = graph.at(current_vertex);

    traversal.push_back(current_vertex);

    for (const auto &node : neighbors)
    {
      if (!visited[node])
      {
        q.push(node);
        visited[node] = true;
      }
    }
  }
  displayVec(traversal);
}

int main()
{
  std::unordered_map<int, std::vector<int>> g_1{{0, {1, 3, 5}},
                                                {1, {0, 2, 4}},
                                                {2, {1}},
                                                {3, {0, 4, 5}},
                                                {4, {1, 3}},
                                                {5, {0, 3}}};
  // Should output 0 -> 1 -> 3 -> 5 -> 2 -> 4
  bfs(g_1);

  std::unordered_map<int, std::vector<int>> g_2{{0, {11, 2, 4}},
                                                {1, {3, 7, 19}},
                                                {2, {0, 4, 7, 19}},
                                                {3, {9, 7, 1}},
                                                {4, {0, 2}},
                                                {7, {2, 11, 9, 1, 19}},
                                                {9, {11, 3, 7}},
                                                {11, {0, 9, 7}},
                                                {19, {2, 7, 1}}};
  // Should output 0 -> 11 -> 2 -> 4 -> 9 -> 7 -> 19 -> 3 -> 1
  bfs(g_2);

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