/****************************************************************/
/*Binary Search   ********/
/****************************************************************/
function binarySearch(target, array, start, end) {
  if (start === end) {
    if (array[start] === target) {
      return start;   //case 1
    } else {
      return 'target number not present in array';    //case 2
    }
  } else if (start > end) {
      return 'ERROR: start value should be less than end value!'; //case 5
  } else {
      let midPosition = Math.round((start + end)/2);
      let midValue = array[midPosition];

      if (midValue > target) {
        return binarySearch(target, array, start, midPosition-1);
      } else if (midValue < target) {
        return binarySearch(target, array, midPosition+1, end);
      } else if (midValue === target) {
        return `Target value ${target} is at position ${midPosition} in the array.`; //case 3
      }
  }
}

let array = [11, 23, 30, 45, 51, 62, 70, 89, 95, 100, 110];
// case 1:
//console.log(binarySearch(11, array, 0, 0));
// case 2:
//console.log(binarySearch(12, array, 0, 0));
// case 3:
//console.log(binarySearch(62, array, 0, 10));
// case 4:
console.log(binarySearch(89, array, 0, array.length-1));
// case 5:
//console.log(binarySearch(89, array, 3, 1));