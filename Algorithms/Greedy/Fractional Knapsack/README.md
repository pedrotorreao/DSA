## Fractional Knapsack Problem

Check out the code for the solution [here](/Algorithms/Greedy/Fractional%20Knapsack/fractionalKnapsack.js).

### Problem Statement

Given a set of items, each item having a value `Vi` and a weight `Wi` associated with it, fill a knapsack such that its total value, `Vt`, is maximized without exceeding a predetermined maximum weigh, `Wmax`. Consider that it is possible to break down the items in order to maximize the total value.

### Example

Consider the following items and their corresponding values and weights, let's determine `Vt` for a `Wmax = 50kg`:

|     Item      |      A      |      B      |      C      |
| :-----------: | :---------: | :---------: | :---------: |
| value - `Vi`  | `Va = $100` | `Vb = $120` | `Vc = $60`  |
| weight - `Wi` | `Wa = 20kg` | `Wb = 30kg` | `Wc = 10kg` |

We would be tempted to think that the best solution would be to just take items `A` and `B` which, at first glance, would amount the largest sum, totaling `$220`, while still not exceeding `Wmax`. However, remember that we can break items down into fractional parts in order to maximize our total value.

First, we determine the items value per weight, the greater the `$` per `kg`, the more valuable the item is:

| Ratio = $/kg | A | B | C |
| :-: | :-: | :-: | :-: |
| ratio - `ri` | `ra = $100/20kg = 5($/kg)` | `rb = $120/30kg = 4($/kg)` | `rc = $60/10kg = 6($/kg)` |

Next, we select the items based on their ratios, from largest to lowest. In this case, `C` has the highest ratio - `6($/kg)`, and as its total weight `Wc` does not exceed `Wmax`, we take the whole item `C`.

> `Vt = Vc = $60`
>
> `Wt = Wc = 10kg < Wmax`

Next we have item `A` with a ratio of `5($/kg)`. Again, adding the whole item `A` to the knapsack already containing `C` does not exceed `Wmax`.

> `Vt = Vc + Va = $60 + $100 = $160`
>
> `Wt = Wc + Wa = 10kg + 20kg = 30kg < Wmax`

We now have `20kg` (`Wmax-Wt = 50kg-30kg`) of weight left that can be added to the knapsack. However, our last item, item `B`, weights `30kg`, so it exceeds `Wmax` if added whole. As we are allowed to break the items down, we take only the amount of `B` which is possible to fit in the knapsack, `Wb' = 20kg`. To determine the value `Vb'` corresponding to `Wb'`, we just need to calculate the product of `Wb'` by the ratio of item `B` which is `4($/kg)`. So,

> `Vt = Vc + Va + Vb' = Vc + Va + (Wb'*rb) = $60 + $100 + $(20*4) = $240`
>
> `Wt = Wc + Wa + Wb'= 10kg + 20kg + 20kg = 50kg`

Summarizing this approach we have the following steps:

1. Calculate the ratio (`value/weight`) for each item.
2. Sort the items based on their ratios in non-ascending order.
3. Select the items with highest ratios and add them to the solution without exceeding the maximum capacity, `Wmax`.
4. At the end, add as much fractional part of the next item as it is possible without exceeding `Wmax`.

### Pseudocode

```
fractionalKnapsack(items[], Wmax):
    > create a new empty array for storing the ratios:
        ratio = []
    > calculate the ratio for each item:
        for each item in items[]:
            ratio[item] = (item value)/(item weight)
        end for
    > sort items based on their ratios:
        sort(ratio)
    > go over sorted ratio[] adding the items w/ highest ratio to the solution:
        for i=0 to i=(number of items-1) and Wmax is not exceeded:
          > check if max. weight Wmax is not being exceeded:
            if (totalWeight + currentWeight) < Wmax:
                solution += item value
                totalWeight += currentWeight
          > break item down in case Wmax is exceeded:
            else:
                solution += fractional item value
                totalWeight += fractional currentWeight
            end
        end for
    > return solution total value:
        return solution
end function
```

### Time complexity

- O(n\*log(n)), `n` being the number of items to be sorted based on their ratios.

### Space complexity

- O(n), `n` being the size of the `ratio` array.
