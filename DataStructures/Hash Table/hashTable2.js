/*******************************************************************/
/*Problem: Hash Table-2: Dealing with collisions using LLs  ********/
/*******************************************************************/
//Simple Single Linked List just for appending values
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
}
// ------------------------------------------------------------------------ //
class HashTable {
  constructor(size){
    this.data = new Array(size);
  }

  _hash(key) {
    let hash = 0;
    for (let i =0; i < key.length; i++){
        hash = (hash + key.charCodeAt(i) * i) % this.data.length
    }
    return hash;
  }
  set (key, value) {
    let address = this._hash(key); //key goes through the hashing function
    
    if (!this.data[address]) { 
      //checks if the current bucket is empty, if so, creates an empty linked list in that data[address]
      this.data[address] = new SLL();
    }
    //pushes the (key, value) pair into the position defined by the hash function. In case the location already has elements, it appends the current (key, value) pair to the SLL.
    this.data[address].append([key, value]);
  }
  
  get (key) {
    const address = this._hash(key); //gets the position where the info is stored through the hashing function

    //gets the first element of the correct bucket which can contain many elements (if collisions happened)
    let currentBucket = this.data[address].head;
    let row = 0; //As the values are entered in the format [key, value], row = 0 gets the key name

    while (currentBucket) {
      //Executes the loop while the current bucket is not null (last "node.next" reference in a LL should point to null):
      if (typeof currentBucket.value[row] === 'string' && currentBucket.value[row] === key) {
        row = 1;
        console.log(`${key}: ${currentBucket.value[row]}`);
        return;
      }
      //If there are more elements occupying the same bucket, it traverses to the next node of the SLL.
      //If not, currentBucket.next = null and we get out of the while loop.
      currentBucket = currentBucket.next; 
    }
  }

  keys(){
    const keysArray = [];

    for (let i = 0; i < this.data.length; i++){
      if(this.data[i]){
        //Gets the key name for the first element of the SLL
        keysArray.push(this.data[i].head.value[0]); 
        //If there are more pairs on the current bucket, traverses the list to the next node
        if (this.data[i].head.next) {
          let nextBucket = this.data[i].head.next;
          while (nextBucket) {
            keysArray.push(nextBucket.value[0]);
            nextBucket = nextBucket.next;
          }
        }
      }
    }
    return keysArray;
  }
}

const myHashTable = new HashTable(10);
myHashTable.set('grapes', 10000);
myHashTable.get('grapes');
myHashTable.set('apples', 9);
myHashTable.get('apples');
myHashTable.set('oranges', 59);
myHashTable.get('oranges');
myHashTable.set('lemons', 125);
myHashTable.get('lemons');
myHashTable.set('letuce', 120);
myHashTable.get('letuce');
myHashTable.set('watermelons', 11);
myHashTable.get('watermelons');
console.log(myHashTable.keys());
console.log(myHashTable.data);