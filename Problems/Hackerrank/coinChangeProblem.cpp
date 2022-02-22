/*********************************************************************************************/
/* Problem: The Coin Change Problem (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an amount and the denominations of coins available, determine how many ways change can
  be made for the amount. There is a limitless supply of each coin type.

  > Example:
      amount = 3     coins = [8,3,1,2]
      There are 3 ways to make change for n=3: {1,1,1}, {1,2} and {3}.

--Input:
  int n: the amount to make change for
  int c[m]: the available coin denominations

--Output:
  int: the number of ways to make change

--Constraints:
  1<=c[i]<=50
  1<=n<=250
  1<=m<=50
  Each c[i] is guaranteed to be distinct.

--Reasoning: See comments below.

--Time complexity:
  O(N*M), where N is the amount to make change for and M is the size of the coins array.

--Space complexity:
  O(N), due to the N-sized array used to store the number of possible combinations for each amount.

*/

#include <iostream>
#include <vector>

long coinChanges(int n, std::vector<long> c) {
  std::vector<long> dp(n + 1, 0);
  dp.at(0) = 1;

  for (const auto &coin : c) {
    for (int amount{1}; amount < dp.size(); ++amount) {
      if (amount >= coin) {
        dp.at(amount) += dp.at(amount - coin);
      }
    }
  }

  return dp.at(n);
}

int main() {
  // test cases:
  int amount = 3;
  std::vector<long> coins{8, 3, 1, 2};
  std::cout << "Total number of ways to make change for " << amount
            << ": " << coinChanges(amount, coins) << "\n"; // 3

  amount = 10;
  coins = {2, 5, 3, 6};
  std::cout << "Total number of ways to make change for " << amount
            << ": " << coinChanges(amount, coins) << "\n"; // 5

  amount = 166;
  coins = {5, 37, 8, 39, 33, 17, 22, 32, 13, 7, 10, 35, 40, 2, 43, 49, 46, 19, 41, 1, 12, 11, 28};
  std::cout << "Total number of ways to make change for " << amount
            << ": " << coinChanges(amount, coins) << "\n"; // 96190959

  amount = 75;
  coins = {25, 10, 11, 29, 49, 31, 33, 39, 12, 36, 40, 22, 21, 16, 37, 8, 18, 4, 27, 17, 26, 32, 6, 38, 2, 30, 34};
  std::cout << "Total number of ways to make change for " << amount
            << ": " << coinChanges(amount, coins) << "\n"; // 16694

  amount = 219;
  coins = {36, 10, 42, 7, 50, 1, 49, 24, 37, 12, 34, 13, 39, 18, 8, 29, 19, 43, 5, 44, 28, 23, 35, 26};
  std::cout << "Total number of ways to make change for " << amount
            << ": " << coinChanges(amount, coins) << "\n"; // 16694

  return 0;
}