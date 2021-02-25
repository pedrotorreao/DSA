/****************************************************************/
/*Problem: Queue - Using Arrays  ********/
/****************************************************************/

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