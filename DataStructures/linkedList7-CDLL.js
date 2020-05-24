/****************************************************************/
/*Problem: Double Linked List - 7: CDLL (class based) ********/
/****************************************************************/
//Fixed: the problem which I initially thought was due to mistakes on the list construction, it was actually a loop time out on the while loop of the printList() method.

class CDLL {
  constructor(value) {
    this.head = {
      value: value,
      next: null
    };
    this.tail = this.head;
    this.length = 1;
  }
  append(value) {
    const node = {
      value: value,
      prev: null,
      next: null
    };
    node.next = this.head;

    node.prev = this.tail;
    this.tail.next = node;

    this.tail = node;
    this.head.prev = node;

    this.length++;
  }
  //  Due to being a circular list, currentNode is never equal to null, so while loop never ends. This ends up
  //timing out.
  
  // printList() {
  //   const array = [];
  //   let currentNode = this.head;
  //   while (currentNode !== null) {
  //     array.push(currentNode.value);
  //     currentNode = currentNode.next;
  //   }
  //   console.log(array);
  // }
  
  printList() {
    const array = [];
    let currentNode = this.head;
    let index = 0;
    while (index < this.length) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
      index++;
    }
    console.log(array);
  }
}
let myLinkedList = new CDLL(10);

myLinkedList.append(5);
myLinkedList.append(16);
myLinkedList.printList();
console.log(myLinkedList.tail.next);
console.log(myLinkedList.head.prev);