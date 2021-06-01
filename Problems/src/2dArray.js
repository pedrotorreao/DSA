/****************************************************************/
/*Problem: 2D Array - DS  ********/
/****************************************************************/
/*
-- Summary:
-- Input(s):
-- Expected output(s):
-- Constraints:
*/
//BRUTE FORCE APPROACH: High time complexity O(n*m) and too confusing
// function hourglassSum(arr) {
//   let hourGlassesA = []; //hour glasses sum
//   let hourGlassesB = [];
//   let hourGlassSum = [];

//   for (let i = 0; i < arr.length; i++) {
//     for (let j = 0; j < 4; j++) {
//       hourGlassesA.push(arr[i][j] + arr[i][j+1] + arr[i][j+2]);
//     }
//   }
//   for (let i = 0; i < 4; i++) {
//     for (let j = 0; j < 4; j++) {
//       hourGlassesB.push(arr[i+1][j+1]);
//     }
//   }
//   for (let i = 0; i < 16; i++) {
//     hourGlassSum.push(hourGlassesA[i] + hourGlassesA[i+8]);
//   }
//   for (let i = 0; i < 16; i++) {
//     hourGlassSum[i] = hourGlassSum[i] + hourGlassesB[i];
//   }
//   let sum = hourGlassSum[0];

//   for (let i = 1; i < 16; i++) {
//     if (hourGlassSum[i] > sum) {
//       sum = hourGlassSum[i];
//     }
//   }

//   return sum;
// }

//BETTER APPROACH: Still has a high time complexity O(n*n), but a lot less confusing.
function hourglassSum(arr) {
  let hourGlassesA = []; //hour glasses sum

  for (let i = 0; i < arr.length-2; i++) {
    for (let j = 0; j < arr.length-2; j++) {
      hourGlassesA.push(arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]);
    }
  }
  
  let sum = hourGlassesA[0];

  for (let i = 1; i < hourGlassesA.length; i++) {
    if (hourGlassesA[i] > sum) {
      sum = hourGlassesA[i];
    }
  }

  return sum;
}
//TEST CASES:
console.log(hourglassSum([[-9,-9,-9,1,1,1],[0,-9,0,4,3,2],[-9,-9,-9,1,2,3],[0,0,8,6,6,0],[0,0,0,-2,0,0],[0,0,1,2,4,0]]));
console.log(hourglassSum([[1,1,1,0,0,0],[0,1,0,0,0,0],[1,1,1,0,0,0],[0,0,2,4,4,0],[0,0,0,2,0,0],[0,0,1,2,4,0]]));