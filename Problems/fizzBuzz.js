/****************************************************************/
/*Problem: Fizz Buzz (LC)  ********/
/****************************************************************/
/*
-- Summary:
Write a program that outputs the string representation of numbers from 1 to n.
But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.
*/
var fizzBuzz = function(n) {
  let arr = [];
  let counter = 1; 
  while(counter <= n) {
          if (counter % 3 === 0 || counter % 5 === 0) {
              if (counter % 3 === 0 && counter % 5 === 0) {
                  arr.push("FizzBuzz");
                  counter += 1;
              } else if (counter % 3 === 0) {
                  arr.push("Fizz");
                  counter += 1;
              } else if (counter % 5 === 0) {
                  arr.push("Buzz");
                  counter += 1;
              } 
          } 
          else {
              arr.push(counter.toString());
              counter += 1;
          }
  }
  return arr;
};