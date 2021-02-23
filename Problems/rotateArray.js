/************************************************************/
/*Problem: Rotate Array (HR)  ********/
/************************************************************/
/*
-- Summary:
  A left rotation operation on an array shifts each of the array's elements 1 unit to the left. 
  For example, if 2 left rotations are performed on array [1,2,3,4,5], then the array would 
  become [3,4,5,1,2]. Note that the lowest index item moves to the highest index in a rotation. 
  This is called a circular array. Given an array 'a' of integers and a number, d, perform d left 
  rotations on the array. Return the updated array to be printed as a single line of space-separated 
  integers.
-- Input(s): 
    a: array containing n integers
    d: the number of rotations 
-- Expected output(s):
    a': rotated array  
-- Constraints:
    (1 ≤ n ≤ 10^6), (1 ≤ d ≤ n), (1 ≤ a[i] ≤ 10^6)
*/
function rotLeft(a, d) {
    if(a.length === d) return a;
    
    let rotate = a.splice(0,d);
    rotate = a.concat(rotate);
    
    return rotate;
}

let a1 = [1,2,3,4,5];
let a1_mod = rotLeft(a1,4);
console.log(a1_mod);

let a2 = [0,0,0,0,1];
let a2_mod = rotLeft(a2,3);
console.log(a2_mod);

