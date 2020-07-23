/****************************************************************/
/*Problem: Maximum Element (HR)  ********/
/****************************************************************/
/*
-- Summary:
You have an empty sequence, and you will be given N queries. Each query is one of these three types:
1 x - Push the element x into the stack.
2   - Delete the element present at the top of the stack.
3   - Print the maximum element in the stack.
-- Input(s):
The first line of input contains an integer, N. The next N lines each contain an above mentioned query. (It is guaranteed that each query is valid.)
-- Expected output(s):
For each type 3 query, print the maximum element in the stack on a new line.
-- Constraints:
1<=N<=10^5| 1<=x<=10^9 |1<=type<=3
*/
function processData(input) {
  let stack = [0]; //initialize the stack with a value zero
  let inputStr = input.split("\n"); //split the input sequence 
  inputStr.shift(); //remove the first element which indicates the size of the sequence

  for(let i = 0; i < inputStr.length; i++) {
    //use destructuring to break the queries into pairs where query is the type (1,2 or 3), and value is the value to be pushe dinto the stack, if any. Also, convert the characters back into numbers.
    let [query,value] = inputStr[i].split(' ').map(x => parseInt(x));

    let top = stack[stack.length - 1]; //sets the top (max value) to the last element of the stack (first out)
    switch(query) {
      case 1: stack.push((value > top) ? value : top); break; //keeps te max value always on the top of the stack
      case 2: stack.pop(); break;
      case 3: console.log(top); break;
    }
  }
}