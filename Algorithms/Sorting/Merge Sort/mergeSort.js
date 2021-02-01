/****************************************************************/
/* Algorithm: Merge Sort  ********/
/****************************************************************/
/*
>> Definition:
    Merge sort use a Divide and Conquer strategy in which it repeatedly breaks down a list 
    into several sublists until each sublist consists of a single element and merging those 
    sublists in a manner that results into a sorted list.
>> Steps:
    1. Divide the unsorted list into n sublists, each containing one element (a list of one 
    element is considered sorted).
    2. Repeatedly merge sublists to produce new sorted sublists until there is only one 
    sublist remaining. This will be the sorted list.
>> Time complexity - O(n*log n)
>> Space complexity - O(n)
*/
function mergeSort(array) {
    //base case - we have reached the 1 element array, return it:
    if(array.length === 1) {
        return array;
    }
    //position where the array is divided:
    let mid = Math.round(array.length/2);
    //left half goes from position 0 to mid-1:
    let left = array.slice(0,mid);
    //right half goes from position mid to length-1:
    let right = array.slice(mid);

    //recursively call mergeSort() to divide the array until it reaches
    //the base case from where it begins to compare and merge the elements
    //into the resulting array:
    return mergeArrays(mergeSort(left),mergeSort(right));
}
function mergeArrays(left,right) {
    let indexL = 0;
    let indexR = 0;
    let mergedArray = [];
    
    //loop through all elements comparing each left and right pair:
    for(let counter = 0; counter < (left.length + right.length); ++counter) {
        //if left hasn't reached its end yet AND its value is less than right,
        //OR if right has reached its end, add left to mergedArray and incr. indexL:
        if(((typeof left[indexL] !== 'undefined') && (left[indexL] < right[indexR])) || (typeof right[indexR] === 'undefined')) {
            mergedArray[counter] = left[indexL];
            ++indexL;
        }
        //right is less than left OR left has reached its end, add right to
        //mergedArray and incr. indexR:
        else if(typeof right[indexR] !== 'undefined') {
            mergedArray[counter] = right[indexR];
            ++indexR;
        }
    }

    return mergedArray;
}

//TEST 1:
let array1 = [30,20,40,10,80,50,15];
console.log(mergeSort(array1));

//TEST 2:
let array2 = [1,35,11,0,-5,98,5];
console.log(mergeSort(array2));

