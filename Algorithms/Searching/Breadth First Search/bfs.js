/****************************************************************/
/* Algorithm: Breadth First Search (BFS) ********/
/****************************************************************/
/* -- Comments:
(1) could also pass as argument the source vertex from which the
    traversal will begin;
(2) instead of pushing into the queue ALL adjacent nodes, we
    could also run another loop through the adjacency list for the 
    currentVertex and push only the nodes not visited yet.
 */
function bfs(graph) {
  //(1)
  let visitedMap = new Map();
  let traversing = "";

  // sets the source vertex to be the first key in the object:
  let root = Object.keys(graph)[0];
  visitedMap.set(root, false);

  let queue = [];
  queue.push(root);

  while (queue.length) {
    let currentVertex = queue.shift();
    if (!visitedMap.get(currentVertex)) {
      traversing += currentVertex + " ";
      visitedMap.set(currentVertex, true);
      queue = queue.concat(graph[currentVertex]); //(2)
    }
  }
  console.log(traversing);
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
