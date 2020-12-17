/****************************************************************/
/*Problem: Bubble Sort - Traditional Algorithm ********/
/****************************************************************/
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
let testArray = [9,85,-5,10,0,-17,123,3,67];
console.log(bubbleSort(testArray));