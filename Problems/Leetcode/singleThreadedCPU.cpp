/***
Problem: LC 1834. Single-Threaded CPU
(https://leetcode.com/problems/single-threaded-cpu/description/)

--Problem statement:
You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array 'tasks',
where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available
to process at 'enqueueTimei' and will take 'processingTimei' to finish processing.

You have a single-threaded CPU that can process at most one task at a time and will act in the following way:
    - If the CPU is idle and there are no available tasks to process, the CPU remains idle.
    - If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing
    time. If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
    - Once a task is started, the CPU will process the entire task without stopping.
    - The CPU can finish a task then start a new one instantly.

Return the order in which the CPU will process the tasks.

  Example 1:
    Input: tasks = [[1,2],[2,4],[3,2],[4,1]]
    Output: [0,2,3,1]
    Explanation: The events go as follows:
    - At time = 1, task 0 is available to process. Available tasks = {0}.
    - Also at time = 1, the idle CPU starts processing task 0. Available tasks = {}.
    - At time = 2, task 1 is available to process. Available tasks = {1}.
    - At time = 3, task 2 is available to process. Available tasks = {1, 2}.
    - Also at time = 3, the CPU finishes task 0 and starts processing task 2 as it is the shortest. Available tasks = {1}.
    - At time = 4, task 3 is available to process. Available tasks = {1, 3}.
    - At time = 5, the CPU finishes task 2 and starts processing task 3 as it is the shortest. Available tasks = {1}.
    - At time = 6, the CPU finishes task 3 and starts processing task 1. Available tasks = {}.
    - At time = 10, the CPU finishes task 1 and becomes idle.

  Example 2:
    Input: tasks = [[7,10],[7,12],[7,5],[7,4],[7,2]]
    Output: [4,3,2,0,1]
    Explanation: The events go as follows:
    - At time = 7, all the tasks become available. Available tasks = {0,1,2,3,4}.
    - Also at time = 7, the idle CPU starts processing task 4. Available tasks = {0,1,2,3}.
    - At time = 9, the CPU finishes task 4 and starts processing task 3. Available tasks = {0,1,2}.
    - At time = 13, the CPU finishes task 3 and starts processing task 2. Available tasks = {0,1}.
    - At time = 18, the CPU finishes task 2 and starts processing task 0. Available tasks = {1}.
    - At time = 28, the CPU finishes task 0 and starts processing task 1. Available tasks = {}.
    - At time = 40, the CPU finishes task 1 and becomes idle.

--Inputs:
  int[][]: 2d array tasks where tasks[i] = [enqueueTimei, processingTimei].

--Output:
  int[]: array containing the processing order.

--Constraints:
  :: tasks.length == n
  :: 1 <= n <= 10^5
  :: 1 <= enqueueTimei, processingTimei <= 10^9

--Reasoning: use a priority queue to sort the tasks based on the time it takes to process them. see comments below.

--Time complexity:
  O(N*log(N)), due to the sorting of the 'tasks' input array. We only go over the same task twice, once for pushing
  it to the priority queue, and the other one when it's time to process it.

--Space complexity:
  O(N), since for the worst case we'd need to allocate space for all the tasks in the 'tasks' array.

*/

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct customCompFunc {
  bool operator()(const std::vector<int> &a, const std::vector<int> &b) {
    return a.at(0) >= b.at(0);
  }
};

class Solution {
public:
  static std::vector<int> getOrder(std::vector<std::vector<int>> &tasks) {
    std::vector<int> res;
    // priority queue for storing the tasks in a sorted way by 'processingTime':
    // pq: [processingTimei, originalPositioni]
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> taskQueue;
    // add position info to each task:
    for (int j{0}; j < tasks.size(); ++j) {
      tasks.at(j).push_back(j);
    }
    // sort tasks based on enqueueTime:
    std::sort(tasks.begin(), tasks.end(), [](std::vector<int> &a, std::vector<int> &b) {
      return a[0] < b[0];
    });

    int i{0};
    long long time{tasks.at(0).at(0)};

    while (!taskQueue.empty() || i < tasks.size()) {
      // push all the tasks with the same 'enqueueTime' and tasks which are enqueued while the CPU
      // is busy, in order to sort them by 'processingTime' in the priority queue:
      while (i < tasks.size() && time >= tasks.at(i).at(0)) {
        taskQueue.push({tasks.at(i).at(1), tasks.at(i).at(2)});
        ++i;
      }

      // if we've processed every task and there are still tasks to be processed (i.e. i < tasks.size()),
      // this means that the next task have an 'enqueueTime' greater than the 'time' it took to process
      // all the previous tasks, so skip to it:
      if (taskQueue.empty()) {
        time = tasks.at(i).at(0);
      } else {
        // update 'time' with the time it'll take to process the current task:
        time += taskQueue.top().at(0);
        // add current task' original order to the result:
        res.push_back(taskQueue.top().at(1));
        // remove task from queue since it's being processed:
        taskQueue.pop();
      }
    }

    return res;
  }

  static bool test(const std::vector<int> &a, const std::vector<int> &b) {
    if (a.size() != b.size())
      return false;

    int n = a.size(), i = 0;

    while (i < n) {
      if (a.at(i) != b.at(i))
        return false;

      ++i;
    }

    return true;
  }
};

int main() {
  std::cout << std::boolalpha;

  std::vector<std::vector<int>> tasks{};
  std::vector<int> expected{}, result{};

  tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  expected = {0, 2, 3, 1};
  result = Solution::getOrder(tasks);
  std::cout << "... testing" << (Solution::test(expected, result) ? "\tPASSED" : "\tFAILED") << "\n";

  tasks = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
  expected = {4, 3, 2, 0, 1};
  result = Solution::getOrder(tasks);
  std::cout << "... testing" << (Solution::test(expected, result) ? "\tPASSED" : "\tFAILED") << "\n";

  return 0;
}