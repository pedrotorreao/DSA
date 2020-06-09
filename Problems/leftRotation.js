/****************************************************************/
/*Problem: Left rotation (HR)  ********/
/****************************************************************/
/*
-- Summary:
A left rotation operation on an array of size n shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1,2,3,4,5], then the array would become [3,4,5,1,2]. Given an array of n integers and a number, d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.
-- Input(s):
First line contains two space-separated integers denoting the respective values of n (the number of integers) and d (the number of left rotations you must perform). The second line contains n space-separated integers describing the respective elements of the array's initial state.
-- Expected output(s):
Print a single line of n space-separated integers denoting the final state of the array after performing d left rotations.
-- Constraints:
1<=n<=10^5 | 1<=d<=10^5 | 1<=ai<=10^5
*/
function leftRotation (n,d,a) {
  let endArray = [];
  let modArray = [];

  //Gets elements to be shifted:
  endArray = a.slice(0,d); 
  //Removes elements to be shifted from original array and concatenates them at the end:
  endArray = a.splice(d).concat(endArray); 
  //Converts array to string:
  endArray = endArray.toString();
  //Replaces the commas with spaces:
  endArray = endArray.split(',').join(' ');

  return endArray;
};
console.log(leftRotation(5,2,[1,2,3,4,5]));
console.log(leftRotation(5,4,[1,2,3,4,5]));
console.log(leftRotation(5,1,[1,2,3,4,5]));