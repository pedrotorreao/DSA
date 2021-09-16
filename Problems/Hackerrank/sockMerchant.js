/****************************************************************/
/*Problem: Sock Merchant (HR)  ********/
/****************************************************************/
/*
-- Summary:
John works at a clothing store. He has a large pile of socks that he must pair by color for sale. Given an array of integers representing the color of each sock, determine how many pairs of socks with matching colors there are.
For example, there are n=7 socks with colors ar=[1,2,1,2,1,3,2]. There is one pair of color 1 and one of color 2. There are three odd socks left, one of each color. The number of pairs is 2.
-- Input(s):
The first line contains an integer n, the number of socks represented in ar. The second line contains n space-separated integers describing the colors ar[i] of the socks in the pile.
-- Expected output(s):
Complete the sockMerchant function in the editor below. It must return an integer representing the number of matching pairs of socks that are available.
-- Constraints:
*/
function sockMerchant(n, ar) {
  let map = {};
  let pairs = 0;

  for (let i = 0; i < ar.length; i++) {
    const item = ar[i];
    if (!map[item]) {
      map[item] = 1;
    } else {
      map[item] += 1;
    }
  }
  //console.log(map);

  for (let i = 0; i < ar.length; i++) {
    const item = ar[i];
    if (map[item] % 2 === 0 && map[item] > 0) {
      pairs += 1;
      map[item] = map[item]-2;
    } else if (map[item] > 2) {
      pairs += 1;
      map[item] = map[item]-2;
    }
  }

  console.log(pairs);
}
sockMerchant(7,[1,2,1,2,1,3,2]);
sockMerchant(9,[10,20,20,10,10,30,50,10,20]);
sockMerchant(1,[10]);
sockMerchant(3,[10,10,10]);
sockMerchant(9,[1,20,25,10,11,30,50,12,1]);