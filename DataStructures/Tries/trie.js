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
  removeWord(word, node = this.root, index = 0){
    /*
      - Descr.: Remove a word from the trie.
      - Input:  It receives the word to be removed as argument and checks if this word is on the tree. 
      - Output: Removes the word completely or partially depending on whether part of the word is a prefix to  other words on the trie. Lastly, print out the words on the trie.
        When deleting a string form a Trie, we can consider the cases below:
    */
    let currentCharac = word[index];
    let currentNode = node.keys.get(currentCharac);
    let canWeDeleteThisNode = false;

    //-- CASE#1: The word being removed has the same prefix as some other word in the Trie. In this case, we cannot delete the entire string, but only the independent "members". Ex: mind and mid.
    if(this.hasDependent(currentNode)){
      this.removeWord(word, currentNode, index+1);
      return false;
    }

    //-- CASE#2: The entire word being removed is a prefix of some other word. In this case, we don't delete anything and just set the flag indicating the end of the word being removed as FALSE. Ex.: mid and middle.
    if(index === word.length - 1){
      if(currentNode.keys.size){
        currentNode.endOfWord = false;
        return false;
      }
      else{ 
        node.keys.delete(currentCharac);
        return true;
      }
    }

    //-- CASE#3: Some other word is a prefix of the word we want to remove. As with CASE#1, we only delete the independent "members". Ex.: middle and mid.
    if(currentNode.endOfWord){
      this.removeWord(word, currentNode, index+1);
      return false;
    }

    //-- CASE#4: No one is dependent on the word we want to remove, we just delete it. Ex.: apple.
    canWeDeleteThisNode = this.removeWord(word, currentNode, index+1);

    if(canWeDeleteThisNode){
      node.keys.delete(currentCharac);
    }
  }
  hasDependent(node){
    return ((node.keys.size > 1) ? true : false);
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

myTrie.removeWord('apple');
console.log(myTrie.isOnTree('apple'));
myTrie.printTrie();

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