/****************************************************************/
/*Tries  ********/
/****************************************************************/
class Node {
  constructor(){
    this.keys = new Map();
    this.endOfWord = false;
  }
}
class Trie {
  constructor() {
    this.root = new Node();
  }
  searchWord(str){
    
  }
  insertWord(str, node = this.root){
    if(!str.length) { node.endOfWord = true; return; }
    if(!node.keys.has(str[0])){
      node.keys.set(str[0], new Node());
    }
    this.insertWord(str.slice(1), node.keys.get(str[0]));
  }
  removeWord(str){

  }
  isOnTree(){
    
  }
  isComplete(){

  }
  print(){

  }
}
const myTrie = new Trie();
myTrie.insertWord('man');
myTrie.insertWord('mind');
myTrie.insertWord('mid');
myTrie.insertWord('apple');
myTrie.insertWord('tree');
myTrie.insertWord('town');
console.log(myTrie);
/*
          root
      -------------
      /     |     \
    m       a      t
  /  \      |    /  \
a     i     p   r    o
|   /  \   |    |     | 
n* n   d*  p    e     w
  |        |    |     |
  d*       e*   e*   n*

*/