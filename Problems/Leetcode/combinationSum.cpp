/*********************************************************************************************/
/* Problem: LC 39. Combination Sum ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given an array of distinct integers 'candidates' and a target integer 'target', return a list
  of all unique combinations of candidates where the chosen numbers sum to 'target'. You may
  return the combinations in any order.

  The same number may be chosen from 'candidates' an unlimited number of times. Two combinations
  are unique if the frequency of at least one of the chosen numbers is different.

  The test cases are generated such that the number of unique combinations that sum up to 'target'
  is less than 150 combinations for the given input.

  > Example 1:
  Input: candidates = [2,3,6,7], target = 7
  Output: [[2,2,3],[7]]
  Explanation:
    2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
    7 is a candidate, and 7 = 7.
    These are the only two combinations.

  > Example 2:
  Input: candidates = [2,3,5], target = 8
  Output: [[2,2,2,2],[2,3,3],[3,5]]

  > Example 3:
  Input: candidates = [2], target = 1
  Output: []
 
--Inputs:
  -int[]: array of distinct integers 'candidates'
  -int: integer 'target'

--Output:
  -int[][]: unique combinations of candidates where the chosen numbers sum to 'target'

--Constraints:
  :: 1 <= candidates.length <= 30
  :: 2 <= candidates[i] <= 40
  :: All elements of candidates are distinct.
  :: 1 <= target <= 40

--Reasoning: See comments below.

--Time complexity: O(2^N)

--Space complexity: O(N)

*/

#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void display2D(std::vector<std::vector<T>> &vec) {
  for (const auto &r : vec) {
    std::cout << "[";
    for (int i{0}; i < r.size(); ++i) {
      std::cout << r.at(i);
      if (i + 1 != r.size())
        std::cout << ", ";
    }
    std::cout << "] ";
  }
  std::cout << "\n\n";
}

void backtrackDFS(std::vector<int> &candidates, std::vector<std::vector<int>> &res, std::vector<int> &cur,
                  int target, int sum, int start) {
  // base case 1:
  //  including the current candidates[i] in the sum exceeds the target, so this decision
  //  branch in no longer valid, backtrack.
  if (sum > target)
    return;
  // base case 2:
  //  we've found a combination whose sum matches 'target', add it to the result.
  if (sum == target) {
    res.push_back(cur);
    return;
  }

  // rescursive case:
  //  explore the paths as long as they are valid.
  for (int i = start; i < candidates.size(); ++i) {
    // include 'candidates[i]' in the running sum:
    int cur_sum = candidates.at(i) + sum;
    // add it to the result:
    cur.push_back(candidates.at(i));
    // recurse for the next element in the decision tree, exploring all possible
    // paths from this point:
    backtrackDFS(candidates, res, cur, target, cur_sum, i);
    // since all paths have been explored for 'candidates[i]', remove it from the current
    // sum and explore the next element, 'candidates[i+1]'.
    cur.pop_back();
  }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  if (candidates.at(0) > target)
    return std::vector<std::vector<int>>();

  std::vector<std::vector<int>> res;
  std::vector<int> cur;

  backtrackDFS(candidates, res, cur, target, 0, 0);

  return res;
}

int main() {
  std::vector<int> candidates{};
  std::vector<std::vector<int>> res{};
  int target{};

  candidates = {2, 3, 6, 7};
  target = 7;
  res = combinationSum(candidates, target);
  display2D<int>(res);

  candidates = {2, 3, 5};
  target = 8;
  res = combinationSum(candidates, target);
  display2D<int>(res);

  return 0;
}