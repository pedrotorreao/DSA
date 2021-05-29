/****************************************************************/
/* Utility functions - Fractional Knapsack Problem ********/
/****************************************************************/

/****************************************************************/
/*************** Sorting Algorithm - Quick Sort *****************/
function quickSort(array, p = 0, q = array.length - 1) {
  //base case: if we've gone through all the array (or subarray for the recursive
  //calls), i.e., low position (p) have reached the high position (q), we're done.
  if (p < q) {
    //partition the array around the pivot (usually last element):
    let r = partition(array, p, q);
    //recursively call quickSort() for subarray with elements smaller than pivot.
    quickSort(array, p, r - 1);
    //recursively call quickSort() for subarray with elements greater than pivot.
    quickSort(array, r + 1, q);
  }
}

/**
 * Makes sure that all elements smaller than the pivot are on the left,
 * and all elements greater than the pivot are on right.
 */
function partition(array, p, q) {
  let pivot = q; //last element in the array
  let j = p; //first element in the array
  let i = p - 1; //pivot position after the partitioning

  while (j <= q) {
    if (array[j][1] <= array[pivot][1]) {
      ++i;
      [array[i], array[j]] = [array[j], array[i]];
    }
    ++j;
  }
  return i;
}
/****************************************************************/

module.exports.quickSort = quickSort;
