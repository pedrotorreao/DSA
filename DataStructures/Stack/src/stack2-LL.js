/****************************************************************/
/*Stack - Using LLs  ********/
/****************************************************************/

class StackLL {
  constructor(){
    this.top = null;
    this.bottom = null;
    this.length = 0;
  }
  peek() {
    console.log(this.top.value);
  }
  push(value){
    const node = {
      value: value,
      next: null
    };
    if (this.top === null) {
      this.top = node;
      this.bottom = this.top;
    } else {
      node.next = this.top;
      this.top = node;
    }
    this.length++;
    this.printStack();
  }
  pop(){
    this.top = this.top.next;
    if (this.top === null) { 
      this.bottom = null;
    }
    this.length--;
    this.printStack();
  }

  getSize() {
    return this.length;
  }
  isEmpty(){
    if (this.top) {
      return false;
    }
    return true;
  }
  printStack(){
    const array = [];
    let currentNode = this.top;
    while(currentNode !== null){
      array.push(currentNode.value);
      currentNode = currentNode.next;
    }
    console.log(array);
  }
}

const myStack = new StackLL();

myStack.push('Google');
myStack.push('Udemy');
myStack.push('Discord');

myStack.pop();

myStack.peek();

console.log('The stack is empty: ', myStack.isEmpty());

myStack.printStack();

console.log(myStack.getSize());

myStack.pop();
myStack.pop();

console.log('The stack is empty: ', myStack.isEmpty());
console.log(myStack.top);
console.log(myStack.bottom);
