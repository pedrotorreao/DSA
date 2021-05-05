/****************************************************************/
/* Algorithm: Floyd-Warshall - Shortest Path ********/
/****************************************************************/
/**
 * Floyd-Warshall Algorithm - (APSP):
 * @param {array} graph adjacency matrix representig our graph.
 * @returns all pairs shortest paths matrix,
 *          array of adjacent vertices to help rebuild the paths.
 */
function floydWarshall(graph) {
  let n = graph.length;

  // create and initialize matrices, this approach might be slow:
  let distance = [...Array(n)].map((x) => Array(n).fill(0));
  let successor = [...Array(n)].map((x) => Array(n).fill(null));

  // setup matrices:
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      distance[i][j] = graph[i][j]; // copy input matrix graph[][]
      if (graph[i][j] !== Infinity) {
        // if there is a path from i to j, go to j from i.
        successor[i][j] = j;
      }
    }
  }
  // find shortest paths:
  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        if (distance[i][j] > distance[i][k] + distance[k][j]) {
          distance[i][j] = distance[i][k] + distance[k][j];
          successor[i][j] = successor[i][k];
        }
      }
    }
  }

  // detect negative cycles:
  let negativeCycle = false;

  for (let k = 0; k < n; k++) {
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < n; j++) {
        if (distance[i][j] > distance[i][k] + distance[k][j]) {
          distance[i][j] = -Infinity;
          successor[i][j] = -1;
          negativeCycle = true;
        }
      }
    }
  }

  if (negativeCycle) {
    console.log(
      `There is negative cycles in the graph \n
       - Elements equal to ${-Infinity} are affected by a negative cycle.`
    );
  }

  return [distance, successor];
}

/**
 * Helper method which is used for retracing the steps taken on the SPs:
 * @param {array} dist all pairs shortest paths matrix (FW algo output).
 * @param {array} next array of adjacent vertices to help rebuild the paths.
 * @param {number} src starting point for the shortest path
 * @param {*} dest destination vertex to be reached from the starting vertex.
 * @returns boolean indicating whether dest is reachable from src
 */
function buildPath(dist, next, src, dest) {
  let path = [];
  if (dist[src][dest] === Infinity) return path; // destination is unreachable from source vertex

  let node = src;
  for (; node !== dest; node = next[node][dest]) {
    if (node === -1) return null; // there is a negative cycle
    path.push(node);
  }

  if (next[node][dest] === -1) return null; // there is a negative cycle
  path.push(dest);

  console.log(
    `Shortest path length from ${src} to ${dest}: ${dist[src][dest]}`
  );
  console.log("Path: ", displayPath(path));
  console.log("\n");
}

/**
 * Helper method for building the SP string to be displayed:
 * @param {array} pathArray array containing the sequence of steps on the SP.
 * @returns string representing the path.
 */
function displayPath(pathArray) {
  let output = "";
  for (let i = 0; i < pathArray.length; i++) {
    if (pathArray[i] !== pathArray[pathArray.length - 1]) {
      output += pathArray[i] + " -> ";
    } else {
      output += pathArray[i];
    }
  }
  return output;
}
/* ------ TEST #1 -------*/
let adjMatrix1 = [
  /*A:*/ [0, 8, Infinity, 1],
  /*B:*/ [Infinity, 0, 1, Infinity],
  /*C:*/ [4, Infinity, 0, Infinity],
  /*D:*/ [Infinity, 2, 9, 0]
];
let [shortestPath1, pathMatrix1] = floydWarshall(adjMatrix1);

console.log("All Pairs Shortest Paths (APSP) Matrix:");
console.table(shortestPath1);
/* shortest path from C to B - Expected output:
      2 -> 0 -> 3 -> 1, which translates to C -> A -> D -> B */
buildPath(shortestPath1, pathMatrix1, 2, 1);
/* shortest path from A to C - Expected output:
      0 -> 3 -> 1 -> 2, which translates to A -> B -> B -> C*/
buildPath(shortestPath1, pathMatrix1, 0, 2);
/* ---- END OF TEST #1 ----*/

/* ------ TEST #2 -------*/
let adjMatrix2 = [
  /*1:*/ [0, 9, -4, Infinity],
  /*2:*/ [6, 0, Infinity, 2],
  /*3:*/ [Infinity, 5, 0, Infinity],
  /*4:*/ [Infinity, Infinity, 1, 0]
];
let [shortestPath2, pathMatrix2] = floydWarshall(adjMatrix2);

console.log("All Pairs Shortest Paths (APSP) Matrix:");
console.table(shortestPath2);
/* shortest path from 1 to 4 - Expected output: 
      0 -> 2 -> 1 -> 3, which translates to 1 -> 3 -> 2 -> 4 */
buildPath(shortestPath2, pathMatrix2, 0, 3);
/* shortest path from 1 to 2 - Expected output:
      0 -> 2 -> 1, which translates to 1 -> 3 -> 2*/
buildPath(shortestPath2, pathMatrix2, 0, 1);

/* ---- END OF TEST #2 ----*/
