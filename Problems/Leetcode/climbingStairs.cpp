/*********************************************************************************************/
/* Problem: Climbing Stairs (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are climbing a staircase. It takes n steps to reach the top. Each time you can either
  climb 1 or 2 steps. In how many distinct ways can you climb to the top?
  > Example 1:
    Input: n = 2
    Output: 2
    Explanation: There are two ways to climb to the top.
      1. 1 step + 1 step
      2. 2 steps

  > Example 2:
    Input: n = 3
    Output: 3
    Explanation: There are three ways to climb to the top.
      1. 1 step + 1 step + 1 step
      2. 1 step + 2 steps
      3. 2 steps + 1 step

 --Inputs:
  -int: non-negative integer N

--Outputs:
  -int: non-negative integer, the number of possible ways in which it is possible to climb the
        staircase.

--Constraints:
   1 <= n <= 45

--Reasoning: See comments below.

--Time complexity: O(N), where N is the number of steps in the staircase. This time complexity
  is achieved due to the memoization.

--Space complexity: O(N), since we allocated space to store the calculated results.

*/

#include <iostream>
#include <vector>

int climbHelper(int n, std::vector<int> &cache) {
  // base case: given a value n, in case we've already calculated the result for it, i.e.,
  // cache[n] is a valid result, we just return this result:
  if (n < cache.size())
    return cache.at(n);

  // recursive case: calculate the result for the case where we climb 1 step:
  int jumpOne = climbHelper(n - 1, cache);
  // recursive case: calculate the result for the case where we climb 2 step:
  int jumpTwo = climbHelper(n - 2, cache);
  // sum the result of both approaches:
  int ways = jumpOne + jumpTwo;
  // chache the result so we don;t have to calculate it again:
  cache.push_back(ways);
  // return the result:
  return cache.at(n);
}

int climbStairs(int n) {
  // initialize a cache to store the results calculated along the way. Since n >= 1 and
  // for a staircase of only 1 step (n=1) there is only one possible way to climb, i.e., to
  // take 1 step, cache[n] for n <= 1 is 1.
  std::vector<int> cache(2, 1);

  return climbHelper(n, cache);
}

int main() {
  int n{2};
  std::cout << "Number of steps: " << n << "\tPossible ways to climb: " << climbStairs(n) << "\n";

  n = 4;
  std::cout << "Number of steps: " << n << "\tPossible ways to climb: " << climbStairs(n) << "\n";

  n = 5;
  std::cout << "Number of steps: " << n << "\tPossible ways to climb: " << climbStairs(n) << "\n";

  return 0;
}

/*  -- DRY RUN --
cs(4):
    n < 2 ? F

    j1 = cs(3):--------------------------: 3
        n < 2 ? F
        j1 = cs(2):----------------------: 2
            n < 2 ? F
            j1 = cs(1):------------------: 1
                n < 2 ? T:
                    return cache[1] = 1
            j2 = cs(0):------------------: 1
                n < 2 ? T:
                    return cache[0] = 1
            ways = j1 + j2 = 2
            cache.push_back(2) ----------: [1,1,2]
            return cache[2] = 2
        j2 = cs(1):----------------------: 1
            n < 3 ? T:
                return cache[1] = 1
        ways = j1 + j2 = 3
        cache.push_back(3) --------------: [1,1,2,3]
        return cache[3] = 3
    j2 = cs(2):--------------------------: 2
        n < 4 ? T:
            return cache[2] = 2
    ways = j1 + j2 = 5
    cache.push_back(5) ------------------: [1,1,2,3,5]
*/