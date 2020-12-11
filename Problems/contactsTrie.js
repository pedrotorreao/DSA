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
    hasDependent(node){
        return ((node.keys.size > 1) ? true : false);
    }
    searchPrefix(prefix, node = this.root, index = 0){
        let currentCharac = prefix[0];
        let currentNode = node.keys.get(currentCharac);
        let prefixed = 0;
      
        while(index < prefix.length){
          node = node.keys.get(prefix[index]);
          ++index;
        }
      
        if(!currentNode){return 0;}
        
        let searchHelper = function(node,pref = 0){
          if(!node){return prefixed;}
          if(node && node.endOfWord){ ++prefixed; }
          for(let charac of node.keys.keys()){
              console.log(`${charac} : ${prefixed} : ${node.endOfWord}`)
              searchHelper(node.keys.get(charac), prefixed);
          }
          return prefixed;
        };
        prefixed = searchHelper(node);
        
        return prefixed;
    }
    
}
//--------------------------------------------------------------
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

let queries = [['add','hack'],['add','hackerrank'],['add','hacker'],['find','hac'],['find','hak']];

console.log(contacts(queries));