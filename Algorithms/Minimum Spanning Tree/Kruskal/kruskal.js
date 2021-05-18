/****************************************************************/
/* Kruskal - Finding the Minimum Spanning Tree (MST) ********/
/****************************************************************/

const { dsu, quickSort, partition } = require("./kruskal_util");

function kruskal(graph) {
  let disjoint_set = new dsu();
  let total_cost = 0;
  let mst = [];

  /* get vertices from edge list (slow, look for better way later) */
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

  // console.log(total_cost);
  // console.log(mst);

  return [mst, total_cost];
}

let edgeList = [
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

let [mst, min_cost] = kruskal(edgeList);
console.log(mst);
console.log(min_cost);
