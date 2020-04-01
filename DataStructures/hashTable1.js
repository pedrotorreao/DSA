/************************************************************/
/*Problem: Hash Table - 1  ********/
/************************************************************/

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
    let address = this._hash(key); //makes the key goes through the hashing function
    
    if (!this.data[address]) {
      this.data[address] = []; //creates an empty array in the hashed location
    }
    this.data[address].push([key, value]); //pushes the (key, value) pair into the position defined by the hash function
    //return this.data;
  }
  
  get (key) {
    const address = this._hash(key); //gets the position where the info is stored through the hashing function
    const currentBucket = this.data[address]; //gets the correct bucket which can contain many elements (if a collision occurs)
    let row = 0;
    let col = 0;
    //Initially this doesn't have an O(n) complexity because the access is imediate due to the program already knowing where to look.
    //However, complexity may increase depending on the number of hash collisions.
    while ((currentBucket[row][col]) && (typeof currentBucket[row][col] === 'string')){
      if (currentBucket[row][col] === key) {
        col = 1;
        console.log(currentBucket[row][col]);
        return;
      } else {
        row++;
      }
    }
  }

  keys(){
    const keysArray = [];
    //console.log(this.data.length);
    for (let i = 0; i < this.data.length; i++){
      if(this.data[i]){
        keysArray.push(this.data[i][0][0]); 
        //not the best solution because since it doesn't account for the colisions, it may end up just getting the firs element.
        //accounting for the collisions may end up increasing complexity to O(n*n). Try later!!!!
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
console.log(myHashTable.keys());
