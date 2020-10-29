class CSLL {
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
      next: null
    };
    node.next = this.head;
    this.tail.next = node; 
    this.tail = node; 
    this.length++;
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
let myLinkedList = new CSLL(10);

myLinkedList.append(5);
myLinkedList.append(16);
console.log(myLinkedList);
console.log(myLinkedList.tail.next);