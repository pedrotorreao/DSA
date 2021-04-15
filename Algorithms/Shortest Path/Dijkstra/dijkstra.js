/****************************************************************/
/* Algorithm: Dijkstra - Shortest Path ********/
/****************************************************************/

function dijkstra(graph, source) {
  let visitedMap = new Map();
  let predecessor = [];
  let distance = [];
  let queue = new priorityQueue();

  let allKeys = Object.keys(graph); // get all vertices keys
  let numberOfNodes = allKeys.length; // get the number of nodes in the graph

  allKeys.forEach((node) => {
    visitedMap.set(node, false);
    distance[node] = Infinity;
    predecessor[node] = -1;
  });

  // for (let i = 0; i < numberOfNodes; i++) {
  //   distance[i] = Infinity;
  //   predecessor[i] = -1;
  // }

  //visitedMap.set(source, true);
  distance[source] = 0;

  queue.insert([source, distance[source]]);

  // let [v, min] = queue.remove();

  // console.log(v);
  // console.log(min);
  while (queue.getSize() !== 0) {
    let [currentVertex, minWeight] = queue.remove();
    let neighbours = graph[currentVertex];

    visitedMap.set(currentVertex, true);

    neighbours.forEach((vertex) => {
      // vertex[0]: vertexTo, vertex[1]: weight
      let [vertexTo, weightTo] = vertex;
      if (!visitedMap.get(vertexTo)) {
        if (distance[currentVertex] + weightTo < distance[vertexTo]) {
          distance[vertexTo] = distance[currentVertex] + weightTo;
          predecessor[vertexTo] = currentVertex;

          queue.insert([vertexTo, distance[vertexTo]]);
        }
      }
    });
    console.log(distance);
  }

  //-- Another possible approach to test:
  // for (let i = 0; i < allKeys.length; i++) {
  //   let v = -1;
  //   for (let j = 0; j < allKeys.length; j++) {
  //     if (!visitedMap.get(v) && (v === -1 || distance[j] < distance[v])) {
  //       v = j;
  //     }
  //   }
  //   if (distance[v] === Infinity) break;

  //   visitedMap.set(v, true);

  //   let neighbours = graph[v];
  //   console.log(neighbours);

  //   for (let vertex of graph[v]) {
  //     let to = vertex[0];
  //     let weight = vertex[1];

  //     if (distance[v] + weight < distance[to]) {
  //       distance[to] = distance[v] + weight;
  //       predecessor[to] = v;
  //     }
  //   }
  // }
  //--
}

/* -----------------------------------------------------------------------------
------------------------ PRIORITY QUEUE USING MIN HEAP -------------------------
----------------------------------------------------------------------------- */
class minHeap {
  constructor() {
    this.heap = [];
  }

  peek() {
    return this.heap[1][0];
  }

  insert(value) {
    if (this.heap.length < 1) {
      //if heap is empty, set first array element to null and push value to the end:
      this.heap[0] = null;
      this.heap.push(value);
      return;
    }
    this.heap.push(value);

    this.heapifyBottomTopRecursively();
  }
  heapifyBottomTopRecursively(index = this.heap.length - 1) {
    let parentIndex = Math.floor(index / 2);
    //in case we've reached the root of the heap, return:
    if (!this.heap[parentIndex]) return;

    //if parent value is greater than the newly added element, swap them and go up in the heap:
    if (this.heap[parentIndex][1] > this.heap[index][1]) {
      this.swapValues(index, parentIndex);
      index = parentIndex;
      this.heapifyBottomTopRecursively(index);
    } else {
      return;
    }
  }

  // ------------ MIN HEAP: DELETION METHODS ------------------->>
  remove() {
    if (this.heap.length <= 1) {
      return;
    } //heap is empty.

    //Replaces top element by the last element in the heap:
    this.swapValues(this.heap.length - 1, 1);
    let largest = this.heap.pop(); //stores the top element being deleted in case we need it for heap sort

    this.heapifyTopBottomRecursively();
    return largest;
  }

  heapifyTopBottomRecursively(rootIndex = 1) {
    if (!this.heap[rootIndex]) {
      return;
    }

    let leftIndex, rightIndex;
    leftIndex = 2 * rootIndex;
    rightIndex = 2 * rootIndex + 1;

    /*if there are no children, return. Reminder: as the heap must be a complete binary tree, all its levels are filled except possibly for the last, and in the last level, all the keys/values are aligned as left as possible, so if a node doesn't have a left child, it won't have a right child since the left subtree would be filled first:*/
    if (!this.heap[leftIndex]) {
      return;
    }

    if (
      this.heap[rootIndex][1] > this.heap[leftIndex][1] ||
      this.heap[rootIndex][1] > this.heap[rightIndex][1]
    ) {
      //if there's no right child or left child's value is less than right child's, swap subtrees' root and left child's values  and go down the heap:
      if (
        !this.heap[rightIndex] ||
        this.heap[leftIndex][1] < this.heap[rightIndex][1]
      ) {
        this.swapValues(rootIndex, leftIndex);
        rootIndex = leftIndex;
      } else {
        this.swapValues(rootIndex, rightIndex);
        rootIndex = rightIndex;
      }
      this.heapifyTopBottomRecursively(rootIndex);
    }
  }

  swapValues(child, parent) {
    let temp = this.heap[child];
    this.heap[child] = this.heap[parent];
    this.heap[parent] = temp;
  }
  getSize() {
    return this.heap.length - 1;
  }
}
class priorityQueue extends minHeap {
  constructor() {
    super();
    this.priorityQ = new minHeap();
  }
}
/* -----------------------------------------------------------------------------
----------------------------------------------------------------------------- */

// -- TESTS: Expected output - (min cost, path)
/* 1. source vertex: 1
    cost from source to node:
      4: 10
      5: 25
      2: 45
      3: 45
      6: Infinite
*/
let adjList1 = {
  1: [
    ["2", 50],
    ["3", 45],
    ["4", 10]
  ],
  2: [
    ["4", 15],
    ["3", 10]
  ],
  3: [["5", 30]],
  4: [
    ["1", 10],
    ["5", 15]
  ],
  5: [
    ["2", 20],
    ["3", 30]
  ],
  6: [["5", 3]]
};

dijkstra(adjList1, 1);

/* 2. source vertex: A
    cost from source to node:
      B: 8
      C: 5
      D: 9
      E: 7
*/
let adjList2 = {
  A: [
    ["B", 10],
    ["C", 5]
  ],
  B: [["D", 1]],
  C: [
    ["B", 3],
    ["D", 9],
    ["E", 2]
  ],
  D: [[]],
  E: [["A", 2]]
};
