/************************************************************/
/*Problem: Diagonal Difference ********/
/************************************************************/
/*
let array = [
  3, 
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 10]
];
let j = 0;
let m = array.length - 2;

let sumDiag1 = 0;
let sumDiag2 = 0;

for (let i = 1; i <= array[0]; i++) {
  sumDiag1 += array[i][j];
  j++;
}
for (let i = 1; i <= array[0]; i++) {
  sumDiag2 += array[i][m];
  m--;
}

for (let i = 1; i <= array.length - 1; i++) {
  sumDiag1 += array[i][j];
  j++;
}
for (let i = 1; i <= array.length - 1; i++) {
  sumDiag2 += array[i][m];
  m--;
}

let sum = sumDiag1 - sumDiag2;
console.log(sum);
*/

// Solution adapted to Hackerrank:

function diagonalDifference(arr) {
    // Write your code here
    let j = 0;
    let m = arr.length - 1;

    let sumDiag1 = 0;
    let sumDiag2 = 0;

    for (let i = 0; i < arr.length; i++) {
        sumDiag1 += arr[i][j];
        j++;
    }
    
    for (let i = 0; i < arr.length; i++) {
        sumDiag2 += arr[i][m];
        m--;
    }   
    let result = Math.abs(sumDiag1-sumDiag2);
    return result;

}
