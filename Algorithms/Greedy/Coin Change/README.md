## Coin Change Problem

Check out the code for the solution [here](/Algorithms/Greedy/Coin%20Change/coinChange.js).

### Problem Statement

Given an amount `M` of USD, we want to make change for $M dollars. Also, consider that we have infinite supply of each denomination, i.e. we have infinite amount of the following coins/notes:

|     |     |     | Notes (dollars) |     |     |      |
| :-: | :-: | :-: | :-------------: | :-: | :-: | :--: |
| $1  | $2  | $5  |       $10       | $20 | $50 | $100 |

|     |     |     | Coin (cents) |     |      |
| :-: | :-: | :-: | :----------: | :-: | :--: |
| ¢1  | ¢5  | ¢10 |     ¢25      | ¢50 | ¢100 |

Determine which is the minimum number of coins/papers needed to provide the change for `M` dollars?

### Example

Consider `M = $67.5`, there are many ways to provide this amount given the denominations that we have available, for example:

> example #1: `$20 + $20 + $20 + $5 + $2 + ¢50 = $67.5` -- 6 denominations
>
> example #2: `$20 + $10 + $10 + $20 + $5 + $2 + ¢50 = $67.5` -- 7 denominations

However, the best way to provide this change is the following:

> solution: `$50 + $10 + $5 + $2 + ¢50 = $67.5` -- 5 denominations

A brute force approach would require us to try out all the possible combinations of changes in order to find the best solution. A better alternative would be to use a greedy approach. This approach consists of the following steps:

1. Find the largest denomination `L` which is also smaller than `M`.

2. Add this found denomination to the result `res`.

3. Subtract `L` from `M`.

4. Repeat steps 1 to 3 while `M != 0`.

First iteration:

1. > `L = $50`
2. > `res = [$50]`
3. > `M = M - L = $67.5 - $50 = $17.5`

Second iteration:

1. > `L = $10`
2. > `res = [$50, $10]`
3. > `M = M - L = $17.5 - $10 = $7.5`

Third iteration:

1. > `L = $5`
2. > `res = [$50, $10, %5]`
3. > `M = M - L = $7.5 - $5 = $2.5`

Fourth iteration:

1. > `L = $2`
2. > `res = [$50, $10, %5, $2]`
3. > `M = M - L = $2.5 - $2 = $0.5 = ¢50`

Fifth iteration:

1. > `L = ¢50`
2. > `res = [$50, $10, %5, $2, ¢50]`
3. > `M = M - L = ¢50 - ¢50 = 0` -- end

### Pseudocode

```
coinChange(M):
    > initialize result array as empty:
      res = []
    > iterate while M is different from zero:
      while M != 0:
        > get the largest denomination possible:
          L = largest denomination <= M
        > add L to the result:
          res.push(L)
        > substract L from M:
          M = M - L
      end while
    > return the amount of coins/notes needed:
      return res.length()
end function
```

It is worth mentioning, however, that this approach may not return the overall best result, it will pick the best option at each step hoping that it might lead to the best result. For example:

> amount to make change: `M = $30`
>
> available denominations: `[$25, $15, $1]`

Since the greedy approach always takes the best option available at each step, it'll begin by taking `$25`, which is also less than `M` so it satisfies the requirement. The problem with this approach is that, after updating the value of `M` to `M-$25`, now the only available denomination which satisfies the requirement of being less than `M` is `$1`:

> greedy solution: `$25 + $1 + $1 + $1 + $1 + $1 = $30` -- 6 notes

However, not being greedy and not taking the best option at the first step ends up providing a way better solution in which only two notes are needed:

> optimal solution: `$15 + $15 = $30` -- 2 notes

### Time complexity

- O(M) - where `M` is the amount we desire to make change for.

### Space complexity

- O(R) - where `R` is the length of the result array.
