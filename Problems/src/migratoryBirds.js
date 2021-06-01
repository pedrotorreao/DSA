/****************************************************************/
/*Problem: Problem_Name  ********/
/****************************************************************/
/*
-- Summary:
  It should return the lowest type number of the most frequently sighted bird.
-- Input(s): array of n integers, where 5<=n<=2x10^5 and 1<=ar[n]<=5
-- Expected output(s):
  It should return the lowest number that appears more often. 
-- Constraints:
*/
function migratoryBirds(arr) {
  let map = {};
  let sights = 0;
  let birdID = 5;
  for (let i = 0; i < arr.length; i++) {
    const item = arr[i];
    if (!map[arr[i]]) {
      map[item] = 1;
    } else {
      map[item]++;
    }
  }
  for (let i = 0; i < arr.length; i++) {
    if (map[arr[i]] > sights) {
      birdID = arr[i];
      sights ++;
    }
  }
  return birdID;
}
console.log(migratoryBirds([2,3,4,5,4,3,2,1,3,4,1,1,1]));