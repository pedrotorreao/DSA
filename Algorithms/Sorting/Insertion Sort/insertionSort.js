/****************************************************************/
/*Insertion Sort  ********/
/****************************************************************/
function insertionSort(array){
  let replaceCount = 0;

  console.log(`Original array: ${array}. \n`);

  for(let index = 1; index < array.length; ++index){
    let key = array[index]; //key stores the current array[index] element to be compared
    let j = index - 1; //j is used to get the elemente before the current array[index]

    /* While j represents a valid position in the array and the element at position j is greater than the one at position index, replace element at array[index] by the one at array[j]. The array will then have repeated elements but key holds the correct value to be placed at array[j+1].*/
    
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