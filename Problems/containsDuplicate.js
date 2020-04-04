/************************************************************/
/*Problem: Contains Duplicate  ********/
/************************************************************/

/*
// BRUTE FORCE APPROACH: TIME COMPLEXITY O(n*n)
function containsDuplicate(nums) {
  for (let i = 0; i < nums.length; i++) {
    for (let j = 1; j < nums.length; j++) {
        if (nums[j] === nums[i] && j !== i ) {
            return true;
        }
    }
}
return false;
}
*/
/*
// BETTER SOLUTION: TIME COMPLEXITY O(N)
function containsDuplicate(nums) {
  let map = {};
  //loop trough the array and create an object where the properties are the items in the array.
  //If the element was never seen, we insert it to the object with a value 'true', to indicate
  //that it has been seen. In case the element had already been seen, we return 'true'. If at the
  //end of the loop we don't see the same element twice, return 'false'.
  for(let i = 0; i < nums.length; i++) {
    if(!map[nums[i]]) {
      const item = nums[i];
      map[item] = true;
      console.log(map);
    } else {
      return true;
    }
  }
  return false;
}

let array = [1,3,4,5,6,1];
console.log(containsDuplicate(array));
*/