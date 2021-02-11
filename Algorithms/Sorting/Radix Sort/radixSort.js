/****************************************************************/
/* Algorithm: Radix Sort  ********/
/****************************************************************/

function radixSort(array) { //[152,008,530,090,088,231,011,045,677,199]
    let max = getMax(array);
    let sorted = [];

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
    let key = 10; //each digit can go only from 0 to 9.
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