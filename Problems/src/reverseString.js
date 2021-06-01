/************************************************************/
/*Problem: Reversing a string  ********/
/************************************************************/

//SOLUTION 1: 
let string = 'jupiter';
function reverseString (string) {
  if (!string || string.length < 2 || typeof string !== 'string') {
    return 'You should enter a string dumbass';
  }

  let reversing = [];
  let j = string.length - 1;

  for (let i = 0; i < string.length; i++) {
    reversing [j-i] = string [i];
  }
  return reversing.join("");
}
console.log(reverseString(string));

//SOLUTION 2: LANGUAGE DEPENDENT
console.log(string.split('').reverse().join(''));

//SOLUTION 3: LANGUAGE DEPENDENT
console.log([...string].reverse().join(''));