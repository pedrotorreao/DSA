/************************************************************/
/*Problem: Staircase  ********/
/************************************************************/
/*
Summary: Write a program that prints a staircase of size n.
Input(s): An integer n.
Expected Output: Print a staircase of size n using # symbols and spaces.Note: The last line must not be preceded by any spaces.
Constraints: 0 < n <= 100
*/
/*
//TIME COMPLEXITY: O(N)
function staircase(n) {
  let spaces = ' ';       //O(1)
  let hashes = '#';       //O(1)
  let index = 1;          //O(1)

  while (index <= n && 0 < n <= 100) {                           //O(N)
    console.log(spaces.repeat(n-index) + hashes.repeat(index));  //O(1)
    index++;  //O(1)
  }
}
staircase(10); //O(1)
*/