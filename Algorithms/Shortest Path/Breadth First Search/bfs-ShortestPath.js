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

function shortestBFS(graph, source, destination) {
  /* check if source and destination are nodes in the graph: */
  if (!graph[source] || !graph[destination]) {
    return !graph[source]
      ? `${source} is not a vertex`
      : `${destination} is not a vertex`;
  }

  let visitedMap = new Map();
  let queue = [];
  let predecessor = [];
  let distance = [];

  let allKeys = Object.keys(graph); // get all vertices keys
  let numberOfNodes = allKeys.length; // get the number of nodes in the graph

  allKeys.forEach((node) => {
    visitedMap.set(node, false); // initialize all vertices to unvisited
    predecessor[node] = -1;
    distance[node] = 0;
  });

  visitedMap.set(source, true);
  queue.push(source);

  while (queue.length) {
    let currentVertex = queue.shift();
    let neighbours = graph[currentVertex];

    neighbours.forEach((vertex) => {
      if (!visitedMap.get(vertex)) {
        visitedMap.set(vertex, true);

        queue.push(vertex);

        distance[vertex] = distance[currentVertex] + 1;

        predecessor[vertex] = currentVertex;
      }
    });
  }

  if (!visitedMap.get(destination)) {
    console.log(`There is no path from ${source} to ${destination}`);
  } else {
    let path = [];
    for (let node = destination; node != -1; node = predecessor[node]) {
      path.push(node);
    }
    path.reverse();

    console.log(
      `Shortest path length from ${source} to ${destination}: ${distance[destination]}`
    );
    console.log("Path: ", displayPath(path));
    console.log("\n");
  }

  function displayPath(array) {
    let output = "";
    for (let i = 0; i < array.length; i++) {
      if (array[i] !== array[array.length - 1]) {
        output += array[i] + " -> ";
      } else {
        output += array[i];
      }
    }
    return output;
  }
}

// TESTS:
// (1) - BFS: 0 -> 1 -> 3 -> 5 -> 2 -> 4
let adjList1 = {
  0: ["1", "3", "5"],
  1: ["0", "2", "4"],
  2: ["1"],
  3: ["0", "4", "5"],
  4: ["1", "3"],
  5: ["0", "3"]
};
shortestBFS(adjList1, "2", "5");
shortestBFS(adjList1, "0", "5");
shortestBFS(adjList1, "3", "1");
shortestBFS(adjList1, "4", "2");

console.log("-----");
// (2) - BFS: 0 -> 11 -> 2 -> 4 -> 9 -> 7 -> 19 -> 3 -> 1
let adjList2 = {
  0: ["11", "2", "4"],
  1: ["3", "7", "19"],
  2: ["0", "4", "7", "19"],
  3: ["9", "1"],
  4: ["0", "2"],
  7: ["2", "11", "9", "1", "19"],
  9: ["11", "3", "7"],
  11: ["0", "9", "7"],
  19: ["2", "7", "1"]
};
shortestBFS(adjList2, "1", "11");
shortestBFS(adjList2, "3", "0");
shortestBFS(adjList2, "4", "3");
shortestBFS(adjList2, "0", "0");
shortestBFS(adjList2, "1", "4");
shortestBFS(adjList2, "11", "1");
shortestBFS(adjList2, "9", "4");
