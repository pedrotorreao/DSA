/****************************************************************/
/* Coin Change Problem - Greedy Algorithm ********/
/****************************************************************/

function coinChange(valueInDollars) {
  let currency = [10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1];
  let change = [];
  let valueInCents = valueInDollars * 100;

  while (valueInCents > 0) {
    let maxDen = currency.find((den) => den <= valueInCents);
    change.push(maxDen);
    valueInCents -= maxDen;
  }

  change.forEach((cng) => {
    if (cng % 100 === 0) {
      console.log(`${cng / 100} dollars`);
    } else {
      console.log(`${cng} cents`);
    }
  });

  console.log(`Number of denom. needed: ${change.length}`);
}

/* test 1: 
input: 23 dollars
output: $20 + $2 + $1 -> 3 denom.*/
console.log("--- test 1: ");
coinChange(23);
console.log("---\n");

/* test 2: 
input: 129.35 dollars
output: $100 + $20 + $5 + $2 + $2 + ¢25 + ¢10 -> 7 denom. */
console.log("--- test 2: ");
coinChange(129.35);
console.log("---\n");

/* test 3: 
input: 0.47 dollars 
output: ¢25 + ¢10 + ¢10 + ¢1 + ¢1 -> 5 denom. */
console.log("--- test 3: ");
coinChange(0.47);
console.log("---\n");
