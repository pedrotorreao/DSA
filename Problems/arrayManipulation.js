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
//BETTER APPROACH - Time complexity of O(n):
/* ---- EXPLANATION:
So, after getting confused for some time, I think I got it. The key is to not try to keep track of all the changes that happen to all the array elements (slow), but rather think of the rate of change (as some suggested) and how a given array element varies from the element before it. 
For example, let's take a look at the Test case 0.
Here we have three queries (a b k), using the traditional approach, we got:
1) 1 2 100: arrayA = [0+100, 0+100, 0, 0, 0] = [100, 100, 0, 0, 0]
2) 2 5 100: arrayA = [100, 100+100, 0+100, 0+100, 0+100] = [100, 200, 100, 100, 100]
3) 3 4 100: arrayA = [100, 200, 100+100, 100+100, 0+100] = [100, 200, 200, 200, 100]
The resulting array using the traditional approach with nested loops is: `arrayA = [100,200,200,200,100]`

If we solve using the better approach suggested here, where for each line **a b k**, we add **k** to the position **a** of the array and **-k** to the position ** b+1**, we got the following:
1) 1 2 100: arrayB = [0+100, 0, 0-100, 0, 0] = [100, 0, -100, 0, 0]
2) 2 5 100: arrayB = [100, 0+100, -100, 0, 0] = [100, 100, -100, 0, 0]
3) 3 4 100: arrayB = [100, 100, -100+100, 0, 0-100] = [100, 100, 0, 0, -100]
The resulting array using the traditional approach with nested loops is: `arrayB = [100,100,0,0,-100]`.

Now, comparing both arrays, we can form a conclusion here:

`arrayA = [100,200,200,200,100]` and `arrayB = [100,100,0,0,-100]`

If arrayB[i] = Y > 0: arrayB[i] is greater than arrayB[i-1] by Y. 
If arrayB[i] = 0: arrayB[i] is equal to arrayB[i-1], i.e, there was no change in comparison to arrayB[i-1].
If arrayB[i] = Y < 0: arrayB[i] is less than arrayB[i-1] by Y.

In other words, values different from zero in arrayB, indicates change, i.e., this value changed in comparison to the value before it.
Let's take a look at `arrayB = [100,100,0,0,-100]`:
arrayB[1] = 100: our starting value
arrayB[2] = 100: this value is greater than arrayB[1] by 100, i.e., `arrayB[2] = arrayB[1] + 100 = 200`.
arrayB[3] = 0: there was no change in comparison to the value before it, i.e., `arrayB[3] = arrayB[2] = 200`.
arrayB[4] = 0: there was no change in comparison to the value before it, i.e., `arrayB[4] = arrayB[3] = 200`.
arrayB[5] = -100: this value is less than arrayB[4] by 100, i.e., `arrayB[5] = arrayB[4] - 100 = 100`.

If we observe the resulting array, [100,200,200,200,100], we have the same result as if we had used the traditional approach.

*/
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