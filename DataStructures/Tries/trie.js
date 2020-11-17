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
  searchPrefix(str, node = this.root){
    /*  
      - Descr.: Print out all the words containing a specific prefix.
      - Input:  It receives the prefix it must look for as input.
      - Output: It stores all the words which begin with that prefix and print them out.
    */

    if(!str.length) { console.log('The prefix string is empty.'); return; }
    let prefix = [];

  }
  insertWord(str, node = this.root){
    /*
      - Descr.: Inserts a new word in the trie.
      - Input:  It receives the word to be inserted as arguments and cheks for repeated keys. 
      - Output: Print out the words on the trie.
    */
    if(!str.length) { node.endOfWord = true; return; }
    if(!node.keys.has(str[0])){
      node.keys.set(str[0], new Node());
    }
    this.insertWord(str.slice(1), node.keys.get(str[0]));
  }
  removeWord(str){
    /*
      - Descr.: Remove a word from the trie.
      - Input:  It receives the word to be removed as argument and checks if this word is on the tree. 
      - Output: Removes the word completely or partially depending on whether part of the word is a prefix to  other words on the trie. Lastly, print out the words on the trie.
    */
  }
  isOnTree(){
    /*
      - Descr.: Checks if a word is on the Trie (Note.: Maybe we can use searchPrefix passing the full word).
      - Input:  It receives the word to be searched as argument. 
      - Output: Returns a boolean indicating whether the word is present or not.
    */
  }
  isComplete(){
    /*
      - Descr.: Checks if a specific word on the Trie is complete or part of a prefix.
      - Input:  It receives the word to be checked for completion as argument. 
      - Output: Returns a boolean indicating whether the word is complete or not.
    */
  }
  print(){
    /*
      - Descr.: Prints out all the words on the trie (Try to print in alphabetical order later).
      - Input:  - 
      - Output: All the words on the trie are logged on the screen.
    */
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