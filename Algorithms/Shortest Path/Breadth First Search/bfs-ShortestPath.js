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
  check if source and destination are vertices on the graph
  call bfs()
  call buildPath()
*/
function shortestBFS(graph, source, destination) {
  /* check if source and destination are nodes in the graph: */
  if (!graph[source] || !graph[destination]) {
    return !graph[source]
      ? `${source} is not a vertex`
      : `${destination} is not a vertex`;
  }
  let visitedMap = new Map();
  let predecessor = [];
  let distance = [];
  let numberOfNodes = Object.keys(graph).length;

  for (let i = 0; i < numberOfNodes; ++i) {
    predecessor[i] = -1;
    distance[i] = Infinity;
  }

  let root = graph[source];
  visitedMap.set(source, false);

  let queue = [];
  queue.push(source);

  while (queue.length) {
    let currentVertex = queue.shift();
    let neighbours = graph[currentVertex];

    neighbours.forEach((vertex) => {
      if (!visitedMap.get(vertex)) {
        visitedMap.set(vertex, true);

        queue.push(vertex);

        predecessor[vertex] = currentVertex;

        if (vertex === destination) {
          //console.log("ai", predecessor);
          return;
        }
      }
    });
  }

  /*  ... review theory */
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
console.log(shortestBFS(adjList1, "2", "5"));

// (2): Should output 0 -> 11 -> 2 -> 4 -> 9 -> 7 -> 19 -> 3 -> 1
// let adjList2 = {
//   0: ["11", "2", "4"],
//   1: ["3", "7", "19"],
//   2: ["0", "4", "7", "19"],
//   3: ["9", "7", "1"],
//   4: ["0", "2"],
//   7: ["2", "11", "9", "1", "19"],
//   9: ["11", "3", "7"],
//   11: ["0", "9", "7"],
//   19: ["2", "7", "1"],
// };
// bfs(adjList2);
