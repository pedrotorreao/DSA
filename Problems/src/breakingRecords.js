/****************************************************************/
/*Problem: Breaking Records (Hackerrank) ********/
/****************************************************************/
/*
-- Summary: A player keeps a detailed note of how many times he/she breaks his/her season record for most points and least points in a game. Points scored in the first game establish her record for the season, and she begins counting from there.
-- Input(s): an integer array containing the scores which are in the same order as the games played. Ex.: scores = [5, 11, 25, 9] correspond to games 0 to 3.
-- Expected output(s): an integer array containing the numbers of times the records were broken. Index 0 is for breaking most points records, and index 1 is for breaking least points records.
-- Constraints: 1 <= n <= 1000; 0 <= score[i] <= 10^8
*/
function breakingRecords(scores) {
  let highest = scores[0];
  let lowest = scores[0];
  let countH = 0;
  let countL = 0;

  for (let i = 1; i < scores.length; i++) {
    if (scores[i] > highest) {
      highest = scores[i];
      countH++;
    } else if (scores[i] < lowest) {
      lowest = scores[i];
      countL++;
    }
  }

  return `${countH} ${countL}`;

}
console.log(breakingRecords([10,5,20,20,4,5,2,25,1]));
console.log(breakingRecords([3,4,21,36,10,28,35,5,24,42]));
console.log(breakingRecords([12,24,10,24]));