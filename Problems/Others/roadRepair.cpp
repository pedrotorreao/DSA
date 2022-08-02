/*********************************************************************************************/
/* Problem: Road Repair ********/
/*********************************************************************************************/
/*
--Problem statement:
  Suppose that your job is to repair a road. The road is represented by a string 'roadStr'
  consisting of 'N' characters in which each character represents a stretch of road. Each character
  can be either '.' or 'x', where '.' represents a good stretch of road and 'x' a bad one. For
  example:
    roadStr = "...xxx..x":
        the road starts with a 3 good patches, followed by 3 bad ones, followed by 2 good ones
        and ending with 1 bad one.
  You can select any number of consecutive bad streches and repair all of them. The cost of
  repairing M consecutive bad spots is M+1. So, for the previous example, repairing the first 2
  bad streches would cost 3. If you have a budget 'totalBudget', how many repairs can you perform
  with the given budget?
    > Example - roadStr = "..xxxxx" and totalBudget = 4:
        There a few different approaches, one is to repair the 3 bad spots in the end. The result is 3 repairs.

--Input:
  string: 'roadStr' of size N
  int: 'totalBudget'

--Output:
  int: the number of maximum possible repairs that can be made without exceding the budget.

--Assumptions:
  - 1 <= N <= 100000
  - 0 <= 'totalBudget' <= 200000
  - roadStr[i] is either 'x' or '.'

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <string>
#include <vector>

// -------------------------------------------------------------------------------------
// Approach #1 - Divide and Conquer:
// --Time complexity: O(2^N), where N is the length of the input string.
// --Space complexity: O(N), due to the stack memory used by having at most N recursive
// calls simultaneously.

int calls_1{0}; // recursive calls counter

int maxNumberOfRepairs_helper(std::string &roadStr, int totalBudget, int idx) {
  ++calls_1;

  // base case:
  //    a. execution got to the end of the string
  //    b. there is no budget left
  if (idx >= roadStr.size() || totalBudget <= 1)
    return 0;

  int res_curr{0};

  // if current segment of the road is a pothole, check if the next consecutive segment
  // is a pothole:
  //    a. if it is, increment the result to account for current pothole, decrement the
  //  budget by 1 since we are still patching, and process next consecutive segment.
  //    b. if it is not, increment the result to account for current pothole, decrement
  //  the budget by 2 since we finished patching the consecutive segments and process the
  // next segment.
  if (roadStr.at(idx) == 'x') {
    if (idx + 1 < roadStr.size() && roadStr.at(idx + 1) == 'x')
      res_curr = 1 + maxNumberOfRepairs_helper(roadStr, totalBudget - 1, idx + 1);
    else
      res_curr = 1 + maxNumberOfRepairs_helper(roadStr, totalBudget - 2, idx + 1);
  }

  // if current segment of the road is not a pothole, process the next segment of the road:
  int res_skip = maxNumberOfRepairs_helper(roadStr, totalBudget, idx + 1);

  // the result will be the maximum value between patching and skipping:
  return std::max(res_curr, res_skip);
}

int maxNumberOfRepairs(std::string &roadStr, int totalBudget) {
  calls_1 = 0;

  return maxNumberOfRepairs_helper(roadStr, totalBudget, 0);
}

// -------------------------------------------------------------------------------------
// Approach #2 - Memoization:
// --Time complexity: O(N^2), where N is the length of the input string.
// --Space complexity: O(N^2), due to the 2d vector used for storing the results.

int calls_2{0}; // recursive calls counter
int maxNumberOfRepairs_memo(std::string &roadStr, int totalBudget, int idx, std::vector<std::vector<int>> &dp) {
  ++calls_2;

  // base case:
  //    a. execution got to the end of the string
  //    b. there is no budget left
  if (idx >= roadStr.size() || totalBudget <= 1)
    return 0;

  // if the result for the current idx and budget has not been calculated before, calculate it:
  if (dp.at(idx).at(totalBudget) == -1) {
    int res_curr{0};

    // if current segment of the road is a pothole, check if the next consecutive segment
    // is a pothole:
    //    a. if it is, increment the result to account for current pothole, decrement the
    //  budget by 1 since we are still patching, and process next consecutive segment.
    //    b. if it is not, increment the result to account for current pothole, decrement
    //  the budget by 2 since we finished patching the consecutive segments and process the
    // next segment.
    if (roadStr.at(idx) == 'x') {
      if (idx + 1 < roadStr.size() && roadStr.at(idx + 1) == 'x')
        res_curr = 1 + maxNumberOfRepairs_memo(roadStr, totalBudget - 1, idx + 1, dp);
      else
        res_curr = 1 + maxNumberOfRepairs_memo(roadStr, totalBudget - 2, idx + 1, dp);
    }

    // if current segment of the road is not a pothole, process the next segment of the road:
    int res_skip = maxNumberOfRepairs_memo(roadStr, totalBudget, idx + 1, dp);

    // cache calculated result so we don't need to repeat calculations:
    dp.at(idx).at(totalBudget) = std::max(res_curr, res_skip);
  }

  return dp.at(idx).at(totalBudget);
}

int maxNumberOfRepairs_2(std::string &roadStr, int totalBudget) {
  calls_2 = 0;

  // 2D vector for caching results for each character and budget:
  std::vector<std::vector<int>> dp(roadStr.size(), std::vector<int>(totalBudget + 1, -1));

  return maxNumberOfRepairs_memo(roadStr, totalBudget, 0, dp);
}
// -------------------------------------------------------------------------------------

int main() {
  // test cases:
  std::cout << "---- Test cases: Approach #1 - DC -----\n";

  std::string road{"...xxx..x....xxx"};
  int budget{7};
  int res = maxNumberOfRepairs(road, budget);
  int expect = 5;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_1 << "\n\n";

  road = "..xxxxx";
  budget = 4;
  res = maxNumberOfRepairs(road, budget);
  expect = 3;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_1 << "\n\n";

  road = "x.x.xxx...x";
  budget = 14;
  res = maxNumberOfRepairs(road, budget);
  expect = 6;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_1 << "\n\n";

  road = "..";
  budget = 5;
  res = maxNumberOfRepairs(road, budget);
  expect = 0;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_1 << "\n\n";

  std::cout << "\n---- Test cases: Approach #2 - Memoization -----\n";

  road = "...xxx..x....xxx";
  budget = 7;
  res = maxNumberOfRepairs_2(road, budget);
  expect = 5;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_2 << "\n\n";

  road = "..xxxxx";
  budget = 4;
  res = maxNumberOfRepairs_2(road, budget);
  expect = 3;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_2 << "\n\n";

  road = "x.x.xxx...x";
  budget = 14;
  res = maxNumberOfRepairs_2(road, budget);
  expect = 6;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_2 << "\n\n";

  road = "..";
  budget = 5;
  res = maxNumberOfRepairs_2(road, budget);
  expect = 0;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");
  std::cout << "Total number of recursive calls: " << calls_2 << "\n\n";

  return 0;
}
