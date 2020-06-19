/****************************************************************/
/*Problem: Counting Valleys (HR) ********/
/****************************************************************/
/*
-- Summary:
A mountain is a sequence of consecutive steps above sea level, starting with a step up from sea level and ending with a step down to sea level. A valley is a sequence of consecutive steps below sea level, starting with a step down from sea level and ending with a step up to sea level. Given Gary's sequence of up and down steps during his last hike, find and print the number of valleys he walked through. For example, if Gary's path is S=[DDUUUUDD], he first enters a valley 2 units deep. Then he climbs out an up onto a mountain 2 units high. Finally, he returns to sea level and ends his hike.
-- Input(s):
n: the number of steps Gary takes
s: a string describing his path
-- Expected output(s):
Return a single integer that denotes the number of valleys Gary walked through during his hike.
-- Constraints:
2 <= n <= 10^6 | s[i] e {UD}
*/
function countingValleys(n, s) {
  let sum = 0;
  let valleys = 0;

  for (let i = 0; i < n; i++) {
    if (s[i] === 'D') {
      sum -= 1;
      //console.log('Down - sum is: ', sum);
    } else if (s[i] === 'U') {
      sum += 1;
      //console.log('Up - sum is: ', sum);
      if (sum === 0) { valleys ++;}
    }
  }
  console.log(valleys);
}
//TEST CASES:
countingValleys(8,'UDDDUDUU'); //Expect 1
countingValleys(8,'DDUUUUDD'); //Expect 1
countingValleys(16,'DDUUDDUUDDDUUDUU'); //Expect 3
countingValleys(10,'UUUUDDUDDD'); //Expect 0