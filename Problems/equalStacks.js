/****************************************************************/
/*Problem: Equal Stacks (HR)  ********/
/****************************************************************/
/*
-- Summary:
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. You can change the height of a stack by removing and discarding its topmost cylinder any number of times. Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. This means you must remove zero or more cylinders from the top of zero or more of the three stacks until they're all the same height, then print the height. The removals must be performed in such a way as to maximize the height. Note: An empty stack is still a stack.
-- Input(s):
n1 space-separated integers describing the cylinder heights in stack 1. The first element is the top of the stack.
n2 space-separated integers describing the cylinder heights in stack 2. The first element is the top of the stack.
n3 space-separated integers describing the cylinder heights in stack 3. The first element is the top of the stack.
-- Expected output(s):
Print a single integer denoting the maximum height at which all stacks will be of equal height.
-- Constraints:
*/
function equalStacks(h1, h2, h3) {
  let sumh1 = 0, sumh2 = 0, sumh3 = 0;

  h1 = h1.reverse(); console.log(h1);
  h2 = h2.reverse(); console.log(h2);
  h3 = h3.reverse(); console.log(h3);

  for (let i = 0; i < h1.length; i++) { sumh1 += h1[i]; }
  for (let i = 0; i < h2.length; i++) { sumh2 += h2[i]; }
  for (let i = 0; i < h3.length; i++) { sumh3 += h3[i]; }

  let min = Math.min(sumh1, sumh2, sumh3);

  while (true) {
    if (sumh1 > min) {sumh1 -= h1.pop();}
    if (sumh2 > min) {sumh2 -= h2.pop();}
    if (sumh3 > min) {sumh3 -= h3.pop();}

    if (sumh1 === sumh2 && sumh2 === sumh3) {return min;}
    min = Math.min(sumh1, sumh2, sumh3);
  }
}
console.log(equalStacks([3,2,1,1,1],[4,3,2],[1,1,4,1]));