/****************************************************************/
/*Problem: Array Manipulation (HR)  ********/
/****************************************************************/
/*
-- Summary:
Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each of the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in your array.
-- Input(s):
The size of the array (n) and a 2D array in the format a,b,k, where a and b are the indices and k is the number to be added to the array.
-- Expected output(s):
The maximum value in your array.
-- Constraints:
*/
//BRUTE FORCE APPROACH - Time complexity of O(n*m). The solution is correct and it works well for small datasets. However, for large datasets it may time out.
/*
function arrayManipulation(n, queries) {
  let array = [];
  let biggest = Number.NEGATIVE_INFINITY;
  //Initialize the array with 0's:
  for (let i = 0; i < n; i++) {
    array[i] = 0;
  }
  for (let i = 0; i < queries.length; i++) { 
    for (let j = queries[i][0]-1; j < queries[i][1]; j++) {
      array[j] += queries[i][2];
    }
    //console.log(array);
  }
  for (let i = 0; i < array.length; i++) {
    if (array[i] > biggest) {
      biggest = array[i];
    }
  }
  console.log(biggest);
}
arrayManipulation(5, [[1,2,100],[2,5,100],[3,4,100]]);
arrayManipulation(10, [[1,5,3],[4,8,7],[6,9,1]]);
*/
//O(n) approach, instead of trying to keep track of all the operations and all the elements that are changing, we can focus only on the endpoints and use them to keep track of the changes.
function arrayManipulation(n, queries) {
  let array = [];
  let biggest = 0;
  let sum = 0;
  let a = 0;
  let b = 0;

  //Initialize the array with 0's:
  for (let i = 0; i < n; i++) {
    array[i] = 0;
  }

  for (let i = 0; i < queries.length; i++) {
    a = queries[i][0];
    b = queries[i][1];
    array[a-1] += queries[i][2];
    array[b] -= queries[i][2];
  }

  for (let i = 0; i < array.length; i++) {
    sum += array[i];
    if (sum > biggest) {
      biggest = sum;
    }
  }
  console.log(biggest);
}
arrayManipulation(5, [[1,2,100],[2,5,100],[3,4,100]]);
arrayManipulation(10, [[1,5,3],[4,8,7],[6,9,1]]);