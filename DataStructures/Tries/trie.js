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
  buildList(node=this.root, string=new String(), arr=new Array()){
    for(let charac of node.keys.keys()){
      this.buildList(node.keys.get(charac), string.concat(charac), arr);
    }
    if(node.endOfWord){ 
      arr.push(string); 
    }

    return arr;
  }
  searchPrefix(prefix){
    /*  
      - Descr.: Print out all the words containing a specific prefix.
      - Input:  It receives the prefix it must look for as input.
      - Output: It stores all the words which begin with that prefix and print them out.
    */
    let prefixMatch = new Array();
    let allWords = this.buildList();

    if(!allWords.length){ console.log('Trie is empty'); return;}

    allWords.forEach(element => {
      if(element.includes(prefix)){ prefixMatch.push(element); }
    });

    if(prefixMatch.length){ 
      console.log(prefixMatch); return prefixMatch; 
    }
    console.log(`No match for the prefix/word "${prefix}".`);
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
  isOnTree(str){
    /*
      - Descr.: Checks if a word is on the Trie.
      - Input:  It receives the word to be searched as argument. 
      - Output: Returns a boolean indicating whether the word is present or not.
    */
    return ((this.buildList().includes(str)) ? true : false);
  }
  printTrie(){
    /*
      - Descr.: Prints out all the words on the trie (Try to print in alphabetical order later).
      - Input:  - 
      - Output: All the words on the trie are logged on the screen.
    */
    let allWords = this.buildList();

    if(allWords.length){ 
      console.log(allWords); return; 
    }
    console.log('Trie is empty');
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
myTrie.insertWord('app');

myTrie.printTrie();

myTrie.searchPrefix('mi');
myTrie.searchPrefix('app');
myTrie.searchPrefix('au');

console.log(myTrie.isOnTree('man'));
console.log(myTrie.isOnTree('tow'));

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
  |    |   |    |     |
  d*   d   e*   e*   n*
      |
      l
      |
      e*

*/