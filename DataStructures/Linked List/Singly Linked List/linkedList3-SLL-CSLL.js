/****************************************************************/
/*Problem: Linked List - 3: SLL/CSLL  ********/
/****************************************************************/
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
      //node.next = this.head; //Uncomment to make it circular
      // (Note: browser may crash when dealing with circular references)
      currentNode.next = node;
      this.tail = node;
      //node.next = this.head;
      //this.tail.next = this.head;
    }
    this.length++;
  };

  //Method for inserting a new node at the beginning of the LL (prepend()):
  this.preppend = function (value) {
    let node = new Node(value);
    if (this.head === null) {
      this.head = node;
      this.tail = this.head;
    } else {
      node.next = this.head;
      this.head = node;
    }
    this.length++;
  }

  //Method for inserting a new node anywhere in the LL (insert()):
  this.insert = function (value, index = 0) {
    let node = new Node(value);
    if (index > this.length || index < 0) {
      console.log('ERROR: Out of bounds!');
    } else if (index === 0) {
      this.preppend(value);
    } else if (index === this.length-1) {
      this.append(value);
    } else {
      let currentNode = this.head;
      for (let i = 0; i < index-1; i++) {
        currentNode = currentNode.next;
      }
      node.next = currentNode.next;
      currentNode.next = node;

      this.length++;
    }
  }

  //Method for removing a node (remove()):
  this.remove = function (index) {
    if (index > this.length) {
      //console.log('ERROR: Not a valid index.');
      return 'ERROR: Not a valid index.';
    } else if (index === 0) {
      this.head = this.head.next;
    } else {
      let currentNode = this.head;
      for (let i = 0; i < index-1; i++) {
        currentNode = currentNode.next;
      }
      let node = currentNode.next.next;
      currentNode.next = node;
      this.length--;
    }
  }

  //Method for returning the element at a specific node (elementAtIndex()):
  this.elementAtIndex = function (index) {
    if (index >= this.length) {
      return 'ERROR: Not a valid index.';
    } else {
      let currentNode = this.head;
      for (let i = 0; i < index; i++) {
        currentNode = currentNode.next;
      }
      let node = currentNode.next;

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
    return `ERROR: Element ${value} doesn't exist in this list.`;
  }

  //Method for printing all elements in array formar (printLL()):
  this.printLL = function() {
    const array = [];
    let currentNode = this.head;
    while (currentNode !== null) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    console.log(array);
  };
}
let mySLL = new SLL();

mySLL.append('Joe');
mySLL.append('Jim');
mySLL.preppend('Peter');
mySLL.insert('Wow',0);
mySLL.printLL();
console.log(mySLL.getSize());

mySLL.remove(1);
console.log(mySLL.getSize());
mySLL.printLL();

console.log(mySLL.elementAtIndex(0));
console.log(mySLL.elementAtIndex(2));
console.log(mySLL.indexOfElement('Jim'));
console.log(mySLL.indexOfElement('Peter'));