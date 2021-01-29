/****************************************************************/
/* Algorithm: Bubble Sort - Traditional Algorithm ********/
/****************************************************************/
/*
Bubble sort, sometimes referred to as sinking sort, is a simple sorting algorithm that repeatedly steps through the list, 
compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the 
list is sorted. The algorithm, which is a comparison sort, is named for the way smaller or larger elements "bubble" to 
the top of the list. This simple algorithm performs poorly in real world use and is used primarily as an educational tool. 
More efficient algorithms such as quicksort, timsort, or merge sort are used by the sorting libraries built into popular 
programming languages such as Python and Java. [Wikipedia]

Time complexity: O(n^2)
Space complexity: O(1)
*/

function bubbleSort(array){
  let sizing = array.length;
  for(let i = 0; i < sizing - 1; ++i){
    for(let j = 0; j < sizing - i - 1; ++j){
      if(array[j] > array[j+1]){
        [array[j], array[j+1]] = [array[j+1], array[j]];
      }
    }
  }
  return array;
}

//TEST CASES:
//1-:
// let testArray1 = [9,85,-5,10,0,-17,123,3,67];

// console.time('Execution Time');
// let orderedArray1 = bubbleSort(testArray1);
// console.timeEnd('Execution Time');

// console.log(orderedArray1);

//2-:
// let testArray2 = [593,12,0,-45,1,45,23,-435,-1];

// console.time('Execution Time');
// let orderedArray2 = bubbleSort(testArray2);
// console.timeEnd('Execution Time');

// console.log(orderedArray2);

//3-:
let testArray3 = [722,345,299,122,119,90,88,51,23,1,0,-1,-24,-121,-987];

console.time('Execution Time');
let orderedArray3 = bubbleSort(testArray3);
console.timeEnd('Execution Time');

console.log(orderedArray3);