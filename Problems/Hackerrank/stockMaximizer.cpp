/*********************************************************************************************/
/* Problem: Stock Maximizer (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Your algorithms have become so good at predicting the market that you now know what the share 
  price of Wooden Orange Toothpicks Inc. (WOT) will be for the next number of days. Each day, 
  you can either buy one share of WOT, sell any number of shares of WOT that you own, or not 
  make any transaction at all. What is the maximum profit you can obtain with an optimum trading 
  strategy?

  > Example: prices=[1,2]
      Buy one share day one, and sell it day two for a profit of 1. Return 1.

  > Example: prices=[2,1]
      No profit can be made so you do not buy or sell stock those days. Return 0.

--Input: 
  - prices: an array of integers that represent predicted daily stock prices

--Output:
  - int: the maximum profit achievable

--Reasoning: 
  Iterate from the end to the start of the 'prices' array, set the max value to 
  the last price and as long as the price is the highest so far, the shares 
  bought previously, which cost less than the current max, will profit, so we buy 
  them. In case we find a new max value (new highest price), update the max. value
  to be this new maximum. Repeat the process.

--Constraints:
  1<=t<=10
  1<=n<=50000
  1<=prices[i]<=100000

--Time complexity: O(n), where n is the size of prices[].

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iostream>
#include <vector>

long stockmax(std::vector<int> prices) {
  if (prices.size() == 1)
    return 0;
  if (prices.size() == 2)
    return ((prices.at(1) < prices.at(0)) ? 0 : (prices.at(1) - prices.at(0)));

  long current_max = prices.at(prices.size() - 1);
  long profit{0};

  for (int i = prices.size() - 2; i >= 0; --i) {
    long curr_price = prices.at(i);

    if (curr_price < current_max)
      profit += (current_max - curr_price);
    else if (curr_price > current_max) {
      current_max = curr_price;
    }
  }

  return profit;
}

int main() {
  std::vector<int> stock_prices{1, 2};
  std::cout << "Max. profit: " << stockmax(stock_prices) << "\n"; // Expected: 1

  stock_prices = {2, 1};
  std::cout << "Max. profit: " << stockmax(stock_prices) << "\n"; // Expected: 0

  stock_prices = {5, 3, 2};
  std::cout << "Max. profit: " << stockmax(stock_prices) << "\n"; // Expected: 0

  stock_prices = {1, 2, 100};
  std::cout << "Max. profit: " << stockmax(stock_prices) << "\n"; // Expected: 197

  stock_prices = {1, 3, 1, 2};
  std::cout << "Max. profit: " << stockmax(stock_prices) << "\n"; // Expected: 3

  stock_prices = {1, 2, 3, 4};
  std::cout << "Max. profit: " << stockmax(stock_prices) << "\n"; // Expected: 6

  stock_prices = {5, 4, 3, 4, 5};
  std::cout << "Max. profit: " << stockmax(stock_prices) << "\n"; // Expected: 4

  return 0;
}