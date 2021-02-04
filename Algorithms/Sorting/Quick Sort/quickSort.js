/****************************************************************/
/* Algorithm: Merge Sort  ********/
/****************************************************************/
/**
 * Definition:
 * 
 * Steps: 
 *  1-  
 * Time complexity -  
 * Space complexity - 
 * 
 */


/**
 * 
 * @param {[]} array 
 * @param {number} first 
 * @param {number} last 
 * @returns {[]} sorted array
 */
function quickSort(array,p = 0,q = array.length-1){
    if(p < q) {
        let r = partition(array,p,q);
        quickSort(array,p,r-1);
        quickSort(array,r+1,q);
    }
    return array;
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
    let pivot = q;
    let j = p;
    let i = p - 1;

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
let array1 = [30,20,40,10,80,50,15];
console.log(quickSort(array1));

//TEST 2:
let array2 = [1,35,11,0,-5,98,5];
console.log(quickSort(array2));

//TEST 3:
let array3 = [3,7,8,5,2,1,5,4];
console.log(quickSort(array3));