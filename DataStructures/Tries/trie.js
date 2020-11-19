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
  searchPrefix(prefix, node = this.root){
    /*  
      - Descr.: Print out all the words containing a specific prefix.
      - Input:  It receives the prefix it must look for as input.
      - Output: It stores all the words which begin with that prefix and print them out.
    */
    if(!prefix.length || !node.keys.has(prefix[0] || !node.keys.size)) { console.log('Not present.'); return; }
    let prefixMatch = new Array(); //stores all the complete words matching this prefix.
    let str = new String();
    const search = function(node,prefix,str){
      if(node.keys.has(prefix[0])){
          let charac = prefix[0];
          str.concat(charac)
          prefix.slice(1); console.log(str);
          search(node.keys.get(prefix[0]), prefix, str);
        if(node.endOfWord){
          prefixMatch.push(str);
        }
      }
    }; search(this.root,prefix,str);
    console.log(str);
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
  printTrie(){
    /*
      - Descr.: Prints out all the words on the trie (Try to print in alphabetical order later).
      - Input:  - 
      - Output: All the words on the trie are logged on the screen.
    */
    let words = new Array(); //stores all the complete words matching this prefix.
    let str = new String();

    const search = function(node, string){
      for(let letter of node.keys.keys()){
        search(node.keys.get(letter), string.concat(letter));
      }
      if(node.endOfWord){ words.push(string); }
    };
    search(this.root, str);
    return words;
  }
}
const myTrie = new Trie();
myTrie.insertWord('man');
myTrie.insertWord('mind');
myTrie.insertWord('mid');
myTrie.insertWord('apple');
myTrie.insertWord('tree');
myTrie.insertWord('town');
myTrie.insertWord('middle');
console.log(myTrie);
console.log(myTrie.printTrie());
// myTrie.searchPrefix('mi');
/*
          root
      -------------
      /     |     \
    m       a      t
  /  \      |    /  \
a     i     p   r    o
|   /  \   |    |     | 
n* n   d*  p    e     w
  |    |   |    |     |
  d*   d   e*   e*   n*
      |
      l
      |
      e*

*/