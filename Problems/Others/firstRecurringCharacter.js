/*************************************************************************************************************/
/*Problem: First Recurring Character - Similar to the 'Contains Duplicate' problem solved previously  ********/
/*************************************************************************************************************/

// BETTER SOLUTION: TIME COMPLEXITY O(N)
function firstRecurringCharacter(nums) {
  let map = {};
  //loop trough the array and create an object where the properties are the items in the array.
  //If the element was never seen, we insert it to the object with a value 'true', to indicate
  //that it has been seen. In case the element had already been seen, we return 'true'. If at the
  //end of the loop we don't see the same element twice, return 'false'.
  for (let i = 0; i < nums.length; i++) {
    if (!map[nums[i]]) {
      const item = nums[i];
      map[item] = true;
      //console.log(map);
    } else {
      //return true;
      return nums[i];
    }
  }
  //return false;
  return "undefined";
}

let array1 = [1, 3, 4, 5, 6, 0];
console.log(firstRecurringCharacter(array1));
let array2 = [2, 5, 1, 2, 3, 5, 1, 2, 4];
console.log(firstRecurringCharacter(array2));
let array3 = [2, 1, 1, 2, 3, 5, 1, 2, 4];
console.log(firstRecurringCharacter(array3));
let array4 = [2, 3, 4, 5];
console.log(firstRecurringCharacter(array4));
let array5 = [2, 5, 5, 2, 3, 5, 1, 2, 4];
console.log(firstRecurringCharacter(array5));
