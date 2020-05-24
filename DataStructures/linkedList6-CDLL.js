/****************************************************************/
/*Problem: Double Linked List - 6: CDLL (function based) ********/
/****************************************************************/
function CDLL () {
  this.head = null;
  this.tail = null;
  this.length = 0;

  //Method for creating a new node (newNode()):
  let Node = function (value) {
    this.value = value;
    this.prev = null;
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
      let i = 0;
      while (i <= this.length && currentNode.next) {
        currentNode = currentNode.next;
        i++;
      }
      node.next = this.head; //Links node.next to the head element
      currentNode.next = node;
      node.prev = currentNode;
      this.tail = node;
      this.head.prev = node; //Links head.prev to the node element
    }
    this.length++;
  }
  
  this.printDLL = function() {
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
let myCDLL = new CDLL();

myCDLL.append('Joe');
myCDLL.append('Jim');
myCDLL.append('Jon');
myCDLL.printDLL();
console.log(myCDLL.getSize());
console.log(myCDLL.tail.next); //If it works, tail.next should be the head node.
console.log(myCDLL.head.prev); //If it works, head.prev should be the last node.