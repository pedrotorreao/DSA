/****************************************************************/
/* Algorithm: Radix Sort  ********/
/****************************************************************/
/*
 >> Definition:
    Radix-sort is a non-comparative stable sorting algorithm which sorts the data by distributing elements
    into buckets according to their radix. For elements with more than one significant digit, this 
    distribution process is repeated for each digit, while preserving the ordering of the prior step, 
    until all digits have been considered. Radix sorts is usually implemented by starting from the least 
    significant digit (LSD) for numbers and from the most significant digit (MSD) words.


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

function radixSort(array) { 
    let max = getMax(array);
    let sorted = [];

    /*This loop iterates through the place values. First it goes through the 1's, then the 10's, and so on. 
    */
    for(let position = 1; (max/position) > 1; position = position*10) {
        countingSort(array,position);
    }

    console.log(array);
}

//get max element in an array:
function getMax(array) {
    let max = 0; //Key: maximun element in the array, i.e., the range 0...key
    array.forEach(element => {
        if(element > max) max = element;
    });
    return max;
}

//counting sort subroutine:
function countingSort(array,position) {
    let key = 10; //each digit can go only from 0 to 9 (radix = 10)
    let count = Array(key).fill(0); //Count: array to store how often each element happens

    for(let i = 0; i < array.length; ++i){
        ++count[Math.floor((array[i]/position)%10)];
    }

    for(let i = 1; i <= key; ++i){
        //Each count[i] now gives us from each index to which index element i goes:
        count[i] = count[i] + count[i-1]; 
    }

    let sortedArr = [];
    for(let i = array.length-1; i >= 0; i--){
        sortedArr[count[Math.floor((array[i]/position)%10)]-1] = array[i];
        --count[Math.floor((array[i]/position)%10)];
    }

    for(let i = 0; i < array.length; ++i){
        array[i] = sortedArr[i];
    }
}

console.log('----- TEST 1 -----');
let array1 = [152,8,530,90,88,231,11,45,677,199];
radixSort(array1);

console.log('----- TEST 2 -----');
let array2 = [1075,432,21,117,5,578,69,14,3,903,524,28,1,739,885,42,6];
radixSort(array2);

console.log('----- TEST 3 -----');
let array3 = [6999,1005,7742,311,21,5876,4956,3334,6987,9990,0,274,92,289,1,123,7643];
radixSort(array3);

console.log('----- TEST 4 -----');
let array4 = [250,1134,41,3234,62,4545,955,0,34,6783,1,2346,999,82,447,2459,3];
radixSort(array4);