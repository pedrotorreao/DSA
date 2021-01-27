/****************************************************************/
/*Insertion Sort  ********/
/****************************************************************/
/*
Simple sorting algorithm that builds the final sorted array (or list) one item at a time. It is much less 
efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort. However, 
insertion sort provides several advantages:
  <> Simple implementation;
  <> Efficient for (quite) small data sets, much like other quadratic sorting algorithms;
  <> More efficient in practice than most other simple quadratic (i.e., O(n2)) algorithms such as selection 
  sort or bubble sort;
  <> Adaptive, i.e., efficient for data sets that are already substantially sorted: the time complexity is O(kn) 
  when each element in the input is no more than k places away from its sorted position; 
Insertion sort iterates, consuming one input element each repetition, and grows a sorted output list. At each 
iteration, insertion sort removes one element from the input data, finds the location it belongs within the 
sorted list, and inserts it there. It repeats until no input elements remain. [Wikipedia]

Time complexity: O(n^2)
Space complexity: O(1)
*/
function insertionSort(array){
  let replaceCount = 0;

  console.log(`Original array: ${array}. \n`);

  for(let index = 1; index < array.length; ++index){
    let key = array[index]; //key stores the current array[index] element to be compared
    let j = index - 1; //j is used to get the elemente before the current array[index]

    /* While j represents a valid position in the array and the element at position j is greater 
    than the one at position index, replace element at array[index] by the one at array[j]. The 
    array will then have repeated elements but key holds the correct value to be placed at array[j+1].*/
    
    while(j >= 0 && array[j] > key){// use '<' to sort in decreasing order
      ++replaceCount;
      console.log(`Replacement ${replaceCount}: replacing ${array[j+1]} by ${array[j]}.`);
      
      array[j+1] = array[j];
      j -= 1;
    }
    array[j+1] = key;
  }

  return array;
}
let unsorted = [105,3,-78,0,55,91,-2];
let sorted = insertionSort(unsorted);

console.log(`\nSorted array: ${sorted}`);