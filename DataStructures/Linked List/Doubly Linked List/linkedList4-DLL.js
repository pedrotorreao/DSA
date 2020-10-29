/****************************************************************/
/*Problem: Double Linked List - 4 ********/
/****************************************************************/
class DoubleLinkedList {
  constructor(value) {
    this.head = {
      value: value,
      prev: null,
      next: null
    };
    this.tail = this.head; //assigning by reference
    this.length = 1;
  }
  append(value) {
    let node = {
      value: value,
      prev: null,
      next: null
    }; 

    node.prev = this.tail;
    this.tail.next = node;
    this.tail = node;

    this.length++;
  }
  prepend(value) {
    let node = {
      value: value,
      prev: null,
      next: null
    };

    node.next = this.head;
    this.head.prev = node;
    this.head = node;

    this.length++;
  }
  insert(value, index = 0) {
    if (index <= 0) {
      this.prepend(value);
    } else if (index >= this.length) {
      this.append(value);
    } else {
      let node = {
        value: value,
        prev: null,
        next: null
      };
      let currentNode = this.head;
      for (let i = 0; i < index-1; i++) {
        currentNode = currentNode.next;
      }
      node.next = currentNode.next;
      node.prev = currentNode;
      currentNode.next = node;
      node.next.prev = node;

      this.length++;
    }
  }

  remove(index) {
    if (index <= 0) {
      this.head = this.head.next;
      this.head.prev = null;
    } else if (index >= this.length) {
      this.tail = this.tail.prev;
      this.tail.next = null;
    } else {
      let currentNode = this.head;
      for (let i = 0; i < index-1; i++) {
        currentNode = currentNode.next;
      }
      currentNode.next = currentNode.next.next;
      currentNode.next.prev = currentNode;
    }

    this.length--;
  }

  printList() {
    const array = [];
    let currentNode = this.head;
    while (currentNode) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    console.log(array);
  }
}

let myLinkedList = new DoubleLinkedList(10);

myLinkedList.append(5);
myLinkedList.append(16);
myLinkedList.printList();
console.log(myLinkedList);

myLinkedList.prepend(1);
myLinkedList.prepend(8);
myLinkedList.printList();
console.log(myLinkedList);

myLinkedList.insert(11,10); // index > length
myLinkedList.insert(0,-5);  // index < 0
myLinkedList.insert(0,0);   // index = 0
myLinkedList.insert(23);    // no index, default parameters
console.log(myLinkedList);
myLinkedList.printList();

myLinkedList.remove(0); // index = 0
myLinkedList.remove(-5);// index < 0
myLinkedList.remove(3); // 0 < index < length
myLinkedList.remove(10);// index > length
myLinkedList.printList();