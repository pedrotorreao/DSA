/****************************************************************/
/*Queue - Using LLs  ********/
/****************************************************************/

class QueueLL {
  constructor(){
    this.first = null;
    this.last = null;
    this.length = 0;
  }
  peek() {
    if (this.first) {
      console.log('First: ', this.first.value);
    } else {
      console.log('The queue is Empty!');
    }
  }
  enqueue(value){
    const node = {
      value: value,
      next: null
    };
    if (this.first === null && this.length === 0) {
      this.first = node;
      this.last = node;
    } else {
      this.last.next = node;
      this.last = node;
    }
    this.length++;
    this.printQueue();
  }
  dequeue(){
    this.first = this.first.next;
    if (this.first === null) {
      this.last = null;
    }
    this.length--;
    this.printQueue();
  }
  getsize(){
    return this.length;
  }
  isEmpty(){
    if (this.length === 0 && this.first) {
      return false;
    }
    return true;
  }
  printQueue(){
    const array = [];
    let currentNode = this.first;
    while(currentNode !== null) {
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    console.log(array);
  }
}

const myQueue = new QueueLL();

myQueue.enqueue('Joy');
myQueue.peek();
myQueue.enqueue('Matt');
myQueue.peek();
myQueue.enqueue('Pavel');
myQueue.peek();
myQueue.enqueue('Samir');
myQueue.peek();

console.log(myQueue.getsize());

myQueue.dequeue();
myQueue.peek();
myQueue.dequeue();
myQueue.peek();
myQueue.dequeue();
myQueue.peek();
myQueue.dequeue();
myQueue.peek();
