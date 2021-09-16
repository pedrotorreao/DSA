/*****************************************************************************************/
/*Problem: Reverse Integer  ********/
/*****************************************************************************************/
//Summary: given a 32-bit signed integer, reverse its digits.
//Input: (a) 123, (b) -123, (c) 120
//Output: (a) 321, (b) -321 , (c) 21
//Remarks: the signal must not be reversed and zeros and the end of the original number should be ignored.
//Constraints: reversed number must not exceed range [-2^31, 2^31 - 1]. Return 0 in case reversed number overflows.
let x = 123;
let y = 120;
let w = -123;
let z = 1534236469;
var reverse = function(x) {
  if (x < Math.pow(-2,31) || x > (Math.pow(2,31)-1)) {return 0;}

  x = x.toString();

  let reversing = [];
  let j = x.length;

  for (let i = 0; i < x.length; i++) {
    if (x[i] === '-') {
      reversing[i] = x[i];
    } else {
    reversing [j-i] = x[i];
    }
  }
  reversing = reversing.join("");

  if (parseInt(reversing) < Math.pow(-2,31) || parseInt(reversing) > (Math.pow(2,31)-1)) {
    return 0;
  } else {
    return parseInt(reversing);
  }  
}

console.log(reverse(x));
console.log(reverse(y));
console.log(reverse(w));
console.log(reverse(z));