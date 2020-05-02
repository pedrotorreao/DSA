/************************************************************/
/*Problem: Between To Sets  ********/
/************************************************************/
/*
You will be given two arrays of integers and asked to determine all integers that satisfy the following two conditions:

1. The elements of the first array are all factors of the integer being considered. This means that 
(integer % array[index]) == 0.
2. The integer being considered is a factor of all elements of the second array. This means that 
(array[index] % integer) == 0.

These numbers are referred to as being between the two arrays. You must determine how many such numbers exist.
*/
function getTotalX(a, b) {
  let min = a[0];
  let max = b[0];
  let seenA = new Map();
  let seenB = new Map();
  let count = 0;
  
  console.log('A:',a);
  console.log('B:',b);

  if (a.length === 1) { //If there is only one element, make this the minimum value.
    min = a[0];
  } else {
    for (let i = 0; i < a.length; i++) { 
      if (min < a[i]) { //In case there are more than one element, make the largest one the min.
        min = a[i];
      }
    }
  }
  console.log('min:', min);

  if (b.length === 1) { //If there is only one element, make this the maximum value.
    max = b[0];
  } else {
    for (let i = 0; i < b.length; i++) {
      if (max > b[i]) { //In case there are more than one element, make the smallest one the min.
        max = b[i];
      }
    }
  }
  console.log('max:', max);

  let element = min; //Begin analyzing elements from the min value.

  console.log('Element b4 loop:', element);

  while (element >= min && element <= max) {
    for (let i = 0; i < a.length; i++) {
      if ((element % a[i] === 0) && (seenA.get(element) !== false)) 
      // Check if the elements of the first array are factors of the integer being considered and assign them a boolean.
      // Also, check if this element wasn't already assigned a 'false' value which indicates that at least one of the
      // elements of the array is not a factor of the element being considered. 
      {
        seenA.set(element, true); // Map the element with a 'true' value to indicate that is meets the criteria.
      } else {
        seenA.set(element, false); // Map the element with a 'false' value to indicate that is doesn't meet the criteria.
        // Also, assigning it a 'false' value prevents it of being considered a valid element when testing for a different
        // array element.
      }
    }
    for (let i = 0; i < b.length; i++) {
      if ((b[i] % element === 0) && (seenB.get(element) !== false))
      // Check if the integer being considered is a factor of all elements of the second array and assign them a boolean.
      // Also, check if this element wasn't already assigned a 'false' value which indicates that for at least one of the
      // elements of the array the integer being considered is not a factor.
      {
        seenB.set(element, true); // Map the element with a 'true' value to indicate that is meets the criteria.
      } else {
        seenB.set(element, false); // Map the element with a 'false' value to indicate that is doesn't meet the criteria.
        // Also, assigning it a 'false' value prevents it of being considered a valid element when testing for a different
        // array element.
      }
    }
    element++; // Increment the element and test again.
  }

  for (let [key, value] of seenA.entries()) {
    if(seenA.get(key) && seenB.get(key)) { // Check both maps for elements with 'true' boolean values assigned to them.
    //Since the elements being considered are the same for both, if it has a 'true' value assigned to them in both maps,
    //it means that the element in question satisfied both criteria, i.e., the elements of the first array are factors of //the integer being considered and the integer being considered is a factor of all elements of the second array.
      count++;
    }
  }
  console.log(seenA);
  console.log(seenB);
  

  return count;
}
//console.log(getTotalX([2,6],[24,36])); //Passed
//console.log(getTotalX([2,4],[16,32,96])); //Passed
//console.log(getTotalX([2],[20,30,12])); //Failed. Expected output: 1  -> Passed
//console.log(getTotalX([3,9,6],[36,72])); //Failed. Expected output: 2
//console.log(getTotalX([1],[100])); //Failed. Expected output: 9 [1,2,4,5,10,20,25,50,100]  -> Passed
//console.log(getTotalX([1],[72,48])); //Failed. Expected output: 8