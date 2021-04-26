/****************************************************************/
/* Algorithm: Bellman-Ford - Shortest Path ********/
/****************************************************************/

function bellmanFord(graph, source, destination) {
  let predecessor = [];
  let distance = [];

  let numberOfVertices = graph.length;

  for (let i = 0; i < numberOfVertices; i++) {
    distance[i] = Infinity;
    predecessor[i] = -1;
  }

  distance[source] = 0;

  for (let i = 0; i < numberOfVertices - 1; i++) {
    graph.forEach((vertex) => {
      let [vertexFrom, vertexTo, weightTo] = vertex;

      if (distance[vertexFrom] + weightTo < distance[vertexTo]) {
        distance[vertexTo] = distance[vertexFrom] + weightTo;
        predecessor[vertexTo] = vertexFrom;
      }
    });
  }

  buildPath(distance, predecessor);

  return;

  function buildPath(dist = distance, pred = predecessor) {
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
console.log("---- TEST 1 ----");
bellmanFord(edgeList1, 1, 2);
