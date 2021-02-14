/****************************************************************/
/* Algorithm: Radix Sort  ********/
/****************************************************************/

function radixSort(array) { 
    let max = getMax(array);
    let sorted = [];

    for(let position = 1; (max/position) > 1; position = position*10) {
        countingSort(array,position);
    }

    console.log(array);
}

function getMax(array) {
    let max = 0; //Key: maximum element in the array, i.e., the range 0...key
    array.forEach(element => {
        if(element > max) max = element;
    });
    return max;
}

function countingSort(array,position) {
    let key = 10; //each digit can go only from 0 to 9 (radix = 10)
    let count = Array(key).fill(0); //count: array to store how often each element happens

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