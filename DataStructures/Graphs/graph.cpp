/***************************************************************************/
/* Graph *******/
/***************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>

class Graph
{
private:
  std::unordered_map<int, std::vector<int>> adjList;
  int numOfVertices;

public:
  void addVertex(int v);
  void addEdge(int src, int dest);
  void removeVertex(int v);
  void removeEdge(int src, int dest);

  void printGraph(void);

  Graph()
  {
    this->numOfVertices = 0;
  }
  ~Graph() {}
};

void Graph::addVertex(int v)
{
  this->adjList[v] = {};
  ++this->numOfVertices;
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

  g.addEdge(1, 2);
  g.addEdge(1, 4);
  g.addEdge(2, 4);
  g.addEdge(2, 3);
  g.addEdge(4, 3);
  g.addEdge(4, 5);

  g.printGraph();

  g.removeVertex(4);
  g.printGraph();

  return 0;
}