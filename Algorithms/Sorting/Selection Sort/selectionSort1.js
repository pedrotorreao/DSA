/****************************************************************/
/*Selection Sort  ********/
/****************************************************************/
/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) 
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray 
is picked and moved to the sorted subarray. 
*/
function selectionSort(array){
  for(let i = 0; i < array.length - 1; ++i){
    let min = i;
    for(let j = i + 1; j < array.length; ++j){
      if(array[j] < array[min]){
        min = j;
      }
    }
    [array[min], array[i]] = [array[i], array[min]];
  }
  return array;
}
//TEST CASES:
//1-:
let testArray1 = [9,85,-5,10,0,-17,123,3,67];

// console.time('Execution Time');
let orderedArray1 = selectionSort(testArray1);
// console.timeEnd('Execution Time');

console.log(orderedArray1);

//2-:
let testArray2 = [593,12,0,-45,1,45,23,-435,-1];

// console.time('Execution Time');
let orderedArray2 = selectionSort(testArray2);
// console.timeEnd('Execution Time');

console.log(orderedArray2);

//3-:
let testArray3 = [722,345,299,122,119,90,88,51,23,1,0,-1,-24,-121,-987];

// console.time('Execution Time');
let orderedArray3 = selectionSort(testArray3);
// console.timeEnd('Execution Time');

console.log(orderedArray3);