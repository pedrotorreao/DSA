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
    const first = { //It could be a good to create a generic method/class for the creation of new nodes
      value: value,
      next: null
    };
    first.next = this.head;
    this.head = first;
    this.length++;
  }
  insert(value, index = 1) { //If no argument is passed as index, assume zero value
    if (index <= 1) {
      this.prepend(value);
    } else if (index >= this.length) {
      this.append(value);
    } else {
      const node = {
        value: value,
        next: null
      };
      let currentNode = this.head;
      for (let i = 1; i < index-1; i++) {
        currentNode = currentNode.next; //Setting the temporary node to be equal to the 'before node' where we must insert the new element
      }
      node.next = currentNode.next; //Linking the new node to the next node
      currentNode.next = node; //Finish the insertion by linking the 'previous node' to our new node
      this.length++;
    }
  }

  remove (index) {
    if (index === 0) {
      this.head = this.head.next;
    } else {
      let currentNode = this.head;
      for (let i = 0; i < index-1; i++) {
      currentNode = currentNode.next;
      }
    
      let node = currentNode.next.next; //Skips the node to be deleted
      currentNode.next = node; // Updates current node 'next reference' to newly created 'node' 
    }
  }

  printList() {
    const array = [];
    let currentNode = this.head;
    while (currentNode !== null) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    console.log(array);
  }
}

let myLinkedList = new LinkedList(10);

myLinkedList.append(5);
myLinkedList.append(16);
myLinkedList.printList();

myLinkedList.prepend(1);
myLinkedList.prepend(8);
myLinkedList.printList();

myLinkedList.insert(0,3);
myLinkedList.insert(0,5);
myLinkedList.insert(0,1);
myLinkedList.insert(0,0);
myLinkedList.insert(23);
myLinkedList.printList();

myLinkedList.remove(8);
myLinkedList.printList();
//console.log(myLinkedList);

//JavaScript -- Variable Assignment
// 1) Primitive values (numbers, strings, undefined, boolean, null): assign by value,
// 2) Compound values (arrays and objects): assign by reference.
// 3) The references in JavaScript only point at contained values and NOT at other variables, or references.