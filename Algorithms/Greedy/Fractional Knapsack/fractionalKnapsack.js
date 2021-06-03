/****************************************************************/
/* Fractional Knapsack Problem - Greedy Algorithm ********/
/****************************************************************/

const { quickSort } = require("./fractionalKnapsack_util");

function fractionalKnapsack(loots, maxWeight) {
  if (!loots.length) {
    console.log("\n... there is nothing to loot :(");
    return;
  }

  let ratio = [];
  let totalWeight = 0;
  let totalValue = 0;
  let knapsack = [];

  loots.forEach((loot) => {
    let r = loot[1] / loot[0];

    ratio.push([loot, r]);
  });

  quickSort(ratio);

  for (let i = ratio.length - 1; i >= 0 && totalWeight < maxWeight; --i) {
    let currentWeight = ratio[i][0][0]; // get weight
    let currentValue = ratio[i][0][1]; // get value

    if (totalWeight + currentWeight < maxWeight) {
      knapsack.push(["full", ratio[i][0]]);
      totalWeight += currentWeight;
      totalValue += currentValue;
    } else {
      let fracWeight = maxWeight - totalWeight;
      let fracValue = fracWeight * ratio[i][1]; // currentDensity: ratio[i][1]

      totalWeight += fracWeight;
      totalValue += fracValue;

      knapsack.push(["frac", ratio[i][0]]);
    }
  }

  console.log("\nKnapsack content: ");
  console.log(knapsack);
  console.log("Total value: ", totalValue);
}

// each loot is represented by a pair (weight, value):
let loot_1 = [
  /*loot A*/ [20, 100],
  /*loot B*/ [30, 120],
  /*loot C*/ [10, 60]
];

fractionalKnapsack(loot_1, 50);

let loot_2 = [
  /*loot A*/ [20, 100],
  /*loot B*/ [30, 120],
  /*loot C*/ [10, 60],
  /*loot D*/ [40, 120]
];

fractionalKnapsack(loot_2, 50);

let loot_3 = [];

fractionalKnapsack(loot_3, 50);
