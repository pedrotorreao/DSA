/************************************************************/
/*Problem: Two Sum - Google Interview Question ********/
/************************************************************/
/*
Given an array of numbers, check if there is a pair of numbers which
sum match a given number.
- You cannot repeat the same number on the same index;
- There may be repeated numbers on the array;
- You can assume that the array is ordered;
- You can consider the array as having only integer numbers;
- Negative numbers may happen
INPUTS: 
- A collection of numbers (array)
- Value to which the array elements must add to
OUTPUTS:
- The array indexes of the elements whose sum match the value
*/
/*
//BRUTE FORCE APPROACH: O(n*n) complexity
function containsSum (array, value) {
  for (let i = 0; i < array.length; i++) {
    for (let j = 1; j <= array.length; j++) {
      if ((i !== j) && (array[i] + array[j] === value)) {
        return [i,j];
        //return (`index ${i}: ${array[i]} \nindex ${j}: ${array[j]} `);
      }
    }
  }
  return 'sum not present in array!';
}
console.log(containsSum([1,2,4,4],8));
*/

//IMPROVED APPROACH 1: O(n) complexity
//This solution depends on the array being always sorted
/*
function containsSum2 (array, value) {
  let low = 0;
  let high = array.length - 1;
  console.log(low);
  console.log(high);

  for (let i = 0; i < array.length; i++) {
    if ((array[high] + array[high - 1] < value)||(array[low] + array[low + 1] > value)) {
      return 'not found :(';
    }else if (array[low] + array[high] === value) {
      return [low,high];
    } else if (array[low] + array[high] > value) {
      high--;
    } else if (array[low] + array[high] < value){
      low++;
    }
  }
}
console.log(containsSum2 ([1,2,6,7,8,11,17],3));
*/

//IMPROVED SOLUTION 2:

const twoSum = (nums, total) => {
  // Keep track of previous array values
  const previousValues = {};

  for (let i = 0; i < nums.length; i++) {
    // What previous value needs to exist for
    // us to have found our solution?
    const complement = total - nums[i];

    if (previousValues[complement]) {
      console.log(previousValues);
      //Return the values that sum to target
      //return [complement, nums[i]];
      return [nums.indexOf(complement), i];
    }

    // This current array item now becomes
    // a previous value
    previousValues[nums[i]] = true;
  }
};

console.log(twoSum([1, 2, 3], 4)); // [1, 3]
console.log(twoSum([3, 9, 12, 20], 21)); // [9, 12]
