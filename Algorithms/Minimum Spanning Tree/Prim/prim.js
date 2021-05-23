/****************************************************************/
/* Prim - Finding the Minimum Spanning Tree (MST) ********/
/****************************************************************/

// import modules for Priority Queue:
const { priorityQueue } = require("./prim_util");

function prim(graph) {
  let mst = []; // array for storing the MST
  let totalCost = 0; // MST total cost
  let distance = [];
  let visitedMap = new Map(); // map to keep track of the visited vertices
  let pq = new priorityQueue();

  let allKeys = Object.keys(graph); // get all vertices keys
  let source = allKeys[0]; // it could be any vertex.
  const numOfVertices = allKeys.length;
  const numOfEdgesMST = numOfVertices - 1;
  let countOfEdges = 0;

  // initialize all vertices as unvisited:
  allKeys.forEach((node) => {
    visitedMap.set(node, false);
  });

  addToPQ(graph, source, visitedMap, pq);

  while (pq.peek() && countOfEdges !== numOfEdgesMST) {
    let [vertexPair, weightTo] = pq.remove();
    let [vertexFrom, vertexTo] = vertexPair;
    if (!visitedMap.get(vertexTo)) {
      mst.push([vertexFrom, vertexTo, weightTo]);
      countOfEdges++;
      totalCost += weightTo;

      addToPQ(graph, vertexTo, visitedMap, pq);
    }
  }

  return [mst, totalCost];
}

/**
 * Method for iterating over the edges of a vertex and add them to the priority queue.
 * @param {Object} graph adjacency list which represents the graph.
 * @param {string} vertex string representing an individual vertex.
 * @param {Map} map Map for keeping track of visited vertices.
 * @param {Priority Queue} queue reference for a priority queue which sorts the edges based on their weight.
 */
function addToPQ(graph, vertex, map, queue) {
  map.set(vertex, true);

  let neighbors = graph[vertex];

  neighbors.forEach((neighbor) => {
    let [vertexTo, weightTo] = neighbor;
    if (!map.get(vertexTo)) {
      //queue.insert([vertexTo, weightTo]);
      queue.insert([[vertex, vertexTo], weightTo]);
    }
  });
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

let [mst1, min_cost1] = prim(adjList1);
console.log("----\nMinimum Spanning Tree:\n", mst1);
console.log("Cost: ", min_cost1);

// test #2:
// expected output:
//    - MST: B-D, C-E, D-E, A-B
//    - Cost: 34
let adjList2 = {
  A: [
    ["B", 15],
    ["C", 20]
  ],
  B: [
    ["A", 15],
    ["C", 13],
    ["D", 5]
  ],
  C: [
    ["A", 20],
    ["B", 13],
    ["D", 10],
    ["E", 6]
  ],
  D: [
    ["B", 5],
    ["C", 10],
    ["E", 8]
  ],
  E: [
    ["C", 6],
    ["D", 8]
  ]
};

let [mst2, min_cost2] = prim(adjList2);
console.log("----\nMinimum Spanning Tree:\n", mst2);
console.log("Cost: ", min_cost2);
