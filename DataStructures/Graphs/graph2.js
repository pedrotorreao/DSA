/***************************************************************************/
/* Graph 2 - Using JS Object as building block for the Adjacent List *******/
/***************************************************************************/
class Graph {
  constructor() {
    this.numberOfNodes = 0;
    this.adjacencyList = {};
  }
  addVertex(node) {
    this.adjacencyList[node] = [];
    ++this.numberOfNodes;
  }

  removeVertex(node) {
    if (this.hasVertex(node)) {
      // check which vertices have edges connecting to this node
      let neighbors = this.getNeighbors(node); //[3,2,5]
      // delete all these edges
      neighbors.forEach((vertex) => {
        let neighborEdges = this.getNeighbors(vertex);
        const foundNode = (element) => element === node;
        // let edgeIdx = neighborEdges.findIndex((el) => {
        //   if (el === node) return idx;
        // });
        let edgeIdx = neighborEdges.findIndex(foundNode);

        this.adjacencyList[vertex].splice(edgeIdx, 1);
      });
      // remove node
      delete this.adjacencyList[node];
    }
  }

  addEdge(node1, node2) {
    //undirected Graph
    if (this.hasVertex(node1) && this.hasVertex(node2)) {
      this.adjacencyList[node1].push(node2);
      this.adjacencyList[node2].push(node1);
      return;
    }
    let error = this.hasVertex(node1)
      ? node2
      : this.hasVertex(node2)
      ? node1
      : 0;
    switch (error) {
      case node1:
        console.log(`node1 ${node1} is not a vertex`);
        break;
      case node2:
        console.log(`node2 ${node2} is not a vertex`);
        break;
      default:
        console.log(`nodes ${node1} and ${node2} are not vertices`);
        break;
    }
  }

  removeEdge(node1, node2) {}

  hasVertex(node) {
    return this.adjacencyList[node] ? true : false;
  }

  hasNeighbors(node) {
    return this.adjacencyList[node].length ? true : false;
  }

  getAllVertices() {
    return Object.keys(this.adjacencyList);
  }

  getNeighbors(node) {
    if (this.hasNeighbors(node)) {
      let neighborsList = this.adjacencyList[node];
      let neighbors = "";
      for (node of neighborsList) {
        neighbors = neighbors + node + " ";
      }
      console.log(neighbors);
      return neighborsList;
    }
    console.log(`node ${node} has no neighbors`);
  }

  showConnections() {
    const allNodes = Object.keys(this.adjacencyList);
    for (let node of allNodes) {
      let nodeConnections = this.adjacencyList[node];
      let connections = "";
      let vertex;
      for (vertex of nodeConnections) {
        connections += vertex + " ";
      }
      console.log(node + "-->" + connections);
    }
  }
}

const myGraph = new Graph();
myGraph.addVertex("0");
myGraph.addVertex("1");
myGraph.addVertex("2");
myGraph.addVertex("3");
myGraph.addVertex("4");
myGraph.addVertex("5");
myGraph.addVertex("6");
myGraph.addEdge("3", "1");
myGraph.addEdge("3", "4");
myGraph.addEdge("4", "2");
myGraph.addEdge("4", "5");
myGraph.addEdge("1", "2");
myGraph.addEdge("1", "0");
myGraph.addEdge("0", "2");
myGraph.addEdge("6", "5");

myGraph.addVertex("7");
myGraph.getNeighbors("4");

myGraph.showConnections();
console.log(myGraph.getAllVertices());

myGraph.removeVertex("4");
myGraph.showConnections();

//Answer:
// 0-->1 2
// 1-->3 2 0
// 2-->4 1 0
// 3-->1 4
// 4-->3 2 5
// 5-->4 6
// 6-->5
