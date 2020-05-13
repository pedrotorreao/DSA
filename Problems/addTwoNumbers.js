/****************************************************************/
/*Problem: Add Two Numbers  ********/
/****************************************************************/
/*
-- Summary: You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
-- Input(s): (2 -> 4 -> 3) + (5 -> 6 -> 4)
-- Expected output(s): 7 -> 0 -> 8
-- Explanation: 342 + 465 = 807
-- Constraints: -
*/
// BRUTE FORCE APPROACH
var addTwoNumbers = function(l1, l2) {
  //array from each list -> join the digits ->parse as int -> reverse it -> sum -> invert -> separe -> array ->list
  let ar1 = [];
  let ar2 = [];
  let ar3 = [];
  let size = 0;
  let diff = 0;

  // Go through the LLs and assign each of its elements to an array position
  let currentNode = l1.head;
  while (currentNode !== null) {
    ar1.push (currentNode.value);
    currentNode = currentNode.next;
  }
  ar1 = ar1.reverse(); // Remember: The digits are stored in reverse order.

  currentNode = l2.head;
  while (currentNode !== null) {
    ar2.push (currentNode.value);
    currentNode = currentNode.next;
  }
  ar2 = ar2.reverse();
  // ----------------------------------------------------------------------- //
  // Check if the lists have the same size. If not, complete the smaller one
  // with zeroes.
  diff = Math.abs(ar1.length - ar2.length);

  if (diff && ar1.length > ar2.length) {
    for (let i = 0; i < diff; i++) {
      ar2.unshift(0);
    }
    size = ar1.length;
  } else if (diff && ar2.length > ar1.length) {
    for (let i = 0; i < diff; i++) {
      ar1.unshift(0);
    }
    size = ar2.length;
  } else { size = ar1.length; }
  // ----------------------------------------------------------------------- //
  // Sum the array elements and check if the sum is greater or equal to 10.
  // If so, subtract 10 from it and add 1 to the element at its left. In case
  // there are no more elements, add 1 the start of the array.
  for (let i = 0; i < size; i++) {
    ar3[i] = ar1[i] + ar2[i];
  }
  for (let i = size-1; i >= 0; i--) {
    if (ar3[i] >= 10) {
      ar3[i] = ar3[i] - 10;
      if (i-1 >= 0) {
        ar3[i-1] += 1;
      } else {
        ar3.unshift(1);
      }
    }
  }
  // ----------------------------------------------------------------------- //
  // Go through the array and convert it into a LL
  let l3 = null;
  let listSoFar = null;

  for (let i = 0; i < ar3.length; i++) {
    listSoFar = l3;
    l3 = {
      value: ar3[i],
      next: listSoFar
    }
  }
  // ----------------------------------------------------------------------- //
  console.log(ar1);
  console.log(ar2);
  console.log(ar3);

  return l3;
};

let mySLL1 = new SLL();
// TC 1:
// mySLL1.append(2);
// mySLL1.append(4);
// mySLL1.append(3);
// mySLL1.append(1);
//TC 2:
mySLL1.append(5);
//TC 3:
//mySLL1.append(1);

let mySLL2 = new SLL();
// TC 1:
// mySLL2.append(5);
// mySLL2.append(6);
// mySLL2.append(4);
//TC 2:
mySLL2.append(5);
//TC 3:
//mySLL2.append(9);
//mySLL2.append(9);
console.log(addTwoNumbers(mySLL1,mySLL2));

// ----------------------------------------------------------------------- //
// Linked List Creation Function:
function SLL () {
  this.head = null;
  this.tail = this.head;
  this.length = 0;
  
  //Method for creating a new node (newNode()):
  let Node = function (value) {
    this.value = value;
    this.next = null;
  };

  //Method for returning the size of the LL (getSize()):
  this.getSize = function () {
    return this.length;
  };

  //Method for inserting a new node at the end of the LL (append()):
  this.append = function (value) {
    let node = new Node(value);
    if (this.head === null) {
      this.head = node;
      this.tail = this.head;
    } else {
      let currentNode = this.head;
      while (currentNode.next) {
        currentNode = currentNode.next;
      }
      //node.next = this.head;
      currentNode.next = node;
      this.tail = node;
      //node.next = this.head;
      //this.tail.next = this.head;
      //console.log(node);
    }
    this.length++;
  };
}
/****************************************************************/
/*Problem: Add Two Numbers -- Leetcode Adapted Solution  ********/
/****************************************************************/
/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/*
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let ar1 = [];
  let ar2 = [];
  let ar3 = [];
  let size = 0;
  let diff = 0;

  var index1 = 0;
  var array1SoFar;
  
  for(var node = l1; node; node = node.next) {
    array1SoFar = ar1;
    ar1[index1] = node.val;
    index1++;
  }
    
  ar1 = ar1.reverse();

  var index2 = 0;
  var array2SoFar;
  
  for(var node = l2; node; node = node.next) {
    array2SoFar = ar2;
    ar2[index2] = node.val;
    index2++;
  }
  ar2 = ar2.reverse();

  diff = Math.abs(ar1.length - ar2.length);

  if (diff && ar1.length > ar2.length) {
    for (let i = 0; i < diff; i++) {
      ar2.unshift(0);
    }
    size = ar1.length;
  } else if (diff && ar2.length > ar1.length) {
    for (let i = 0; i < diff; i++) {
      ar1.unshift(0);
    }
    size = ar2.length;
  } else { size = ar1.length; }

  for (let i = 0; i < size; i++) {
    ar3[i] = ar1[i] + ar2[i];
  }
  for (let i = size-1; i >= 0; i--) {
    if (ar3[i] >= 10) {
      ar3[i] = ar3[i] - 10;
      if (i-1 >= 0) {
        ar3[i-1] += 1;
      } else {
        ar3.unshift(1);
      }
    }
  }
  let l3 = null;
  let listSoFar = null;

  for (let i = 0; i < ar3.length; i++) {
    listSoFar = l3;
    l3 = {
      val: ar3[i],
      next: listSoFar
    }
  }


  return l3; 
};