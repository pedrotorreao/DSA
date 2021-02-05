/****************************************************************/
/* Algorithm: Merge Sort  ********/
/****************************************************************/
/*
 >> Definition:
    Quicksort is a divide-and-conquer algorithm and it works by selecting
    a pivot element from the array and partitioning the other elements 
    into two sub-arrays, according to whether they are less than or greater 
    than the pivot. The partitioning is the key and most important step of this
    algorithm, making sure that all elements smaller than the pivot are at its left,
    and all elements greater than the pivot are at its right. The sub-arrays are 
    then sorted recursively. This can be done in-place, requiring small additional 
    amounts of memory to perform the sorting [Wikipedia].
>> Steps: 
    1. Choose an element to be the pivot
    2. Partition the array around the pivot
    3. Recursively apply 1. and 2. to the sub-arrays.
 >> Time complexity:
        - Worst case (rare) - O(n^2): pivot happens to be the largest/smallest
        element in the array.
        - Average - O(n*log n): pivot is an intermediary value.
        - Best - O(n*log n): In the most balanced case, each time we perform a 
        partition we divide the list into two nearly equal pieces. 
 >> Space complexity - Worst case: O(log n)

*/

function quickSort(array,p = 0,q = array.length-1){
    //base case: if we've gone through all the array (or subarray for the recursive 
    //calls), i.e., low position (p) have reached the high position (q), we're done.
    if(p < q) {
        //partition the array around the pivot (usually last element):
        let r = partition(array,p,q);
        //recursively call quickSort() for subarray with elements smaller than pivot.
        quickSort(array,p,r-1);
        //recursively call quickSort() for subarray with elements greater than pivot.
        quickSort(array,r+1,q);
    }
    //return array;
}

/**
 * Makes sure that all elements smaller than the pivot are on the left,
 * and all elements greater than the pivot are on right.
 * @param {array} array 
 * @param {number} first 
 * @param {number} last 
 * @returns {number} partitionedAt
 */
function partition(array,p,q){
    let pivot = q; //last element in the array
    let j = p; //first element in the array
    let i = p - 1; //pivot position after the partitioning

    while(j <= q){
        if(array[j] <= array[pivot]) {
            ++i;
            [array[i],array[j]] = [array[j],array[i]];
        }
        ++j;
    }
    return i;
}

//TEST 1:
console.log('----- TEST 1 -----');
let array1 = [30,20,40,10,80,50,15];
console.log('Original array: ', array1);
quickSort(array1);
console.log('Sorted array: ', array1);

//TEST 2:
console.log('----- TEST 2 -----');
let array2 = [1,35,11,0,-5,98,5];
console.log('Original array: ', array2);
quickSort(array2);
console.log('Sorted array: ', array2);

//TEST 3:
console.log('----- TEST 3 -----');
let array3 = [3,7,8,5,2,1,5,4];
console.log('Original array: ', array3);
quickSort(array3);
console.log('Sorted array: ', array3);

//TEST 4:
console.log('----- TEST 4 -----');
let array4 = [35,79,-8,53,0,91,-62,4,0];
console.log('Original array: ', array4);
quickSort(array4);
console.log('Sorted array: ', array4);