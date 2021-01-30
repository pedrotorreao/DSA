/****************************************************************/
/* Algorithm: Bucket Sort ********/
/****************************************************************/
/*
>> Definition: 
    Bucket Sort is a sorting technique that sorts the elements by first dividing the elements 
    into several groups called buckets. The elements inside each bucket are sorted using any 
    of the suitable sorting algorithms or recursively calling the same algorithm. After that,
    it's just a matter of concatenating the resulting buckets.
>> Steps:
    1 - Determine N, the number of buckets to be used. We can define N as the size of the 
    unsorted input array for simplicity. Here, N is calculated using the formula below:
        N = floor(square root (size of input array))
    Also, we are gonna place all these individual buckets inside an array.
    2 - Insert each array element into its bucket. To decide in which bucket a given element
    goes we can use the following:
        location = ceil((element * N) / largest array element)
    3 - Sort each individual bucket using a sorting algorithm of choice. Here are going to be
    using Insertion Sort.
    4 - Concatenate the sorted buckets.
>> When to use:
    - When the data to be sorted is uniformly distributed over a range.
>> When not to use:
    - When space is a concern.
>> Time complexity:
    - Worst case - O(n^2): In case the elements are in a very close range in the array, it is 
    possible that some bucket have way more elements than others or even all the elements are 
    placed in the same bucket which makes the complexity depend on the helper sorting algorithm.
    - Best case - O(n+k): In case the elements are uniformly distributed in the buckets. O(n) is 
    the complexity for making the buckets and O(k) is the complexity for sorting the elements of 
    the bucket using algorithms having linear time complexity at the best case.
>> Space complexity - O(n)
*/
// ------- Support sorting algorithm: Insertion Sort -------- //
function insertionSort(array){
    for(let index = 1; index < array.length; ++index){
      let key = array[index];
      let j = index - 1;
  
      while(j >= 0 && array[j] > key){
        array[j+1] = array[j];
        j -= 1;
      }
      array[j+1] = key;
    }

    return array;
}
// -----------------------------------------------------------//
function bucketSort(array) {
    let numberOfBuckets = Math.floor(Math.sqrt(array.length));
    let allBuckets = new Array(numberOfBuckets);
    let sorted = [];

    let maxValue = array[0];
    
    // Find max value:
    for(let i = 1; i < array.length; ++i) {
        if(array[i] > maxValue) { maxValue = array[i]; }
    }

    //Push elements into their specific buckets:
    for(let i = 0; i < array.length; ++i) {
        let location = Math.ceil((array[i]*numberOfBuckets)/maxValue);
        if(!allBuckets[location]) { allBuckets[location] = []; }

        allBuckets[location].push(array[i]);
    }

    //Sort individual buckets using insertion sort:
    allBuckets.forEach(bucket => {
        insertionSort(bucket);
        sorted = sorted.concat(bucket);
    });

    return sorted;
}

let array1 = [40,10,30,80,70,20,60,50,100];
let array2 = [0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434];
console.log(bucketSort(array1));
console.log(bucketSort(array2));