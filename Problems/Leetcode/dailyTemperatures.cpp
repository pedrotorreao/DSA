/* * * * * * * * * * * * * * * * * *
Problem: LC 739. Daily Temperatures

--Problem statement:
Given an array of integers temperatures represents the daily temperatures, return
an array answer such that answer[i] is the number of days you have to wait after
the ith day to get a warmer temperature. If there is no future day for which this
is possible, keep answer[i] == 0 instead.

  Example 1:
      Input: temperatures = [73,74,75,71,69,72,76,73]
      Output: [1,1,4,2,1,1,0,0]

  Example 2:
      Input: temperatures = [30,40,50,60]
      Output: [1,1,1,0]

  Example 3:
      Input: temperatures = [30,60,90]
      Output: [1,1,0]


--Constraints:
    :: 1 <= temperatures.length <= 10^5
    :: 30 <= temperatures[i] <= 100

--Inputs:
  - int[]: array of integers temperatures.

--Outputs:
  - int[]: number of days you have to wait for each temperature value to get a warmer temperature.

--Reasoning: Monotonic Stack approach. See comments below.

--Time complexity:
    :: O(n), where n is the size of the temperatures array since each element is processed once.

--Space complexity:
    :: O(n), due to the additional space needed for the stack.

* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stack>
#include <vector>

void display1D(const std::vector<int> &vec);

class Solution {
public:
  static std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
    // stack for storing the temperature' indices:
    std::stack<int> s;
    // output array:
    std::vector<int> res(temperatures.size(), 0);

    for (int i = 0; i < temperatures.size(); i++) {
      // while the stack is not empty and the current temperature is higher than
      // the temperature indicated by the index stored at the top of the stack,
      // calculate the number of days until a warmer temperature by subtracting
      // the index at the top of the stack from the current index:
      while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
        res[s.top()] = i - s.top();
        // pop the index from the stack, since we now have a larger temperature
        // value:
        s.pop();
      }
      // push the current index to the stack:
      s.push(i);
    }
    return res;
  }
};

int main() {
  std::vector<int> temperatures{}, res{};

  temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
  res = Solution::dailyTemperatures(temperatures);

  std::cout << "-- Daily temperatures: ";
  display1D(temperatures);
  std::cout << "-- For each temperature value, the number of days from a warmer day are: ";
  display1D(res);
}

void display1D(const std::vector<int> &vec) {
  std::cout << "[ ";
  for (const auto &num : vec) {
    std::cout << num << " ";
  }
  std::cout << "]\n";
}