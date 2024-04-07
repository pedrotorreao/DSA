/******************************************************************************
Grokking Algorithms - Chapter 7: Dijkstra
*******************************************************************************/
#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::pair<std::string, int> vw_pair;

struct comp_func {
  bool operator()(const vw_pair &a, const vw_pair &b) {
    return a.second > b.second;
  }
};

bool dijkstra(std::unordered_map<std::string, std::vector<vw_pair>> &g, std::string source, std::string destination) {
  // set for storing the visited nodes:
  std::unordered_set<std::string> visited;
  // hash table for storing the path traversed from source -> destination:
  std::unordered_map<std::string, std::string> parent;
  // hash table for storing the costs:
  std::unordered_map<std::string, int> cost;
  // min heap for keep the nodes with smaller weights first:
  std::priority_queue<vw_pair, std::vector<vw_pair>, comp_func> pq;
  // flag to indicate whether a path between source and destination exists:
  bool pathFound{false};

  // set the source' parent since there's no node before it:
  parent[source] = "none";
  // initialize costs to "infinite":
  for (auto it = g.begin(); it != g.end(); it++) {
    // "it" is a pointer to an address containing a pair <node, weigth>:
    std::string node = (*it).first;

    cost[node] = std::numeric_limits<int>::max();
  }

  // mark source node as visited:
  visited.insert(source);
  // since we begin from source, its cost is zero:
  cost[source] = 0;
  // add source node to the min heap:
  pq.push(std::make_pair(source, cost[source]));

  // iterate while there are still nodes to be traversed:
  while (!pq.empty()) {
    std::string current_vertex = (pq.top()).first; // node
    int current_weigth = (pq.top()).second;        // weight/cost
    // remove element since it has been traversed
    pq.pop();
    // mark it as visisted:
    visited.insert(current_vertex);
    // get all of its neighbors:
    auto neighbors = g[current_vertex];
    // visit current node' neighbors:
    for (const auto &next : neighbors) {
      std::string v_to = next.first;
      int w_to = next.second;
      // do not process already visited nodes:
      if (!visited.count(v_to)) {
        // if a best cost to a neighbor was found, update its cost and
        // its parent:
        if (cost[current_vertex] + w_to < cost[v_to]) {
          cost[v_to] = cost[current_vertex] + w_to;

          parent[v_to] = current_vertex;

          // add updated pair to the min heap:
          pq.push(std::make_pair(v_to, cost[v_to]));
        }
      }
    }

    if (current_vertex == destination)
      pathFound = true;
  }

  // build the path source->destination:
  if (pathFound) {
    std::vector<std::string> path;
    std::string curr_parent{destination};

    while (curr_parent != "none") {
      path.push_back(curr_parent);

      curr_parent = parent[curr_parent];
    }

    std::cout << "-- Best path to seller costs " << cost[destination] << ": ";
    for (auto it = path.rbegin(); it != path.rend(); it++) {
      std::cout << *it << "  ";
    }
    std::cout << "\n";

    return true;
  }

  return false;
}

int main() {
  std::unordered_map<std::string, std::vector<vw_pair>> graph{
      {"book", {{"lp", 5}, {"poster", 0}}},
      {"lp", {{"bass", 15}, {"drums", 20}}},
      {"poster", {{"bass", 30}, {"drums", 35}}},
      {"bass", {{"piano", 20}}},
      {"drums", {{"piano", 10}}},
      {"piano", {{}}}};

  std::string src{"book"}, dest{"piano"};

  bool pathFound = dijkstra(graph, src, dest);
}