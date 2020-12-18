/****************************************************************/
/*Problem: Bubble Sort - Single loop ********/
/****************************************************************/
function bubbleSort(array){
  let endPoint = array.length;
  let index = 0;
  let ordered = false;
  
  while(!ordered){
    if(array[index] > array[index+1]){
      [array[index], array[index+1]] = [array[index+1], array[index]];
    }
  
    [index,endPoint] = (index === endPoint-2) ? [0, --endPoint] : [++index, endPoint];
    
    ordered = ((endPoint === 2) ? true : false);
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