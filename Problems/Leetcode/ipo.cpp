/***
Problem: LC 502. IPO
(https://leetcode.com/problems/ipo/description/)

--Problem statement:
Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital,
LeetCode would like to work on some projects to increase its capital before the IPO. Since it has limited
resources, it can only finish at most 'k' distinct projects before the IPO. Help LeetCode design the best
way to maximize its total capital after finishing at most 'k' distinct projects.

You are given 'n' projects where the ith project has a pure profit 'profits[i]' and a minimum capital of
'capital[i]' is needed to start it.

Initially, you have 'w' capital. When you finish a project, you will obtain its pure profit and the profit
will be added to your total capital.

Pick a list of at most 'k' distinct projects from given projects to maximize your final capital, and return
the final maximized capital.

The answer is guaranteed to fit in a 32-bit signed integer.

> Example 1:
    Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
    Output: 4
    Explanation:
      Since your initial capital is 0, you can only start the project indexed 0.
      After finishing it you will obtain profit 1 and your capital becomes 1.
      With capital 1, you can either start the project indexed 1 or the project indexed 2.
      Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
      Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

> Example 2:
    Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
    Output: 6

--Inputs:
  int: k, the amount of projects that we are allowed to pick.
  int: w, the initial capital that we have.
  int[]: profits, array representing the profit[i] of each 'ith' project.
  int[]: capital, array representing the capital[i] required to start the 'ith' project.

--Output:
  int: final maximized capital.

--Constraints:
  :: 1 <= k <= 10^5
  :: 0 <= w <= 10^9
  :: n == profits.length
  :: n == capital.length
  :: 1 <= n <= 10^5
  :: 0 <= profits[i] <= 10^4
  :: 0 <= capital[i] <= 10^9

--Reasoning: See coments below.

--Time complexity: O(N*log(N));
    In the worst case, all the project will be pushed to both heaps once, so our algorithm has
    a time complexity of O(N*log(N) + k*log(N)), where N is the total number of projects and K
    is the amount of projects we can take. So, the overall time complexity will be O(N*log(N)).

--Space complexity: O(N);
    Since, at most, we may need to store all the projects in the heaps.

*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

typedef std::pair<int, int> prft_idx; // {profit[i], i}
typedef std::pair<int, int> cptl_idx; // {capital[i], i}

struct myCompMax {
  bool operator()(
      const prft_idx &a,
      const prft_idx &b) {
    return a.first < b.first;
  }
};

struct myCompMin {
  bool operator()(
      const prft_idx &a,
      const prft_idx &b) {
    return a.first > b.first;
  }
};

class Solution {
public:
  static int findMaximizedCapital(int k, int w, std::vector<int> &profits, std::vector<int> &capital) {
    // cannot take any projects:
    if (k == 0)
      return 0;
    // invalid inputs:
    const int N = (profits.size() != capital.size() || profits.size() == 0 || capital.size() == 0) ? -1 : profits.size();
    if (N == -1)
      return N;

    // max. heap for profits:
    // std::priority_queue<prft_idx, std::vector<prft_idx>, myCompMax> max_heap_profits;
    std::priority_queue<int> max_heap_profits;
    // min. heap for capital:
    std::priority_queue<cptl_idx, std::vector<cptl_idx>, myCompMin> min_heap_capital;

    // add all project capitals to the min-heap, so that we can select a project with
    // the smallest capital requirement:
    for (int i{0}; i < N; i++) {
      min_heap_capital.push({capital.at(i), i});
    }

    long long my_capital = w;

    while (k > 0) {
      // - go through the top projects of the min-heap and filter the ones that can
      // be done with our available capital.
      // - insert the profits of all these projects into a max-heap, so that we can
      // choose a project with the maximum profit.
      while (!min_heap_capital.empty() && my_capital >= min_heap_capital.top().first) {
        int idx = min_heap_capital.top().second;

        // max_heap_profits.push({profits.at(idx), idx});
        max_heap_profits.push(profits.at(idx));
        // remove project from the min heap so we don't process the same project again:
        min_heap_capital.pop();
      }

      if (!max_heap_profits.empty()) {
        // update our capital to account for the new project's profit:
        my_capital += max_heap_profits.top();
        // remove project from the max heap so we don't process the same project again:
        max_heap_profits.pop();
        // decrement the amount of projects we can take:
        --k;
      } else {
        break;
      }
    }

    return my_capital;
  }
};

int main() {
  std::vector<int> capital{}, profits{};
  int w{0}, k{0}, ans{0}, expec{0};

  std::cout << std::noboolalpha;

  capital = {0, 1, 1};
  profits = {1, 2, 3};
  w = 0;
  k = 2;
  expec = 4;
  ans = Solution::findMaximizedCapital(k, w, profits, capital);
  std::cout << "> Maximum profit for " << k << " projects: " << ans << "\n\t" << (ans == expec ? "[[PASSED]]" : "[[FAILED]]") << "\n\n";

  capital = {0, 1, 1};
  profits = {1, 2, 3};
  w = 0;
  k = 3;
  expec = 6;
  ans = Solution::findMaximizedCapital(k, w, profits, capital);
  std::cout << "> Maximum profit for " << k << " projects: " << ans << "\n\t" << (ans == expec ? "[[PASSED]]" : "[[FAILED]]") << "\n\n";

  capital = {0, 1, 2, 3};
  profits = {1, 2, 3, 5};
  w = 0;
  k = 3;
  expec = 8;
  ans = Solution::findMaximizedCapital(k, w, profits, capital);
  std::cout << "> Maximum profit for " << k << " projects: " << ans << "\n\t" << (ans == expec ? "[[PASSED]]" : "[[FAILED]]") << "\n\n";
  return 0;
}