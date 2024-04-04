/******************************************************************************
Grokking Algorithms - Chapter 6: Breadth Search
*******************************************************************************/
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Friend {
public:
  std::string name;
  bool sellsMangoes;

  Friend() {
    this->name = "Unknown";
    this->sellsMangoes = false;
  }

  Friend(std::string f_name, bool isSeller) : name(f_name), sellsMangoes(isSeller) {}

  ~Friend(){};
};

bool bfs(std::unordered_map<std::string, std::vector<Friend>> &g, Friend src) {
  // queue for storing the nodes to be visited:
  std::queue<Friend> q;
  // set for storing the visited nodes:
  std::unordered_set<std::string> v;
  // hash table for storing the path traversed from the source node to the destination:
  std::unordered_map<std::string, std::string> pathMap;

  // boolean to indicate whether we've found a node which satisfies the condition:
  bool sellerFound{false};

  std::string sellerName = {"none"};

  // add source vertex to the queue and mark it as visited:
  q.push(src);
  v.insert(src.name);

  // iterate while there are still nodes to be traversed:
  while (!q.empty()) {
    // get the current node to be visited from the front of the queue:
    Friend current = q.front();
    q.pop();

    // get all of its neighbors:
    std::vector<Friend> friends = g[current.name];
    // traverse current node' neighbors:
    for (auto &currFriend : friends) {
      // do not process already visited nodes:
      if (!v.count(currFriend.name)) {
        // update path:
        pathMap[currFriend.name] = current.name;
        // add node to the queue so its neighbors may be also visited:
        q.push(currFriend);
        // mark node as visited:
        v.insert(currFriend.name);

        // if current node' neighbor satisfies the condition, we are done:
        if (currFriend.sellsMangoes) {
          std::cout << "-- " << currFriend.name << " sells mangoes.\n";
          // update seller name and set flag to true:
          sellerName = currFriend.name;
          sellerFound = true;
          break;
        }
      }
    }
  }

  // if a selle was found, build the path to it from the source node:
  if (sellerFound) {
    std::string parent = pathMap[sellerName];
    std::vector<std::string> path{};

    path.push_back(sellerName);

    while (parent != src.name) {
      path.push_back(parent);
      parent = pathMap[parent];
    }
    path.push_back(src.name);

    std::cout << "-- Path to seller: ";
    for (auto it = path.rbegin(); it != path.rend(); it++) {
      std::cout << *it << "  ";
    }
    std::cout << "\n";
  }

  return false;
}

int main() {
  std::unordered_map<std::string, std::vector<Friend>> graph;

  Friend source = Friend("Pedro", false);

  graph["Pedro"] = {Friend("Alice", false), Friend("Bob", false), Friend("Claire", false)};
  graph["Bob"] = {Friend("Anuj", false), Friend("Peggy", false)};
  graph["Alice"] = {Friend("Peggy", false)};
  graph["Claire"] = {Friend("Tom", false), Friend("Johnny", false)};
  graph["Anuj"] = {};
  graph["Peggy"] = {};
  graph["Tom"] = {};
  graph["Johnny"] = {Friend("Ames", true)};
  graph["Ames"] = {};

  bool foundAMangoSeller = bfs(graph, source);
}
