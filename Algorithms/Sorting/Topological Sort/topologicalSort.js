/****************************************************************/
/* Algorithm: Topological Sort ********/
/****************************************************************/

function topologicalSort(graph) {
  let visitedMap = new Map();
  let topSort = [];

  let allKeys = Object.keys(graph);
  allKeys.forEach((node) => {
    visitedMap.set(node, false);
  });

  let root = allKeys[0];

  let stack = [];

  for (let i = 0; i < allKeys.length; i++) {
    if (!visitedMap.get(allKeys[i])) {
      let neighbours = graph[allKeys[i]];

      topologicalVisit(allKeys[i], graph, neighbours);
    }
    topSort.push(stack.pop());
  }
  displaySort(topSort);

  function topologicalVisit(node, graph = this.graph, neighbours) {
    if (neighbours.length) {
      neighbours.forEach((element) => {
        if (!visitedMap.get(element)) {
          topologicalVisit(element, graph, graph[element]);
        }
      });
    }

    visitedMap.set(node, true);
    stack.push(node);
  }

  function displaySort(array) {
    let output = "";
    for (let i = 0; i < array.length; i++) {
      if (array[i] !== array[array.length - 1]) {
        output += array[i] + " -> ";
      } else {
        output += array[i];
      }
    }
    console.log(output);
  }
}

// TESTS:
// (1) - Expected output: B->E->A->C->D
let graph1 = {
  B: ["E", "C"],
  C: ["D"],
  A: ["C", "D"],
  D: [],
  E: ["A", "C"],
};
topologicalSort(graph1);

// (2) - Expected output: 1->2->4->3->5 or 1->2->4->5->3
let graph2 = {
  1: ["2", "4"],
  2: ["3", "4"],
  3: [],
  4: ["3", "5"],
  5: [],
};
topologicalSort(graph2);
