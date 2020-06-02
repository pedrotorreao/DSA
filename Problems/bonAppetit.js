/****************************************************************/
/*Problem: Bon Appétit (HR)  ********/
/****************************************************************/
/*
-- Summary:
  Complete the bonAppetit function in the editor below. It should print 'Bon Appetit' if the bill is fairly split. Otherwise, it should print the integer amount of money that Brian owes Anna.
-- Input(s):
  bill: an array of integers representing the cost of each item ordered
  k: an integer representing the zero-based index of the item Anna doesn't eat
  b: the amount of money that Anna contributed to the bill
-- Expected output(s):
  If Brian did not overcharge Anna, print Bon Appetit on a new line; otherwise, print the difference (i.e., b_charged - b_actual) that Brian must refund to Anna. This will always be an integer.
-- Constraints:
  2<=n<=10^5 0<=k<n 0<=bill[i]<=10^4 0<=b<=sum(bill[i])(from i=0 to n-1)
  */
 function bonAppetit(bill, k, b) {
  let sum = 0;
  for (let i = 0; i < bill.length; i++) {
    if (i !== k) {
      sum += bill[i];
    }
  }
  if (b === sum/2) {
    return 'Bon Appetit';
  } 
  return (b-(sum/2));
}
console.log(bonAppetit([2,4,6],2,3));
console.log(bonAppetit([2,4,6],2,6));
console.log(bonAppetit([3,10,2,9],1,12));
console.log(bonAppetit([3,10,2,9],1,7));
console.log(bonAppetit([3,10,2,1],0,7));
console.log(bonAppetit([13,10,22,9],2,10));
console.log(bonAppetit([3,1,25,19],3,14));