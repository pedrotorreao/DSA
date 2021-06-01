/****************************************************************/
/*Problem: Divisible Sum Pairs  ********/
/****************************************************************/
/*
-- Summary:
  You are given an array of n integers, ar = [0,...,n-1], and a positive integer, k. Find and print the number of (i,j) pairs where i<j and (ar[i] + ar[j]) is divisible by k.
  Ex.: ar = [1,2,3,4,5,6] and k=5. The pairs which meet the criteria are [1,4], [2,3] and [4,6].
-- Input(s):
  n: the integer length of array;
  ar: an array of integers;
  k: the integer to divide the pair sum by.
-- Expected output(s):
  The number of pairs (i,j) that satisfy the criteria.
-- Constraints: 2 <= n <= 100; 1 <= ar[i] <= 100; 1 <= k <= 100.
*/
//BRUTE FORCE APPROACH: Nested for loops - Time Complexity O(n^2)
function divisibleSumPairs(n, k, ar) {
  let pastValues = {};
  let count = 0;

  for (let i = 0; i < n; i++) {
    for (let j = i+1; j < n; j++) {
      if ((ar[i] + ar[j]) % k === 0) {
        count++;
      }
    }
  }
  return count;
}
//TEST CASES:
console.log(divisibleSumPairs(6,5,[1,2,3,4,5,6]));
console.log(divisibleSumPairs(6,3,[1,3,2,6,1,2]));
console.log(divisibleSumPairs(5,2,[1,2,1,5,4]));
console.log(divisibleSumPairs(9,3,[1,1,1,1,1,1,1,1,1]));