/************************************************************/
/*Problem: Maximum Subarray Sum  ********/
/************************************************************/
// BRUTE FORCE APPROACH: TIME COMPLEXITY - O(N^2)
var maxSubArray = function(nums) {
  let largestSum = Number.NEGATIVE_INFINITY; 
  //NEGATIVE_INFINITY is a static property of the JavaScript Number object. It can be explained as something that is lower than any other number.
  let subArrayStart = 0; //Position where the subarray begins in the case where the if statement is satisfied.
  let subArrayEnd = 0;  //Position where the subarray ends in the case where the if statement is satisfied.

  for (let i = 0; i < nums.length; i++) {//Beginning of the current window
    let tempSum = 0;  //It holds the current subarray sum, from the element at index 'i' to the element at index 'j'.
    //temSum gets reset at each outer interaction as the window moves from left to right.
    for (let j = i; j < nums.length; j++) {//This loop goes through all the array elements from 'i' to 'nums.length - 1'.
      tempSum += nums[j]; //Current subarray sum.
      if (tempSum > largestSum) { //In case the current subarray sum 'tempSum' is greater that the previously stored largest sum 'largestSum', update the largest sum value and the indexes locations.
        largestSum = tempSum;
        subArrayStart = i;
        subArrayEnd = j;
      }
    }
  }
  //console.log(`Maximum subarray starts at index ${subArrayStart} and ends at index ${subArrayEnd}`);
  return largestSum;
};
console.log(maxSubArray([-2,1,-3,4,-1,2,1,-5,4]));
console.log(maxSubArray([1,3,-4,25,-1,1,5,-16,1]));
console.log(maxSubArray([-2,1,-3,-3,-1,2,1,-5,40]));