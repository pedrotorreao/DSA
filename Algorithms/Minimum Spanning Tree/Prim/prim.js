/****************************************************************/
/* Prim - Finding the Minimum Spanning Tree (MST) ********/
/****************************************************************/

// import modules for Priority Queue:
const { priorityQueue } = require("./prim_util");

function prim(graph) {
  let mst = []; // array for storing the MST
  let totalCost = 0; // MST total cost
  let visitedMap = new Map(); // map to keep track of the visited vertices
  let pq = new priorityQueue();

  let allKeys = Object.keys(graph); // get all vertices keys
  let source = allKeys[0]; // it could be any vertex.
  let numOfVertices = allKeys.length;
  let numOfEdgesMST = numOfVertices - 1;
  let countOfEdges = 0;

  // initialize all vertices as unvisited:
  allKeys.forEach((node) => {
    visitedMap.set(node, false);
  });

  graph[source].forEach((neighbor) => {
    visitedMap.set(source, true);
  });

  /* ..... */
}

// test #1:
// expected output:
//    - MST: B-C, C-E, D-E, A-C, E-F
//    - Cost: 17

let adjList1 = {
  A: [
    ["B", 9],
    ["C", 4]
  ],
  B: [
    ["C", 1],
    ["A", 9],
    ["D", 5],
    ["E", 6]
  ],
  C: [
    ["A", 4],
    ["B", 1],
    ["E", 2]
  ],
  D: [
    ["B", 5],
    ["E", 3],
    ["F", 8]
  ],
  E: [
    ["C", 2],
    ["B", 6],
    ["D", 3],
    ["F", 7]
  ],
  F: [
    ["D", 8],
    ["E", 7]
  ]
};
