/****************************************************************/
/*Problem: Palindrome Number  ********/
/****************************************************************/
/*
-- Summary: Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
-- Input(s): Ex.: (a) 121; (b)-121
-- Expected output(s): (a) true; (b) false
-- Constraints: Coud you solve it without converting the integer to a string?
- Approaches: 
(a) Convert the number to a string, reverse it and compare to the original one :)
(b) Get how many digits (size) the number has, divide the number by 10 'size' times, you'll get all the digits, store these in an array, reverse it and compare to the original.
*/
// APPROACH (b): Much faster, since there is only one loop.

var isPalindrome = function(x) {
  let revNum = 0;
  let original = x;

  while (x > 0) {
    revNum = (revNum * 10) + (x % 10);
    x = Math.floor(x/10);
  }
  if (revNum === original) {
    return true;
  } else {
    return false;
  }

};

/* -- EXPLANATION:
Lets suppose x = 123 orinally.
- 1st iteration (i = 0):
revNum = (0*10)+(123%10) = 0 + 3 = 3
x = Math.floor(123/10) = Math.floor(12.3) = 12

- 2nd iteration (i = 1):
revNum = (3*10)+(12%10) = 30 + 2 = 32
x = Math.floor(12/10) = Math.floor(1.2) = 1

- 3rd iteration (i = 2):
revNum = (32*10)+(1%10) = 320 + 1 = 321
x = Math.floor(1/10) = Math.floor(0.1) = 0

*/


// APPROACH (a): Very slow since all the methods used have time complexity O(n) each.
// var isPalindrome = function(x) {
//   let revNum = x.toString().split('').reverse().join('');
//   console.log(revNum);
//   if (revNum === x.toString()) {
//     return true;
//   } else {
//     return false;
//   }
// };

console.log(isPalindrome(-121));