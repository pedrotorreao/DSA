/************************************************************/
/*Problem: Kangaroo  ********/
/************************************************************/
/*
Summary: Given two kangaroos on a number line ready to jump in the positive direction (i.e, toward positive infinity):
  - The first kangaroo starts at location x1 and moves at a rate of v1 meters per jump.
  - The second kangaroo starts at location x2 and moves at a rate of v2 meters per jump.
  You have to figure out a way to get both kangaroos at the same location at the same time as part of the show. 
  If it is possible, return YES, otherwise return NO.
  Note: The two kangaroos must land at the same location after making the same number of jumps.
Inputs: x1, x2, v1, v2
Output: 'YES' or 'NO' depending if the kangaroos will meet each other.
*/
function kangaroo(x1, v1, x2, v2) {
  if ((x1 > x2 && v1 > v2) || (x2 > x1 && v2 > v1)) {
    return 'NO';
  } //else if (x1 < 0 || x1 >= 10000 || x2 <= 0 || x2 > 10000 || v1 < 1 || v1 > 1000 || v2 < 1 || v2 > 1000 )
  let location1 = x1;
  let location2 = x2;
  let numberOfJumps1 = 0;
  let numberOfJumps2 = 0;
  let totalMax = x1 + v1 + x2 + v2;

  
  for (let i = 0; i < totalMax; i++) {
    location1 += v1;
    location2 += v2;
    numberOfJumps1++;
    numberOfJumps2++;
    if (location1 === location2 && numberOfJumps1 === numberOfJumps2) {
      console.log(numberOfJumps1);
      return 'YES';
    }
  }
  return 'NO';
}
//The result will be YES as long as either one of the sums can be divides by the other. 
//Ex: (x1+v1)%(x2+v2) == 0 or (x2+v2)/(x1+v1) == 0
console.log(kangaroo(0,3,4,2));
console.log(kangaroo(0,2,5,3));
console.log(kangaroo(10,3,2,5));
console.log(kangaroo(0,3,75,1));
console.log(kangaroo(0,8,124,4));
console.log(kangaroo(0,2,1023,1));
console.log(kangaroo(0,3,80,1));
console.log(kangaroo(1,4,123,2));