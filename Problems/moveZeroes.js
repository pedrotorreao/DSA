/************************************************************/
/*Problem: Move Zeroes  ********/
/************************************************************/
/*
Summary:  Given an array, write a function to move all 0's to the end while maintaining the relative order of the array.
          Also, do not make a copy of the array, if needed, reverse the array in place.
Input:  Array of integers. Ex.: [0,1,0,3,12]
Output: Input array with zeros (if present) shifted to the end.
Constraints:  Don't make a copy of the array.
*/
//BRUTE FORCE APPROACH: TIME COMPLEXITY - O(N)
/*
var moveZeroes = function(nums) {
  let count = 0;
  let index = 0;
  let size = nums.length;

  while (count < size) {
    if (nums[index] === 0) { 
      nums.splice(index,1); 
      nums.push(0);
      //count++;
      //console.log(nums);              
    } else {
      index++; 
    }
    count++;
  }
  return nums;
};
console.log(moveZeroes([0,1,0,3,12]));
console.log(moveZeroes([1,0,0,0,0,1,0,3,0,4,5,88,9,12]));
console.log(moveZeroes([0,0,0,0,0,1]));
*/