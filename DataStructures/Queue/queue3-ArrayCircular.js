/*
-- Considerations: 
In case we don't want to shift the elements in the array in order to avoid increasing the time complexity of the code, we have to deal with the problem that, as the array probably has a fixed size, once there is an element in the last position, it is considered as full since we are dealing with queues and new elements are added to the end. A solution to this problem would be to use the concept of a circular queue where we check if there are slots available in the array and, if so, add the new elements in these positions while keeping track of the start and the end of the queue. Despite the concept being simple, implementing it can be quite confusing as you try to keep track of everything. In the end, even though we managed to keep the a constant time complexity O(1), we are better off using LLs.
*/
class QueueArray {
  constructor(){
    this.first = null;
    this.last = null;
    this.queue = new Array(5);
    this.length = 0;
    this.lastPosition = -1;
    this.firstPosition = 0;
  }

  peek() {
    if (this.length) {
      console.log('--First: ', this.first);
      console.log('--Last: ', this.last);
    } else {
      console.log('Queue is Empty!');
    }
  }
  enqueue(value){
    if (this.length === this.queue.length) {
      console.log('Queue is Full!');
      return;
    } else {
      if (this.lastPosition + 1 === this.queue.length) {
        this.lastPosition = 0;
      } else if (this.length === 0) {
        this.firstPosition = 0;
        this.lastPosition = 0;
      } else {
        this.lastPosition++;
      }
    }
    this.queue[this.lastPosition] = value;
    this.first = this.queue[this.firstPosition];
    this.last = this.queue[this.lastPosition];
    
    this.length++;
  }
  dequeue(){
    if (this.length === 0) {
      console.log('Queue is Empty!');
      this.first = null;
      this.last = null;
      return;
    } 
    
    this.queue[this.firstPosition] = null;
    
    if (this.firstPosition + 1 === this.queue.length) {
      this.firstPosition = 0;
    } else {
      this.firstPosition++;
    }
    
    this.first = this.queue[this.firstPosition];
    this.last = this.queue[this.lastPosition];
  
    this.length--;
  }

  getSize() {
    return this.length;
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
console.log('#-------- Enqueue until full -------#');
myQueue.enqueue('Joy');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Matt');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Pavel');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Samir');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Ahmad');
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('#----- Enqueue: overflow error -------#');
myQueue.enqueue('Houssan');
console.log("\n");

console.log('#----------- Dequeue ----------#');
myQueue.dequeue();
myQueue.printQueue();
myQueue.peek(); 

myQueue.dequeue();
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('-------- Enqueue to the recently opened slots   -------');
myQueue.enqueue('Fahim');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Hassam');
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('-------- Enqueue: overflow error  -------');
myQueue.enqueue('Sultan');
console.log("\n");

console.log('-------- Dequeue: should pop out Pavel -------');
myQueue.dequeue();
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('-------- Enqueue to the recently opened slot -------');
myQueue.enqueue('Omar');
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('-------- isEmpty() should return false -------');
console.log(myQueue.isEmpty());
console.log("\n");

console.log('-------- Dequeue everybody -------');
myQueue.dequeue();
myQueue.printQueue();
myQueue.peek(); 

myQueue.dequeue();
myQueue.printQueue();
myQueue.peek();

myQueue.dequeue();
myQueue.printQueue();
myQueue.peek();

myQueue.dequeue();
myQueue.printQueue();
myQueue.peek();

myQueue.dequeue();
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('-------- isEmpty() should return true -------');
console.log(myQueue.isEmpty());
console.log("\n");

console.log('-------- Enqueue just in case -------');
myQueue.enqueue('Abdul');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Pripya');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Tarum');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Fahul');
myQueue.printQueue();
myQueue.peek();

myQueue.enqueue('Hina');
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('-------- Enqueue: overflow error  -------');
myQueue.enqueue('Salim');
console.log("\n");

console.log('-------- Dequeue to open up a slot -------');
myQueue.dequeue();
myQueue.printQueue();
myQueue.peek();
console.log("\n");

console.log('-------- Enqueue: add Salim  -------');
myQueue.enqueue('Salim');
myQueue.printQueue();
myQueue.peek();

console.log(myQueue.getSize());
