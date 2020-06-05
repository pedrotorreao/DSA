/****************************************************************/
/*Problem: Queue - Using LLs  ********/
/****************************************************************/
/*
-- Considerations: 
When building queues, it is usually better to use LLs instead of arrays. The reason being that, when using arrays, everytime we have to dequeue an element, we need to shift all indexes, since the first element now is the one that was previouly the second and so on. If we consider an array of n elements, everytime we need to dequeue an element, this is going to have an O(N) time complexity, while if we are using LLs, this is a matter of just setting the first node to be equal to the first.next reference, which has a constant time complexity O(1).
*/

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
