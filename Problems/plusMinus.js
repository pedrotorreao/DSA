/************************************************************/
/*Problem: Plus Minus ********/
/************************************************************/
/*
Summary: Given an array of integers, calculate the fractions of its elements 
that are positive, negative, and are zeros. Print the decimal value of each fraction on a new line.
*/

function plusMinus(arr) {
  let size = arr.length;
  let positives = 0;
  let negatives = 0;
  let zeros = 0;

  for (let i = 0; i < size; i++) {
    if (arr[i] < 0) {
      negatives++;
    } else if (arr[i] > 0) {
      positives++;
    } else {
      zeros++;
    }
  }
console.log(`${(positives/size).toPrecision(6)}\n${(negatives/size).toPrecision(6)}\n${(zeros/size).toPrecision(6)}`);
}
plusMinus([-4, 3, -9, 0, 4, 1]);
