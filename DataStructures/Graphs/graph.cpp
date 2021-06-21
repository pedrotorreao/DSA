/***************************************************************************/
/* Graph *******/
/***************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>

class Graph
{
private:
  std::unordered_map<int, std::vector<int>> adjList;

public:
  void addVertex(int v);
  void addEdge(int src, int dest);
  void removeVertex(int v);
  void removeEdge(int src, int dest);

  void printGraph(void);

  Graph() {}
  ~Graph() {}
};

void Graph::addVertex(int v)
{
}

void Graph::addEdge(int src, int dest)
{
}

void Graph::removeVertex(int v)
{
}

void Graph::removeEdge(int src, int dest)
{
}

void Graph::printGraph(void)
{
}

int main()
{

  return 0;
}