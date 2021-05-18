/****************************************************************/
/* Algorithm: Bellman-Ford - Shortest Path ********/
/****************************************************************/

function bellmanFord(graph, source, destination) {
  let predecessor = [];
  let distance = [];

  // get all the vertices from the edge list:
  let allKeys = {};
  graph.forEach((edge) => {
    let from = edge[0];
    let to = edge[1];

    if (typeof allKeys[from] === "undefined") {
      allKeys[from] = true;
    }
    if (typeof allKeys[to] === "undefined") {
      allKeys[to] = true;
    }
  });
  allKeys = Object.keys(allKeys);
  let numberOfVertices = allKeys.length;

  // initialize the distance and predecessor arrays:
  allKeys.forEach((key) => {
    distance[key] = Infinity;
    predecessor[key] = -1;
  });

  // starting node has distance set to zero:
  distance[source] = 0;

  // the algorithm will take at most N-1 iterations to finish, N being the
  // number of vertices. Also, in case no edges gets relaxed during an
  // iteration, it means the algorithm has already reached its solution.
  let relaxed = true;

  for (let i = 0; i < numberOfVertices - 1 && relaxed; i++) {
    relaxed = false;
    graph.forEach((edge) => {
      let [edgeFrom, edgeTo, weightTo] = edge;

      if (distance[edgeFrom] + weightTo < distance[edgeTo]) {
        distance[edgeTo] = distance[edgeFrom] + weightTo;
        predecessor[edgeTo] = edgeFrom;
        relaxed = true;
      }
    });
  }

  // in order to detect whether a negative cycle exist, we simply
  // run the algorithm one more time, if any of the edges gets relaxed,
  // this means that there is a negative cycle, since edge' weighs are still
  // being updated after the N-1 iteration.
  console.log("Checking for negative cycles ...");
  let negCycleExist = false;

  graph.forEach((edge) => {
    let [edgeFrom, edgeTo, weightTo] = edge;

    if (distance[edgeTo] > distance[edgeFrom] + weightTo) {
      negCycleExist = true;
      return;
    }
  });

  if (negCycleExist) {
    console.log("Graph contains a negative cycle.");
    return;
  }
  console.log("... no negative cycles detected \n");

  buildPath(distance, predecessor, source, destination);

  function buildPath(
    dist = distance,
    pred = predecessor,
    src = source,
    dest = destination
  ) {
    let path = [];
    for (let node = destination; node != -1; node = predecessor[node]) {
      path.push(node);
    }
    path.reverse();

    if (path[0] !== source) {
      console.log(`Vertex ${destination} is not reachable from ${source} \n`);
      return;
    }
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

let edgeList1 = [
  ["1", "2", 50],
  ["1", "3", 45],
  ["1", "4", 10],
  ["2", "4", 15],
  ["2", "3", 10],
  ["3", "5", 30],
  ["4", "1", 10],
  ["4", "5", 15],
  ["5", "2", 20],
  ["5", "3", 30],
  ["6", "5", 3]
];
// console.log("---- TEST 1 ----");
// bellmanFord(edgeList1, "1", "2");
// bellmanFord(edgeList1, "1", "5");
// bellmanFord(edgeList1, "1", "3");
// bellmanFord(edgeList1, "2", "5");
// bellmanFord(edgeList1, "1", "6");

let edgeList2 = [
  ["A", "B", 10],
  ["A", "C", 5],
  ["B", "D", 1],
  ["C", "B", 3],
  ["C", "D", 9],
  ["C", "E", 2],
  ["E", "A", 2],
  ["E", "D", 6]
];
console.log("---- TEST 2 ----");
bellmanFord(edgeList2, "A", "D");
bellmanFord(edgeList2, "A", "B");
bellmanFord(edgeList2, "C", "D");
bellmanFord(edgeList2, "E", "B");

let edgeList3 = [
  ["1", "2", 4],
  ["1", "4", 5],
  ["4", "3", 3],
  ["3", "2", -10],
  ["2", "4", 5]
];
// console.log("---- TEST 3 ----");
// bellmanFord(edgeList3, "1", "2");

let edgeList4 = [
  ["1", "3", 5],
  ["1", "2", 4],
  ["2", "4", 7],
  ["4", "3", -15],
  ["3", "2", 7]
];
// console.log("---- TEST 4 ----");
// bellmanFord(edgeList4, "1", "3");
