/************************************************************/
/*Problem: Mini-Max Sum  ********/
/************************************************************/
/*
Summary:  Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. 
          Then print the respective minimum and maximum values as a single line of two space-separated long integers.
Input(s): An array of 5 integers.
Expected  Output: Two space-separated long integers denoting the respective minimum and maximum values that can be calculated by summing exactly 
          four of the five integers. 
Constraints: 1 <= array[i] <= 10e9
*/
//BRUTE FORCE APPROACH: TIME COMPLEXITY O(N*N)
//USED INSERTION SORT IN ORDER TO SORT THE ARRAY----->IMPROVE THIS, TRY MERGE SORT
/*
function miniMaxSum(arr) {
  //By the question statement, there is no guarantee that the input array is sorted. It may be a catch.
  let min = 0;
  let max = 0;
  let up = 0;
  let down = 1;

  for (let i = 0; i < arr.length; i++) {
    let key = arr[i];
    let j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j+1] = key;
  }

  while (up < arr.length - 1 && down < arr.length) {
    min += arr[up];
    max += arr[down];
    up++;
    down++; 
  }
  //return [min,max];
  return console.log('element: ',element);${min} ${max}`;
}
console.log(miniMaxSum([9, 11, 2, 5]));
console.log(miniMaxSum([1, 3, 5, 7, 9]));
*/