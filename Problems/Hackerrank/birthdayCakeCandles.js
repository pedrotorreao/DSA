/*****************************************************************************************/
/*Problem: Birthday Cake Candles  ********/
/*****************************************************************************************/
//Summary: given an array of integers, return how many times the biggest value appears.
//Input: array of integers that represent the height of the candles.
//Output: number of times the highest values appear (how many candles the person can blow out.)
/*
function birthdayCakeCandles(ar) {
  let element = 0;
  let count = 1;
  //console.log('element b4 for loop: ',element);

  for (let i = 0; i < ar.length; i++) {
    //console.log('element b4 if statement: ',element);
    //console.log(`ar[${i}] = ${ar[i]}`);
    if (element < ar[i]) {
      element = ar[i];
      count = 1;
      //console.log('element: ',element);
    } else if (element === ar[i]) {
      count++;
    } 
    //console.log('count: ',count);
  }
  return count;
}
console.log(birthdayCakeCandles([4,4,1,3]));
console.log(birthdayCakeCandles([4,0,1,3,6,7,7,9]));
console.log(birthdayCakeCandles([1,0,0,0,1]));
console.log(birthdayCakeCandles([4,4,4,3,4,4,5]));
*/