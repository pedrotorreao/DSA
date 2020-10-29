/****************************************************************/
/*Problem: Queue - Using Arrays  ********/
/****************************************************************/
/*
-- Considerations: 
When building queues, it is usually better to use LLs instead of arrays. The reason being that, when using arrays, everytime we have to dequeue an element, we need to shift all indexes, since the first element now is the one that was previouly the second and so on. If we consider an array of n elements, everytime we need to dequeue an element, this is going to have an O(N) time complexity, while if we are using LLs, this is a matter of just setting the first node to be equal to the first.next reference, which has a constant time complexity O(1).
*/
class QueueArray {
  constructor(){
    this.first = null;
    this.last = null;
    this.queue = [];
  }

  peek() {
    if (this.first) {
      console.log('First: ', this.first);
    } else {
      console.log('The queue is Empty!');
    }
  }
  enqueue(value){
    this.queue.push(value);
    this.first = this.queue[0];
    this.last = this.queue[this.queue.length-1];

    this.printQueue();
  }
  dequeue(){
    this.queue.shift();
    if (this.queue.length === 0) {
      this.first = null;
      this.last = null;
    } else {
      this.first = this.queue[0];
      this.last = this.queue[this.queue.length-1];
    }
    this.printQueue();
  }

  getSize() {
    return this.queue.length;
  }
  isEmpty(){
    if (this.first) {
      return false;
    }
    return true;
  }
  printQueue(){
    console.log(this.queue);
  }
}

const myQueue = new QueueArray();

myQueue.enqueue('Joy');
myQueue.peek();
myQueue.enqueue('Matt');
myQueue.peek();
myQueue.enqueue('Pavel');
myQueue.peek();
myQueue.enqueue('Samir');
myQueue.peek();

console.log(myQueue.isEmpty());
console.log(myQueue.getSize());

myQueue.dequeue();
myQueue.peek();
myQueue.dequeue();
myQueue.peek();
myQueue.dequeue();
myQueue.peek();
myQueue.dequeue();
myQueue.peek();

console.log(myQueue.isEmpty());
console.log(myQueue.getSize());