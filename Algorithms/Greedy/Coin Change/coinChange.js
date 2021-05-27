/****************************************************************/
/* Coin Change Problem - Greedy Algorithm ********/
/****************************************************************/
/* -- US Currency - USD (US Dollar):
Paper denominations:
  $1: 1 dollar      | $2: 2 dollars   | $5: 5 dollars
  $10: 10 dollars   | $20: 20 dollars | $50: 50 dollars
  $100: 100 dollars

Coin denominations:
	¢100: 1 dollar or 100 cents 
  ¢50: 50 cents or a half
	¢25:  25 cents or 1 quarter 
	¢10: 10 cents or 1 dime
	¢5: 5 cents or 1 nickel
	¢1: 1 cent or 1 penny
-- */
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
}

/* test 1: 
input: 23 dollars
output: 20 dollars + 2 dollars + 1 dollar */
console.log("--- test 1: ");
coinChange(23);
console.log("---\n");

/* test 2: 
input: 129.35 dollars
output: 20 dollars + 2 dollars + 1 dollar */
console.log("--- test 2: ");
coinChange(129.35);
console.log("---\n");

/* test 3: 
input: 0.47 dollars 
output: 20 dollars + 2 dollars + 1 dollar */
console.log("--- test 3: ");
coinChange(0.47);
console.log("---\n");
