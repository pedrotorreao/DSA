/****************************************************************/
/* Algorithm: Breadth First Search (BFS) - Shortest Path ********/
/****************************************************************/
/* -- Comments:
(1) instead of pushing into the queue ALL adjacent nodes, we
    could also run another loop through the adjacency list for the 
    currentVertex and push only the nodes not visited yet.
(2) bfs is only effective to find the shortest path in a graph if the 
    graph being traversed is an unweighted graph.
 */

/*
shortesPathBFS(graph, source, destination):
  call bfs()
  call buildPath()
*/
function bfs(graph, source, destination) {
  let visitedMap = new Map();
  let traversing = "";
  let predecessor = [];

  // gets all the adjacent nodes of A
  let root = graph[source];
  visitedMap.set(root, false);

  let queue = [];
  queue.push(root);

  while (queue.length) {
    let currentVertex = queue.shift();
    if (!visitedMap.get(currentVertex)) {
      traversing += currentVertex + " ";
      visitedMap.set(currentVertex, true);
      queue = queue.concat(graph[currentVertex]); //(1)

      // ? If not this way, maybe rewrite this function and break it into smaller methods
      predecessor[graph[currentVertex]] = currentVertex;

      if (currentVertex === destination) {
        return true;
      }
    }
  }
  console.log(traversing);
  return false;
}

// TESTS:
// (1): Should output 0 -> 1 -> 3 -> 5 -> 2 -> 4
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
bfs(adjList2);
