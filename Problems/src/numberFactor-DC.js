/****************************************************************/
/* Problem: Number Factor - Divide & Conquer Approach********/
/****************************************************************/
/*
-- Summary:
Given an integer N, determine how many combinations are possible to make
using the numbers {1,3,4} to reach N. Example:
  N = 4: [1,1,1,1] [1,3] [3,1] [4] --> 4 possible combinations
-- Input(s):
N: integer to be reached
-- Expected output(s):
Print the number of combinations possible.
*/
function nf(n) {
  if (n < 1) return 0; // base case
  if (n === 1 || n === 2) return 1;
  if (n === 3) return 2;
  if (n === 4) return 4;

  return nf(n - 1) + nf(n - 3) + nf(n - 4);
}

// Test cases:
/* 1. expected output: 6 */
console.log("Combinations possible for n = 5: ", nf(5));

/* 2. expected output: 9 */
console.log("Combinations possible for n = 6: ", nf(6));

/* 3. expected output: 15 */
console.log("Combinations possible for n = 7: ", nf(7));

/* 4. expected output: 25 */
console.log("Combinations possible for n = 8: ", nf(8));

/* 5. expected output: 40 */
console.log("Combinations possible for n = 9: ", nf(9));

/* 6. expected output: 64 */
console.log("Combinations possible for n = 10: ", nf(10));

/* 7. expected output: 104 */
console.log("Combinations possible for n = 11: ", nf(11));

/* 8. expected output: 169 */
console.log("Combinations possible for n = 12: ", nf(12));

/* 9. expected output: 273 */
console.log("Combinations possible for n = 13: ", nf(13));

/* 
-- Reasoning:
  We can easily determine the amount of combinations needed for the
  first few numbers:
    N = 1: [1] --> 1 combination
    N = 2: [1,1] --> 1 combination
    N = 3: [1,1,1] and [3] --> 2 combinations
    N = 4: [1,1,1,1] [1,3] [3,1] [4] --> 4 combinations
  What we are going to do is to break down larger values of N until
  we get down to these known results, then use them to build up 
  the solution using recursion.
    N-1 = r1a: do we know the num. of combinations to reach r1a?
      Y: return num.
      N: keep breaking the problem down (r1a-1, r1a-3, r1a-4 ...)
    N-3 = r1b: same as above
    N-4 = r1c: same as above
  Example: Find the num. of combinations possible for N=5.
    N-1 = 5-1 = 4: 4 combinations
    N-3 = 5-3 = 2: 1 combination
    N-4 = 5-4 = 1: 1 combination
  The result will be: 
    (4 + 1 + 1) combinations = 6 combinations
*/
