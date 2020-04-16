/************************************************************/
/*Problem: Apples and Oranges  ********/
/************************************************************/
function countApplesAndOranges(s, t, a, b, apples, oranges) {
  //Sam's house is between 's' and 't'
  //The apple tree is located at 'a' (to the left of the house)
  //The orange tree is located at 'b' (to the right of the house)
  //The fruits fall 'd' units of distance from the its three.
  let applesOver = 0;
  let orangesOver = 0;
  let distanceApples = 0;
  let distanceOranges = 0;
  for (let i = 0; i < apples.length; i++) {
    distanceApples = a + apples[i];
    if (distanceApples >= s && distanceApples <= t ) {
      applesOver++;
    }
  }
  for (let i = 0; i < oranges.length; i++) {
    distanceOranges = b + oranges[i];
    if (distanceOranges >= s && distanceOranges <= t ) {
      orangesOver++;
    }
  }
  console.log(`${applesOver}\n${orangesOver}`);
  }
  countApplesAndOranges(7, 11, 5, 15, [-2,2,1], [5,-6]);
  countApplesAndOranges(7, 10, 4, 12, [2,3,-4], [3,-2,-4]);