/****************************************************************/
/*Problem: Balanced Brackets (HR)  ********/
/****************************************************************/
/*
-- Summary:
Given n strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO.
-- Input(s):
isBalanced has the following parameter(s):
s: a string of brackets
-- Expected output(s):
-- Constraints:
Complete the function isBalanced in the editor below. It must return a string: YES if the sequence is balanced or NO if it is not.
*/
// SOLUTION WITHOUT USING STACKS:
function isBalanced(s) {
  let count = -1;
	while (s.length != count) {
		count = s.length; 
    s = s.replace('()', '');
    s = s.replace('[]', '');
    s = s.replace('{}', '');
	}
	if (s.length == 0)
		return "YES";
	else 
		return "NO";
}
/* -- SOLUTION EXPLANATION:
Setting count equal to the original string length means that, if there are no case of matching brackets, this means that not all brackets have their pair, meaning that nothing will be replaced and the string length will remain the same, thus in the next iteration count will be equal to the string length and the execution leaves the while loop. As nothing was replaced, the string length is different than zero, thus we return 'NO'. If there are matching brackets, the while loop will execute until all matching brackets are replaced/removed and at some point count will be equal to the string length. If when we get out of the while loop the string length is zero, that means that there were only matching brackets and the string was balanced, and the program returns 'YES'. Otherwise, it means that not all of the brackets on the string had their pair, and the program returns 'NO'.
*/

console.log(isBalanced('{{[[(())]]}}'));
console.log(isBalanced('{[()}'));
console.log(isBalanced('{{[[(())]]}}'));

//SOLUTION USING STACKS: