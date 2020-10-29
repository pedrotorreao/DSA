/****************************************************************/
/*Problem: Stack - Using arrays  ********/
/****************************************************************/
/*
Considerations: Arrays are usually created with fixed size (static arrays), so it may not be possible to increase its size which can limit the stack capabilities, and even when it is possible to increase its size (dynamic arrays), it usually means doubling its size which may not be very memory efficient. LLs, on the other hand, are neither created with fixed size nor stored in contiguous memory spaces, so its size can be increased without problems. However, it is worth mentioning that LLs use an extra variable which stores the reference to the next node. On the other hand, arrays can take advantage of cache locality, which means that as arrays are stored contiguously in memory, large chunks of them will be loaded into the cache upon first access. This makes it comparatively quick to access future elements of the array. Linked lists, as said previously, aren't necessarily in contiguous blocks of memory, which could lead to more cache misses, which increases the time it takes to access them. Ex.: If we wanted to loop through an array, the first access would require us to go to memory to retrieve it (a very slow operation in CPU cycles). However, after the first access the rest of the array would be in the cache, and subsequent accesses would be much quicker. With the linked list, the first access would also require us to go to memory. However, as the processor will cache the memory directly surrounding this location, this doesn't actually means that it will capture any of the other elements of the list, which means that when we try to access the next element in the list, we will have to go to memory again.
*/
class StackArray {
  constructor(){
    this.top = null;
    this.bottom = null;
    this.stack = [];
  }

  peek() {
    console.log(this.top);
  }
  push(value){
    this.stack.push(value);
    this.top = this.stack[this.stack.length-1];
    this.bottom = this.stack[0];

    this.printStack();
  }
  pop(){
    this.stack.pop();
    if (this.stack.length === 0) {
      this.top = null;
      this.bottom = null;
    } else {
      this.top = this.stack[this.stack.length-1];
      this.bottom = this.stack[0];
    }
    this.printStack();
  }

  getSize() {
    return this.stack.length;
  }
  isEmpty(){
    if (this.top) {
      return false;
    }
    return true;
  }
  printStack(){
    console.log(this.stack);
  }
}

const myStack = new StackArray();

myStack.push('Google');
myStack.push('Udemy');
myStack.push('Discord');
console.log(myStack.getSize());

myStack.pop();
console.log(myStack.getSize());

myStack.peek();

console.log('The stack is empty: ', myStack.isEmpty());

myStack.printStack();

myStack.pop();
myStack.pop();

console.log('The stack is empty: ', myStack.isEmpty());
console.log(myStack.top);
console.log(myStack.bottom);
console.log(myStack.getSize());