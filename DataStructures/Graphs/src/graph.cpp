/***************************************************************************/
/* Graph *******/
/***************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <stdexcept>
#include <queue>
#include <stack>

class Graph
{
private:
  std::unordered_map<int, std::vector<int>> adjList;

public:
  void addVertex(int v);
  void addEdge(int src, int dest);
  void removeVertex(int v);
  void removeEdge(int src, int dest);

  void bfs(int src);
  void dfs(int src);

  void shortestPathBFS(int src, int dest);

  void printGraph(void);

  Graph() {}
  ~Graph() {}
};

void Graph::addVertex(int v)
{
  this->adjList[v] = {};
}

void Graph::addEdge(int src, int dest)
{
  if (this->adjList.count(src) && this->adjList.count(dest))
  {
    adjList[src].push_back(dest);
    return;
  }
  throw std::invalid_argument("Make sure both src and dest are graph vertices.");
}

void Graph::removeVertex(int v)
{
  if (this->adjList.count(v))
  {
    auto it = this->adjList.begin();

    while (it != this->adjList.end())
    {
      removeEdge(it->first, v);

      it++;
    }

    this->adjList.erase(v);
    return;
  }
  throw std::invalid_argument("vertex v is not a graph vertex.");
}

void Graph::removeEdge(int src, int dest)
{
  if (this->adjList.count(src) && this->adjList.count(dest))
  {
    std::vector<int> &neighbors = this->adjList[src];

    for (auto i{0}; i < neighbors.size(); i++)
    {
      if (neighbors.at(i) == dest)
      {
        neighbors.erase(neighbors.begin() + i);
      }
    }
    return;
  }
  throw std::invalid_argument("Make sure both src and dest are graph vertices.");
}

void Graph::bfs(int src)
{
  if (!this->adjList.count(src))
  {
    throw std::invalid_argument("src is not a vertex!");
  }

  std::unordered_map<int, bool> visited;
  std::queue<int> q;

  auto it = this->adjList.begin();
  while (it != this->adjList.end())
  {
    visited[it->first] = false;
    it++;
  }

  q.push(src);
  visited[src] = true;

  std::cout << "bfs: ";

  while (!q.empty())
  {
    int currentVertex = q.front();
    q.pop();

    std::cout << currentVertex << " ";

    std::vector<int> neighbors = this->adjList[currentVertex];

    for (auto i{0}; i < neighbors.size(); i++)
    {
      if (!visited[neighbors.at(i)])
      {
        visited[neighbors.at(i)] = true;
        q.push(neighbors.at(i));
      }
    }
  }

  std::cout << "\n";
}

void Graph::dfs(int src)
{
  if (!this->adjList.count(src))
  {
    throw std::invalid_argument("src is not a vertex!");
  }

  std::unordered_map<int, bool> visited;
  std::stack<int> s;

  auto it = this->adjList.begin();
  while (it != this->adjList.end())
  {
    visited[it->first] = false;
    it++;
  }

  s.push(src);
  visited[src] = true;

  std::cout << "dfs: ";

  while (!s.empty())
  {
    int currentVertex = s.top();
    s.pop();

    std::cout << currentVertex << " ";

    std::vector<int> neighbors = this->adjList[currentVertex];

    for (auto i{0}; i < neighbors.size(); i++)
    {
      if (!visited[neighbors.at(i)])
      {
        visited[neighbors.at(i)] = true;
        s.push(neighbors.at(i));
      }
    }
  }
}

void Graph::shortestPathBFS(int src, int dest)
{
  if (!this->adjList.count(src) || !this->adjList.count(dest))
  {
    throw std::invalid_argument("src/dest is not a vertex!");
  }

  std::unordered_map<int, bool> visited;
  std::queue<int> q;
  std::unordered_map<int, int> predecessor;
  std::unordered_map<int, int> distance;

  auto it = this->adjList.begin();
  while (it != this->adjList.end())
  {
    visited[it->first] = false;
    predecessor[it->first] = -1;
    distance[it->first] = 0;

    it++;
  }

  q.push(src);
  visited[src] = true;

  while (!q.empty())
  {
    int currentVertex = q.front();
    q.pop();

    std::vector<int> neighbors = this->adjList[currentVertex];

    for (auto i{0}; i < neighbors.size(); i++)
    {
      if (!visited[neighbors.at(i)])
      {
        visited[neighbors.at(i)] = true;
        q.push(neighbors.at(i));

        predecessor[neighbors.at(i)] = currentVertex;
        distance[neighbors.at(i)] = distance[currentVertex] + 1;
      }
    }
  }

  if (!visited[dest])
  {
    throw std::out_of_range("dest is unreachable from src.");
  }

  // display path and path length:
  std::vector<int> path;
  for (int node = dest; node != -1; node = predecessor[node])
  {
    path.push_back(node);
  }
  std::cout << "\nShortest path length from " << src << " to " << dest << " : " << distance[dest] << "\n";

  std::cout << "Path: ";
  auto i = path.size() - 1;
  while (i != 0)
  {
    std::cout << path.at(i) << " ";
    i--;
  }
  std::cout << "\n";
}

void Graph::printGraph(void)
{
  auto it = this->adjList.begin();

  while (it != adjList.end())
  {
    std::vector<int> nodes = it->second;
    std::cout << it->first << ": ";

    for (auto i{0}; i < nodes.size(); i++)
    {
      std::cout << nodes.at(i) << " ";
    }

    std::cout << "\n";

    it++;
  }
  std::cout << "\n";
}

int main()
{
  Graph g;

  g.addVertex(1);
  g.addVertex(2);
  g.addVertex(3);
  g.addVertex(4);
  g.addVertex(5);
  g.addVertex(6);

  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(2, 3);
  g.addEdge(4, 3);
  g.addEdge(4, 5);
  g.addEdge(3, 6);

  g.printGraph();

  g.bfs(1);
  g.dfs(1);
  g.shortestPathBFS(1, 6);
  // g.removeVertex(4);
  // g.printGraph();

  return 0;
}