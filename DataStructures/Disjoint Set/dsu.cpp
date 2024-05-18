#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

template <typename T>
class DisjointSetUnion {
private:
  std::unordered_map<T, T> parent;
  std::unordered_map<T, int> rank;

public:
  DisjointSetUnion() {}
  ~DisjointSetUnion() = default;

  // ---- Core methods ----:
  bool MakeSet(T x) {
    if (parent.find(x) != parent.end()) {
      // x already exists:
      return false;
    }
    parent[x] = x;
    rank[x] = 1;

    return true;
  }

  bool Find(T x, T &setRepresentative) {
    auto parent_itr = parent.find(x);
    if (parent_itr == parent.end()) {
      // x does not exist:
      return false;
    }

    T u = parent_itr->first;
    T p = parent_itr->second;

    if (u != p) {
      // path compression:
      bool dsuFind = Find(parent[p], parent[u]);
    }
    setRepresentative = parent[u];

    return true;
  }

  bool Union(T x, T y) {
    T xSet, ySet;

    if (!Find(x, xSet) || !Find(y, ySet)) {
      // one of the elements do not exist:
      return false;
    }

    if (xSet == ySet) {
      // same set, no need to perform a union:
      return true;
    }

    if (rank[xSet] < rank[ySet]) // set y has greater rank
      parent[xSet] = ySet;
    else if (rank[xSet] > rank[ySet]) // set x has greater rank
      parent[ySet] = xSet;
    else { // sets have the same rank
      parent[ySet] = xSet;
      rank[xSet] += 1;
    }

    return true;
  }

  // ---- Helper methods ----:
  bool sameSet(T x, T y) {
    T xSet, ySet;

    if (!Find(x, xSet) || !Find(y, ySet)) {
      // one of the elements do not exist:
      return false;
    }

    if (xSet == ySet) {
      // same set, no need to perform a union:
      return true;
    }

    return false;
  }

  int setCount(void) {
    std::unordered_set<T> sets;

    for (auto itr = parent.begin(); itr != parent.end(); ++itr) {
      sets.insert(parent[itr->second]);
    }

    return sets.size();
  }
};

int main() {
  std::cout << std::boolalpha;

  DisjointSetUnion<std::string> dsu;

  dsu.MakeSet("Brazil");
  dsu.MakeSet("Argentina");
  dsu.MakeSet("Uruguay");
  dsu.MakeSet("Chile");
  dsu.MakeSet("France");
  dsu.MakeSet("Italy");

  std::cout << ">> Set count: " << dsu.setCount() << "\n";

  bool unionOK = false;
  unionOK = dsu.Union("Brazil", "Chile");
  unionOK = dsu.Union("Brazil", "Uruguay");
  unionOK = dsu.Union("Chile", "Argentina");

  std::cout << ">> Set count: " << dsu.setCount() << "\n";

  std::cout << ">> Brazil and Argentina are on the same set: " << dsu.sameSet("Brazil", "Argentina") << "\n";
  std::cout << ">> Chile and Uruguay are on the same set: " << dsu.sameSet("Chile", "Uruguay") << "\n";
  std::cout << ">> Chile and Italy are on the same set: " << dsu.sameSet("Chile", "Italy") << "\n";

  std::string setRepresentative = "";
  bool findOK = false;

  findOK = dsu.Find("Chile", setRepresentative);
  std::cout << ">> Chile set' representative: " << setRepresentative << "\n";
  findOK = dsu.Find("Argentina", setRepresentative);
  std::cout << ">> Argentina set' representative: " << setRepresentative << "\n";
  findOK = dsu.Find("Uruguay", setRepresentative);
  std::cout << ">> Uruguay set' representative: " << setRepresentative << "\n";

  unionOK = dsu.Union("France", "Italy");

  std::cout << ">> Set count: " << dsu.setCount() << "\n";
  std::cout << ">> France and Italy are on the same set: " << dsu.sameSet("France", "Italy") << "\n";
  findOK = dsu.Find("Italy", setRepresentative);
  std::cout << ">> Italy set' representative: " << setRepresentative << "\n";
  findOK = dsu.Find("France", setRepresentative);
  std::cout << ">> France set' representative: " << setRepresentative << "\n";
}