/****************************************************************/
/*Problem: Contacts (HR)  ********/
/****************************************************************/
/*
--  Description: The application must perform two types of operations:
      1.  add name: name is a string denoting a contact name to be stored as a new contact in the application.
      2.  find partial: partial is a string denoting a partial name to search the application for. It must count the number of contacts starting with partial and print the count on a new line.
    Given  sequential add and find operations, perform each operation in order.

--  Input Format: Each line i contains an operation in one of the two forms defined above.

--  Constraints: 1<=n<=10^5 | 1<=|name|<=21 | 1<=|partial|<=21
      It is guaranteed that  and  contain lowercase English letters only and the input doesn't have any duplicate  for the  operation.

-- Output: For each find partial operation, print the number of contact names starting with partial on a new line.
*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Solution 3: The solution below solves the problem and it passes all the test cases in time. This is achieved by keeping a counter on each node so each time a new word is added to the Trie, the nodes which are part of this new word get its counter incremented to indicate that there are 'count' words on the Trie to which this node serves as a prefix, so once it gets to the final character of the prefix we are looking for, it already knows the amount of words which start with this prefix and it doesn't need to look further in the Trie.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

class Node {
  constructor(){
    this.child = [];
    this.count = 0;
  }
}
class Trie {
  constructor(){
    this.root = new Node();
  }
  insertWord(word, node = this.root){
    for(let i = 0; i < word.length; ++i){
      let j = word[i].charCodeAt(0) - 'a'.charCodeAt(0); 
      if(!node.child[j]){ node.child[j] = new Node(); }
      ++node.child[j].count;
      node = node.child[j];
    }
  }
  searchPrefix(prefix, node = this.root){
    for(let i = 0; i < prefix.length; ++i){
      let j = prefix[i].charCodeAt(0) - 'a'.charCodeAt(0);
      if(!node.child[j]){ return 0; }
      node = node.child[j];
    }
    return node.count;
  }
}
function contacts(queries) {
    let wordCount = []; 
    let count = 0;
    let contactsTrie = new Trie();
    
    queries.forEach(input => {
        if(input[0] === 'add'){
            contactsTrie.insertWord(input[1]);
        }
        else if(input[0] === 'find'){
            count = contactsTrie.searchPrefix(input[1]);
            wordCount.push(count);
        }  
    });
    
    return wordCount;
}
//TEST CASES:
// (1) -  Expected Output: [3,0]. 
//        Explanation:  ['find','hac'] => 3, ['find','hak'] => 0
let queries1 = [['add','hack'],['add','hackerrank'],['add','hacker'],['find','hac'],['find','hak']];
console.log(contacts(queries1));

// (2) -  Expected Output: [3,2,2]. 
//        Explanation:  ['find','mi'] => 3, ['find','ap'] => 2, ['find','t'] => 2
let queries2 = [['add','man'],['add','mind'],['add','mid'],['add','middle'],['add','apple'],['add','app'],     ['add','tree'],['add','town'],['find','mi'],['find','ap'],['find','t']];
console.log(contacts(queries2));

// (3) -  Expected Output: [4,2,2,3,5,1,1]. 
//        Explanation:  ['find','mi'] => 4, ['find','ap'] => 2, ['find','t'] => 2,['find','tr'] => 3,
//                      ['find','t'] => 5, ['find','man'] => 1, ['find','apple'] => 1
let queries3 = [['add','man'],['add','mind'],['add','mid'],['add','middle'],['add','apple'],['add','app'],     ['add','tree'],['add','town'],['add','mindless'],['find','mi'],['find','ap'],['find','t'],['add','tower'],['add','trip'],['add','troup'],['find','tr'],['find','t'],['find','man'],['find','apple']];
console.log(contacts(queries3));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Solution 1: The solution below solves the problem, but it takes too long (Runtime errors). This is probably due to the recursive calls inside the foor loop in the searchPrefix() method.
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
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
    insertWord(str, node = this.root){
        if(!str.length) { node.endOfWord = true; return; }
        if(!node.keys.has(str[0])){
          node.keys.set(str[0], new Node());
        }
        this.insertWord(str.slice(1), node.keys.get(str[0]));
    }

    searchPrefix(prefix, node = this.root, index = 0){
        let prefixed = 0;
      
        while(index < prefix.length){
          node = node.keys.get(prefix[index]);
          ++index;
        }
        let searchHelper = function(node,pref = 0){
          if(!node){return prefixed;}
          if(node && node.endOfWord){ ++prefixed; }

          for(let charac of node.keys.keys()){
              searchHelper(node.keys.get(charac), prefixed);
          }
          return prefixed;
        };
        prefixed = searchHelper(node);
        
        return prefixed;
    }
    
}
*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
Solution 2: The solution below also seems to solve the problem since is passed the all the tests, but it also takes too long (Runtime errors).
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*
class Node {
  constructor(){
    this.keys = new Map();
    this.endOfWord = false;
    this.count = 0;
  }
}
class Trie {
    constructor() {
        this.root = new Node();
    }
    insertWord(str, node = this.root){
        if(!str.length) { node.endOfWord = true; return; }
        if(!node.keys.has(str[0])){
          node.keys.set(str[0], new Node());
        }
        ++node.count;
        this.insertWord(str.slice(1), node.keys.get(str[0]));
    }

    searchPrefix(prefix, node = this.root, index = 0){
        let prefixed = 0;
        
        while(index < prefix.length){
          node = node.keys.get(prefix[index]);
          if(index === prefix.length-1 && node && node.endOfWord){++prefixed;} //in case prefix = word
          ++index;
        } 
        return (node ? (node.count+prefixed) : 0);
    }
    
}
*/