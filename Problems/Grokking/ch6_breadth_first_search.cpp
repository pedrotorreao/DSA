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
  std::queue<Friend> q;
  std::unordered_set<std::string> v;
  std::vector<std::string> path;

  q.push(src);
  v.insert(src.name);

  while (!q.empty()) {
    Friend current = q.front();
    q.pop();

    path.push_back(current.name);

    std::vector<Friend> friends = g[current.name];

    for (auto &currFriend : friends) {
      if (!v.count(currFriend.name)) {
        if (currFriend.sellsMangoes) {
          std::cout << "--> " << current.name << " sells mangoes.\n";
          return true;
        }
        q.push(currFriend);
        v.insert(currFriend.name);
      }
    }
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
  graph["Thom"] = {};
  graph["Johnny"] = {Friend("Ames", true)};
  graph["Ames"] = {};

  bool foundAMangoSeller = bfs(graph, source);
}
