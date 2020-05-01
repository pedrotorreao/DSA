function getTotalX(a, b) {
  let min = a[0];
  let max = b[0];
  let seenA = new Map();
  let seenB = new Map();
  let count = 0;
  
  console.log('A:',a);
  console.log('B:',b);

  if (a.length === 1) {
    min = a[0];
  } else {
    for (let i = 0; i < a.length; i++) {
      if (min < a[i]) {
        min = a[i];
      }
    }
  }
  console.log('min:', min);

  if (b.length === 1) {
    max = b[0];
  } else {
    for (let i = 0; i < b.length; i++) {
      if (max > b[i]) {
        max = b[i];
      }
    }
  }
  console.log('max:', max);

  let element = min;

  console.log('Element b4 loop:', element);

  while (element >= min && element <= max) {
    for (let i = 0; i < a.length; i++) {//Problem: It does not account for the length of the secodnd array.
      if ((element % a[i] === 0) && (seenA.get(element) !== false))
      {
        seenA.set(element, true);
      } else {
        seenA.set(element, false);
      }
    }
    for (let i = 0; i < b.length; i++) {//Problem: It does not account for the length of the secodnd array.
      if ((b[i] % element === 0) && (seenB.get(element) !== false))
      {
        seenB.set(element, true);
      } else {
        seenB.set(element, false);
      }
    }
    element++;
  }

  for (let [key, value] of seenA.entries()) {
    if(seenA.get(key) && seenB.get(key)) {
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