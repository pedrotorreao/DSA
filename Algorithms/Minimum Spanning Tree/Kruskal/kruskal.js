/****************************************************************/
/* Kruskal - Finding the Minimum Spanning Tree (MST) ********/
/****************************************************************/

// import modules for DSU and Quicksort:
const { dsu, quickSort } = require("./kruskal_util");

function kruskal(graph) {
  let disjoint_set = new dsu();
  let total_cost = 0;
  let mst = [];

  // get vertices from edge list (slow, look for better way later):
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

  // make a set for each vertex:
  allKeys.forEach((key) => {
    disjoint_set.make_set(key);
  });

  // sort the graph edges in ascending order by weight,
  // could use a sorting algo or a priority queue:
  quickSort(graph);

  // add edges to the MST from lowest weight to highest
  // avoiding edges which form cycles:
  graph.forEach((edge) => {
    [from, to, weight] = edge;
    if (disjoint_set.find_set(from) !== disjoint_set.find_set(to)) {
      mst.push(edge);
      disjoint_set.union_set(from, to);
      total_cost += weight;
    }
  });

  return [mst, total_cost];
}

// test #1:
// expected output:
//    - MST: B-C, C-E, D-E, A-C, E-F
//    - Cost: 17
let edgeList1 = [
  ["A", "B", 9],
  ["A", "C", 4],
  ["B", "C", 1],
  ["B", "D", 5],
  ["B", "E", 6],
  ["C", "E", 2],
  ["D", "E", 3],
  ["D", "F", 8],
  ["E", "F", 7]
];

let [mst1, min_cost1] = kruskal(edgeList1);
console.log("----\nMinimum Spanning Tree:\n", mst1);
console.log("Cost: ", min_cost1);

// test #2:
// expected output:
//    - MST: B-D, C-E, D-E, A-B
//    - Cost: 34
let edgeList2 = [
  ["A", "B", 15],
  ["A", "C", 20],
  ["B", "C", 13],
  ["B", "D", 5],
  ["C", "D", 10],
  ["C", "E", 6],
  ["D", "E", 8]
];

let [mst2, min_cost2] = kruskal(edgeList2);
console.log("----\nMinimum Spanning Tree:\n", mst2);
console.log("Cost: ", min_cost2);
