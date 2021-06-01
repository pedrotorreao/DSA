/****************************************************************/
/*Problem: Cats and a Mouse (HR)  ********/
/****************************************************************/
/*
-- Summary:
You are given q queries in the form of x, y, and z representing the respective positions for cats A and B, and for mouse C. Complete the function catAndMouse to return the appropriate answer to each query, which will be printed on a new line. If cat A catches the mouse first, print Cat A. If cat B catches the mouse first, print Cat B. If both cats reach the mouse at the same time, print Mouse C as the two cats fight and mouse escapes. For example, cat A is at position x=2 and cat B is at y=5. If mouse C is at position z=4, it is 2 units from cat A and 1 unit from cat B. Cat B will catch the mouse.
-- Input(s):
x: an integer, Cat A's position
y: an integer, Cat B's position
z: an integer, Mouse C's position
-- Expected output(s):
For each query, return Cat A if cat A catches the mouse first, Cat B if cat B catches the mouse first, or Mouse C if the mouse escapes.
-- Constraints:
*/
function catAndMouse(x, y, z) {
  if (Math.abs(x-z) < Math.abs(y-z)) {
    console.log('Cat A');
  } else if (Math.abs(x-z) > Math.abs(y-z)) {
    console.log('Cat B');
  } else {
    console.log('Mouse C');
  }
}
// TEST CASES:
catAndMouse(2, 5, 4); // should print Cat B
catAndMouse(1, 2, 3); // should print Cat B
catAndMouse(1, 3, 2); // should print Mouse C
catAndMouse(15, 21, 17); // should print Cat A