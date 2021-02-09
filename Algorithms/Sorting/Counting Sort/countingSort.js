/****************************************************************/
/* Algorithm: Counting Sort  ********/
/****************************************************************/
/*
>> Description:  
    Algorithm for sorting a collection of objects according to keys that are small integers; 
    that is, it is an integer sorting algorithm. It operates by counting the number of objects 
    that have each distinct key value, and using arithmetic on those counts to determine the 
    positions of each key value in the output sequence. Because it uses key values as indexes 
    into an array, it is not a comparison sort [Wikipedia].

    Counting sort is efficient if the range of input data is not significantly greater than the 
    number of objects to be sorted. Consider the situation where the input sequence is between 
    range 1 to 10K and the data is 10, 5, 10K, 5K [GeeksForGeeks].

    Counting sort can be used as a subroutine for more powerful sorting algorithms such 
    as radix sort [Brilliant].

    Counting sort assumes that each of the n input elements in a list has a key value ranging 
    from 0 to k, for some integer k. For each element in the list, counting sort determines the 
    number of elements that are less than it. Counting sort can use this information to place the 
    element directly into the correct slot of the output array. Counting sort uses three lists: 
    - the input list, array[0,1,…,n], 
    - the output list, sortedArr[0,1,…,n], 
    - and a list that serves as temporary memory, count[0,1,…,k]. 
    Note that 'array' and 'sortedArr' have n slots (a slot for each element), while 'count' contains 
    k slots (a slot for each key value).

>> Steps:
    1. It starts by going through 'array', and for each element 'array[i]', it goes to the index of 
    'count' that has the same value as 'array[i]' (so it goes to 'count[array[i]]') and increments 
    the value of 'count[array[i]]' by one. This means that if 'array' has seven 0’s in its list, 
    after counting sort has gone through all n elements of 'array', the value at 'count[0]' will be 7.
    In this step, 'count' keeps track of how many elements in 'array' there are that have the same 
    value of a particular index in 'count'. In other words, the indices of 'count' correspond to the 
    values of elements in 'array', and the values in 'count' correspond to the total number of times 
    that a value in 'array' appears in 'array'.
    2. Next, modify 'count' so that each 'count[i]' includes the number of elements less than it. This 
    can be accomplished by going through 'count' and replacing each 'count[i]' value with 
    'count[i] + count[i−1]'. This step allows counting sort to determine at what index in 'sortedArr' 
    an element should be placed.
    3. Then, starting at the end of 'array', add elements to 'sortedArr' by checking the value of 'array[i]', 
    going to 'count[array[i]]', writing the value of the element at 'array[i]' to 'sortedArr[count[array[i]]]'. 
    Finally, decrement the value of count[array[i]] by 1 since that slot in BBB is now occupied [Brilliant].

>> Time complexity: O(k+n)
    The first loop goes through 'array', which has n elements. This step has a O(n) time complexity. The second 
    loop iterates over k, so this step has a running time of O(k). The third loop iterates through 'array', so 
    again, this has a running time of O(n). Therefore, the counting sort algorithm has a running time of O(k+n). 
>> Space complexity: O(n+k), stable sort.
*/

function countingSort(array) {
    let key = 0; //Key: maximun element in the array, i.e., the range 0...key
    array.forEach(element => {
        if(element > key) key = element;
    });

    let count = Array(key+1).fill(0); //Count: array to store how often each element happens
    for(let i = 0; i < array.length; ++i){
        ++count[array[i]];
    }
    for(let i = 1; i <= key; ++i){
        //Each count[i] now gives us from each index to which index element i goes:
        count[i] = count[i] + count[i-1]; 
    }

    let sortedArr = [];
    for(let i = array.length-1; i >= 0; i--){
        sortedArr[count[array[i]]-1] = array[i];
        --count[array[i]];
    }

    console.log(sortedArr);
}
console.log('----- TEST 1 -----');
let array1 = [2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9];
countingSort(array1);

console.log('----- TEST 2 -----');
let array2 = [0,4,1,7,5,5,6,4,3,3,4,2,1,9,8,4,6];
countingSort(array2);

console.log('----- TEST 3 -----');
let array3 = [6,1,2,1,1,5,4,3,6,9,0,2,9,2,1,1,7];
countingSort(array3);

console.log('----- TEST 4 -----');
let array4 = [0,11,1,3,2,5,5,0,3,3,1,6,9,2,7,9,3];
countingSort(array4);