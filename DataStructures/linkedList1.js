/************************************************************/
/*Problem: Linked List - 1  ********/
/************************************************************/
// Create the below linked list:
// myLinkedList = {
//   head: {
//     value: 10
//     next: {
//       value: 5
//       next: {
//         value: 16
//         next: null
//       }
//     }
//   }
// };

class LinkedList {
  constructor(value) {
    this.head = {
      value: value,
      next: null
    };
    this.tail = this.head; //assigning by reference
    this.length = 1;
  }
  append(value) {
    const node = {
      value: value,
      next: null
    };
    //tail.next and head.next are references to the same value (aka shared value).
    this.tail.next = node; //updates the 'next' value in the head object to be equal to the new node object (assign by reference).
    this.tail = node; //updates the node object.
    this.length++;
  }
  prepend(value) {
    const first = {
      value: value,
      next: null
    };
    first.next = this.head;
    this.head = first;
    this.length++;
  }
}

let myLinkedList = new LinkedList(10);

myLinkedList.append(5);
myLinkedList.append(16);
myLinkedList.prepend(1);
myLinkedList.prepend(8);
console.log(myLinkedList);

//JavaScript -- Variable Assignment
// 1) Primitive values (numbers, strings, undefined, boolean, null): assign by value,
// 2) Compound values (arrays and objects): assign by reference.
// 3) The references in JavaScript only point at contained values and NOT at other variables, or references.