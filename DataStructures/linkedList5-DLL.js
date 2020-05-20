/****************************************************************/
/*Problem: Double Linked List - 5 ********/
/****************************************************************/
function DLL () {
  this.head = null;
  this.tail = null;
  this.length = 0;

  //Method for creating a new node (newNode()):
  let Node = function (value) {
    this.value = value;
    this.prev = null;
    this.next = null
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
      currentNode.next = node;
      node.prev = currentNode;
      this.tail = node;
    }
    this.length++;
  }

  //Method for inserting a new node at the beginning of the LL (prepend()):
  this.prepend = function (value) {
    let node = new Node(value);
    if (this.head === null) {
      this.head = node;
      this.tail = this.head;
    } else {
      node.next = this.head;
      this.head.prev = node;
      this.head = node;
    }
    this.length++;
  }
  //Method for inserting a new node anywhere in the LL (insert()):
  this.insert = function (value, index = 0) {
    if (index <= 0) {
      this.prepend(value);
    } else if (index >= this.length) {
      this.append(value);
    } else {
      let node = new Node(value);
      let currentNode = this.head;
      for (let i = 0; i < index-1; i++) {
        currentNode = currentNode.next;
      }
      node.prev = currentNode;
      node.next = currentNode.next;
      currentNode.next = node;
      node.next.prev = node;
      this.length++;
    }
  }

  //Method for removing a node (remove()):
  this.remove = function (index) {
    if (index > this.length) {
      this.tail = this.tail.prev;
      this.tail.next = null;
    } else if (index <= 0) {
      this.head = this.head.next;
      this.head.prev = null;
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

  //Method for returning the element at a specific node (elementAtIndex()):
  this.elementAtIndex = function (index) {
    if (index >= this.length) {
      return this.tail.value;
    } else if (index <= 0) {
      return this.head.value;
    } else {
      let currentNode = this.head;
      for (let i = 0; i < index; i++) {
        currentNode = currentNode.next;
      }
      return currentNode.value;
    }
  }

  //Method for returning the index of an specific element (1st encounter) (indexOfElement()):
  this.indexOfElement = function (value) {
    let currentNode = this.head;
    for (let i = 0; i < this.length; i++) {
      if (currentNode.value === value) {
        return i;
      }
      currentNode = currentNode.next;
    }
    return 'Not found!';
  }

  //Method for printing all elements in array format (printLL()):
  this.printDLL = function() {
    const array = [];
    let currentNode = this.head;
    while (currentNode !== null) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    console.log(array);
  }

}
let myDLL = new DLL();

myDLL.append('Joe');
myDLL.append('Jim');
myDLL.append('Jon');
myDLL.printDLL();
console.log(myDLL.getSize());

myDLL.prepend('Pam');
myDLL.prepend('Peter');
myDLL.prepend('Phill');
myDLL.printDLL();
console.log(myDLL.getSize());

myDLL.insert('Wow',0);
myDLL.insert('AAAA',-2);
myDLL.insert('May',11);
myDLL.insert('Hello',5);
myDLL.printDLL();
console.log(myDLL.getSize());

myDLL.remove(-2);
myDLL.remove(0);
myDLL.remove(15);
myDLL.remove(4);
myDLL.printDLL();
console.log(myDLL.getSize());

console.log(myDLL.elementAtIndex(0));
console.log(myDLL.elementAtIndex(2));
console.log(myDLL.elementAtIndex(10));
console.log(myDLL.elementAtIndex(4));

console.log(myDLL.indexOfElement('Phill'));
console.log(myDLL.indexOfElement('Pam'));
console.log(myDLL.indexOfElement('Hello'));
console.log(myDLL.indexOfElement('Jon'));
console.log(myDLL.indexOfElement('Paul'));