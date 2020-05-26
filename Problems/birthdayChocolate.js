/****************************************************************/
/*Problem: Birthday Chocolate  ********/
/****************************************************************/
/*
-- Summary:
-- Input(s): 
  's' - array of integers (numbers on each of the squares of chocolate); 
  'd' - integer to be matched (birth day); 
  'm' - how many contiguous array elements can be used to match 'd' (birth month);
-- Expected output(s):
  integer denoting the total number of ways that we can portion the array to match 's'.
-- Constraints:
*/
//BRUTE FORCE APPROACH: Time Complexity - O(N^2). Nested for loops.
function birthday(s, d, m) {
  let count = 0;
  // Get array elements by window size
  for(let i = 0; i < s.length; i++) {
    let tempSum = 0;
    for (let j = i; j < i+m; j++) {
      tempSum += s[j];
    }
    if (tempSum === d) { //The window size in this case is m=2, but it needs to adaptable
      count++;
    }
  }
  return count;
}
//TEST CASES
console.log(birthday([2,2,1,3,2],4,2));
console.log(birthday([1,2,1,3,2],4,3));
console.log(birthday([1,1,1,1,1,1],6,5));
console.log(birthday([1,1,1,1,1,1],5,6));
console.log(birthday([1,1,1,1,1,1],5,5));
console.log(birthday([1,0,1,1,1,1],2,3));
console.log(birthday([5,5,1,6,1,1],8,3));