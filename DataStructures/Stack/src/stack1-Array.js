/****************************************************************/
/*Stack - Using arrays  ********/
/****************************************************************/

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