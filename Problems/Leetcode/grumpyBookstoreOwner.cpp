/***********************************************************************************/
/* Problem: LC 1052. Grumpy Bookstore Owner ****************************************/
/***********************************************************************************/
/*
--Problem statement:
  There is a bookstore owner that has a store open for 'n' minutes. Every minute, some
  number of customers enter the store. You are given an integer array 'customers' of
  length 'n' where 'customers[i]' is the number of the customer that enters the store at
  the start of the ith minute and all those customers leave after the end of that minute.

  On some minutes, the bookstore owner is grumpy. You are given a binary array 'grumpy'
  where 'grumpy[i]' is 1 if the bookstore owner is grumpy during the ith minute, and is
  0 otherwise.

  When the bookstore owner is grumpy, the customers of that minute are not satisfied,
  otherwise, they are satisfied. The bookstore owner knows a secret technique to keep
  themselves not grumpy for 'minutes' consecutive minutes, but can only use it once.

  Return the maximum number of customers that can be satisfied throughout the day.


  > Example 1:
      Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
      Output: 16
      Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes.
      The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

  > Example 2:
      Input: customers = [1], grumpy = [0], minutes = 1
      Output: 1

--Inputs:
  -int[]: array of integers 'customer'
  -int[]: array of binary 'grumpy'
  -int: number of consecutive minutes the owner can use his technique to not get grumpy

--Output:
  -int: maximum number of customers that can be satisfied throughout the day

--Constraints:
    :: n == customers.length == grumpy.length
    :: 1 <= minutes <= n <= 2 * 104
    :: 0 <= customers[i] <= 1000
    :: grumpy[i] is either 0 or 1

--Reasoning: See comments below.

--Time complexity: O(N), where N is the size of arrays 'customers' and 'grumpy'.

--Space complexity: O(1), since no additional input dependent space is allocated.

*/

#include <iostream>
#include <vector>

int maxSatisfied(std::vector<int> &customers, std::vector<int> &grumpy, int minutes) {
  const int T = customers.size();

  int always_satisfied{0}, additionaly_satisfied{0}, maybe_satisfied{0};

  for (int t{0}; t < T; ++t) {
    // owner not grumpy (grumpy[i]=0), customer is always satisfied.
    // total number of customers which are always satisfied:
    always_satisfied += (1 - grumpy.at(t)) * customers.at(t);

    // owner is grumpy, so customers could be satisfied if he keeps it under control.
    // sum of customers that could be satisfied if owner don't get grumpy:
    maybe_satisfied += (grumpy.at(t) * customers.at(t));

    // sliding window with 'width=minutes' to count customers that could be satisfied
    // if owner manages to behave when he gets grumpy:
    if (t >= minutes)
      maybe_satisfied -= (grumpy.at(t - minutes) * customers.at(t - minutes));

    // keep track of the maximum number of addistional customers that could be satisfied
    // when grumpy[i]=1 and the owner uses his technique to keep it nice:
    additionaly_satisfied = std::max(additionaly_satisfied, maybe_satisfied);
  }

  return always_satisfied + additionaly_satisfied;
}

int main() {
  std::vector<int> customers{1, 0, 1, 2, 1, 1, 7, 5};
  std::vector<int> grumpy{0, 1, 0, 1, 0, 1, 0, 1};
  int minutes{3}, expected{16};
  int res = maxSatisfied(customers, grumpy, minutes);
  std::cout << "Max. # of customer satisfied: " << res
            << "\t::Expected: " << expected << "\t"
            << (expected == res ? "--PASSED" : "--FAILED") << "\n";

  customers = {1, 21, 1, 2, 1, 1, 7, 5};
  grumpy = {0, 1, 1, 1, 0, 1, 1, 1};
  minutes = 3;
  expected = 26;
  res = maxSatisfied(customers, grumpy, minutes);
  std::cout << "Max. # of customer satisfied: " << res
            << "\t::Expected: " << expected << "\t"
            << (expected == res ? "--PASSED" : "--FAILED") << "\n";

  customers = {1, 1, 1, 2, 3, 1, 4, 0};
  grumpy = {0, 1, 1, 0, 1, 0, 1, 1};
  minutes = 3;
  expected = 11;
  res = maxSatisfied(customers, grumpy, minutes);
  std::cout << "Max. # of customer satisfied: " << res
            << "\t::Expected: " << expected << "\t"
            << (expected == res ? "--PASSED" : "--FAILED") << "\n";

  customers = {4, 10, 10};
  grumpy = {1, 1, 0};
  minutes = 2;
  expected = 24;
  res = maxSatisfied(customers, grumpy, minutes);
  std::cout << "Max. # of customer satisfied: " << res
            << "\t::Expected: " << expected << "\t"
            << (expected == res ? "--PASSED" : "--FAILED") << "\n";

  customers = {2, 6, 6, 9};
  grumpy = {0, 0, 1, 1};
  minutes = 1;
  expected = 17;
  res = maxSatisfied(customers, grumpy, minutes);
  std::cout << "Max. # of customer satisfied: " << res
            << "\t::Expected: " << expected << "\t"
            << (expected == res ? "--PASSED" : "--FAILED") << "\n";

  customers = {9, 10, 4, 5};
  grumpy = {1, 0, 1, 1};
  minutes = 1;
  expected = 19;
  res = maxSatisfied(customers, grumpy, minutes);
  std::cout << "Max. # of customer satisfied: " << res
            << "\t::Expected: " << expected << "\t"
            << (expected == res ? "--PASSED" : "--FAILED") << "\n";

  return 0;
}