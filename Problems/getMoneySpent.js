/****************************************************************/
/*Problem: Electronics Shop (HR)  ********/
/****************************************************************/
/*
-- Summary:
Monica wants to buy a keyboard and a USB drive from her favorite electronics store. The store has several models of each. Monica wants to spend as much as possible for the 2 items, given her budget. Given the price lists for the store's keyboards and USB drives, and Monica's budget, find and print the amount of money Monica will spend. If she doesn't have enough money to both a keyboard and a USB drive, print -1 instead. She will buy only the two required items.
-- Input(s):
keyboards: an array of integers representing keyboard prices
drives: an array of integers representing drive prices
b: the units of currency in Monica's budget
-- Expected output(s):
Print a single integer denoting the amount of money Monica will spend. If she doesn't have enough money to buy one keyboard and one USB drive, print -1 instead.
-- Constraints:
*/
//BRUTE FORCE APPROACH: O(n*m) time complexity.
function getMoneySpent(keyboards, drives, b) {
  let map = {};
  let sum = 0;
  for (let i = 0; i < keyboards.length; i++) {
    let item = keyboards[i];
    let complement = b - keyboards[i];
    if (!map[complement]) {
      map[complement] = true;
    }
  }
  for (let i = 0; i < drives.length; i++) {
    if (map[drives[i]]) {
      return b;
    }
  }
  for (let i = 0; i < keyboards.length; i++) {
    for (let j = 0; j < drives.length; j++) {
      if ((keyboards[i] + drives [j]) > sum && (keyboards[i] + drives [j]) < b) {
        sum = keyboards[i] + drives [j];
      }
    }
  }
  if (sum > 0) {
    return sum;
  } else {
    return -1;
  }
}
console.log(getMoneySpent([3,1],[5,2,9],10));
console.log(getMoneySpent([4],[5],5));