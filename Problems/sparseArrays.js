/****************************************************************/
/*Problem: Sparse Arrays (HR) ********/
/****************************************************************/
/*
-- Summary:
There is a collection of input strings and a collection of query strings. For each query string, determine how many times it occurs in the list of input strings. For example, given input strings=['ab','ab','abc'] and queries=['ab','abc','bc'], we find 2 instances of 'ab', 1 of 'abc' and 0 of 'bc'. For each query, we add an element to our return array, results=[2,1,0].
-- Input(s): 
An array of strings and an array of queries.
-- Expected output(s): 
Return an integer array of the results of all queries in order.
-- Constraints: 
1<=n,q<=1000 / 1<=|strings[i]|,|queries[i]|<=20
*/
function matchingStrings(strings, queries) {
  let map = {};
  let results = [];

  //Go through the strings array mapping them, if an element was seen previously, sum the occurences.
  for (let i = 0; i < strings.length; i++) {
    const item = strings[i];
    if (!map[item]) {
      map[item] = 1;
    } else {
      map[item] += 1;
    }
  }
  // Initialize the results array:
  for (let i = 0; i < queries.length; i++) {
    results[i] = 0;
  }
  // Run each query element against the strings database (map). If a match is found, get how many times that element appears from the map object (map[item]) and assign the value to the results array. If not, assign zero to the results array for that specific query.
  for (let i = 0; i < queries.length; i++) {
    const item = queries[i];
    if(map[item]){
      results[i] = map[item];
    } else {
      results[i] = 0;;
    }
  }
  console.log(results);
}

//TEST CASES:
matchingStrings(['aba','baba','aba','xzxb'], ['aba','xzxb','ab']);
matchingStrings(['ab','ab','abc'], ['ab','abc','bc']);
matchingStrings(['def','de','fgh'], ['de','lmn','fgh']);
matchingStrings(['abcde','sdaklfj','asdjf','na','basdn','sdaklfj','asdjf','na','asdjf','na','basdn','sdaklfj','asdjf'], ['abcde','sdaklfj','asdjf','na','basdn']);