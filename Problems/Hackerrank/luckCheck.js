/****************************************************************/
/*Problem: Luck Check  ********/
/****************************************************************/
/*
-- Summary: code snippet to check my bets
-- Input(s): array of integers containing my bets
-- Expected output(s): number of hits
-- Constraints:
*/

function luckCheck (bet) {
	let num = [7,17,29,55,78];
	let map = {};
	let yourLuck = 0;

	for (let i = 0; i < num.length; i++) {
		let item = num[i];
		if (!map[item]) {
			map[item] = true;
		}
	}

	for (let i = 0; i < bet.length; i++) {
		let luckyNum = bet[i];
		if (map[luckyNum]) {
			yourLuck++;
		}
	}
	console.log(yourLuck);
}
// -- BETS:
// 1:
luckCheck([4,9,30,52,59]);
// 2:
luckCheck([6,7,23,34,38]);
// 3:
luckCheck([5,19,31,56,69]);
// 4:
luckCheck([25,28,29,34,48]);
// 5:
luckCheck([18,21,25,31,47]);
// 6:
luckCheck([1,15,41,47,53]);
// 7:
luckCheck([7,23,24,28,69]);
// 8:
luckCheck([31,32,41,71,75]);
// 9:
luckCheck([8,19,21,28,57]);
// 10:
luckCheck([3,9,15,21,56]);
// 11:
luckCheck([59,60,66,67,73]);
// 12:
luckCheck([42,44,62,76,77]);
// 13:
luckCheck([1,35,45,47,65]);
// 14:
luckCheck([9,26,40,44,57]);
// 15:
luckCheck([10,30,34,43,79]);
// 16:
luckCheck([13,36,55,58,62]);