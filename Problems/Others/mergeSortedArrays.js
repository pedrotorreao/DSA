/************************************************************/
/*Problem: Merge Sorted Arrays  ********/
/************************************************************/
/*
//SOLUTION 1: Time complexity O(n*n) using Insertion Sort
let mergeAndSort = (arr1, arr2) => {
  let array = arr1.concat(arr2);

  for (let i = 1; i < array.length; i ++) {
    let key = array[i];
    let j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j+1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
  return array;
}
console.log(mergeAndSort([0,3,4,31], [4,6,30]));

//SOLUTION 2: Time complexity O(n) but worse readability
function mergeSortedArrays(array1, array2){
  const mergedArray = [];
  let array1Item = array1[0];
  let array2Item = array2[0];
  let i = 1;
  let j = 1;
  
  //We should actually move these 2 if statements to line 2 so that we do the checks before we do assignments in line 3 and 4!
  if(array1.length === 0) {
    return array2;
  }
  if(array2.length === 0) {
    return array1;
  }

  while (array1Item || array2Item){
    if(array2Item === undefined || array1Item < array2Item){
      mergedArray.push(array1Item);
      array1Item = array1[i];
      i++;
    }   
    else {
      mergedArray.push(array2Item);
      array2Item = array2[j];
      j++;
    }
  }
  return mergedArray;
}

console.log(mergeSortedArrays([0,3,4,31], [3,4,6,30]));
*/