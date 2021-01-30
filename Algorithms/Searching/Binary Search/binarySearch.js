/****************************************************************/
/* Algorithm: Binary Search   ********/
/****************************************************************/
/*
>> Definition: 
  Search algorithm that finds the position of a target value within a sorted array by repeatedly 
  dividing the search interval in half. 
>> Steps:
    1 - Binary search compares the target value to the middle element of the array. 
    2 - If they are not equal, the half in which the target cannot lie is eliminated and the search 
    continues on the remaining half, again taking the middle element to compare to the target value, 
    and repeating this until the target value is found. 
    3 - If the search ends with the remaining half being empty, the target is not in the array. 
  Binary search runs in logarithmic time in the worst case, making O(log n) comparisons, where n is 
  the number of elements in the array. Binary search is faster than linear search except for small 
  arrays. However, the array must be SORTED first to be able to apply binary search.
>> Time complexity:O(log n)
>> Space complexity: O(1)
*/
function binarySearch(target, array, start, end) {
  if (start === end) {
    if (array[start] === target) {
      return `Target value ${target} is at position ${start} in the array.`;
    } else {
      return 'target number not present in array';
    }
  } else if (start > end) {
      return 'ERROR: start value should be less than end value!';
  } else {
      let midPosition = Math.round((start + end)/2);
      let midValue = array[midPosition];

      if (midValue > target) {
        return binarySearch(target, array, start, midPosition-1);
      } else if (midValue < target) {
        return binarySearch(target, array, midPosition+1, end);
      } else if (midValue === target) {
        return `Target value ${target} is at position ${midPosition} in the array.`;
      }
  }
}
// INPUT - Sorted array:
let array = [11, 23, 30, 45, 51, 62, 70, 89, 95, 100, 110];

// TEST CASES:
// case 1 - START = END and TARGET is on the array:
console.log(binarySearch(45, array, 3, 3));

// case 2 - START = END and TARGET is NOT on the array:
console.log(binarySearch(12, array, 0, 0));

// case 3.1 - START = 1st position and END = last position. Short search, mid value is target:
console.log(binarySearch(62, array, 0, array.length-1));

// case 3.2 - START = 1st position and END = last position. Longest search, target is 1st or last elements:
console.log(binarySearch(11, array, 0, array.length-1));
console.log(binarySearch(110, array, 0, array.length-1));

// case 4 - START > END: Not a valid search:
console.log(binarySearch(89, array, 3, 1));