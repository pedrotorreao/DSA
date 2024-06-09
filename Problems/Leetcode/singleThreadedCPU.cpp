/***
Problem: LC 1834. Single-Threaded CPU
(https://leetcode.com/problems/number-of-provinces/description/)

--Problem statement:
  You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks,
  where tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available
  to process at enqueueTimei and will take processingTimei to finish processing.

  You have a single-threaded CPU that can process at most one task at a time and will act in
  the following way:
    - If the CPU is idle and there are no available tasks to process, the CPU remains idle.
    - If the CPU is idle and there are available tasks, the CPU will choose the one with the
    shortest processing time. If multiple tasks have the same shortest processing time, it will
    choose the task with the smallest index.
    - Once a task is started, the CPU will process the entire task without stopping.
    - The CPU can finish a task then start a new one instantly.

  Return the order in which the CPU will process the tasks.

  > Example 1:
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

  > Example 2:
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
  int[][]: 2D integer array tasks.

--Output:
  int[]: the order in which the CPU will process the tasks.

--Constraints:
    :: tasks.length == n
    :: 1 <= n <= 10^5
    :: 1 <= enqueueTimei, processingTimei <= 10^9

--Time complexity:
    O(N*log(N)), where N is the size of the input array, since we need to sort all the tasks by
    enqueue time and also to push N elements to the priority queue (log(N)).

--Space complexity:
    O(N), due to the space allocated for the priority queue.

*/

#include <bits/stdc++.h>

using namespace std;

void display1D(const vector<int> &taskOrder);
void display2D(const vector<vector<int>> &tasks);
bool validateAns(const vector<int> &ans, const vector<int> &expected);

struct customCompFunc {
  bool operator()(const vector<int> &a, const vector<int> &b) {
    return a.at(0) >= b.at(0);
  }
};

class Solution {
public:
  static vector<int> getOrder(vector<vector<int>> &tasks) {
    vector<int> res;

    // priority queue to store the tasks sorted by processing time:
    // - top element: [processingTime, index]
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> taskQueue;

    // index each task with its position in the input array (O(n)):
    for (int j{0}; j < tasks.size(); ++j) {
      tasks.at(j).push_back(j);
    }

    // sort tasks based on enqueueTime (O(n*log(n))):
    sort(tasks.begin(), tasks.end(), [](vector<int> &a, vector<int> &b) {
      return a[0] < b[0];
    });

    int i{0};
    long long time{tasks.at(0).at(0)};

    while (!taskQueue.empty() || i < tasks.size()) {
      // enqueue all the tasks whose enqueueTime has come while the cpu is busy:
      while (i < tasks.size() && time >= tasks.at(i).at(0)) {
        // push the processingTime and position info to the priority queue:
        taskQueue.push({tasks.at(i).at(1), tasks.at(i).at(2)});
        ++i;
      }

      // if there are no tasks available and the cpu is idle, advance time to the
      // next task' enqueueTime:
      if (taskQueue.empty()) {
        time = tasks.at(i).at(0);
      }
      // otherwise, process the task at the top of the queue:
      else {
        // update the time with the processingTime for the current task:
        time += taskQueue.top().at(0);
        res.push_back(taskQueue.top().at(1));

        taskQueue.pop();
      }
    }

    return res;
  }
};

/*

# input:  tasks[n][p] --> task[i] = [enqueueTimei, processingTimei], n: number of tasks, p: pair w/ time info.
# output: order in which the CPU can process each task.

* we can process at most 1 task at a TIME (i):
    -> cpu idle and no tasks        --> cpu idle
    -> cpu idle and available tasks --> choose the one w/ the shortest processing time,
                                    --> if multiple tasks have the same shortest processing time, choose the first in order
    -> cpu processes the entire task without stopping
    -> cpu can finish a task then start a new one instantly (inclusive, at the same i)

* enqueue time is ordered?
*/

int main() {
  cout << boolalpha;

  vector<vector<int>> tasks{};
  vector<int> expected{}, order{};

  tasks = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
  expected = {0, 2, 3, 1};
  order = Solution::getOrder(tasks);
  display1D(order);
  cout << "--> Correct CPU processing order: " << validateAns(order, expected) << "\n - - - - \n";

  tasks = {{7, 10}, {7, 12}, {7, 5}, {7, 4}, {7, 2}};
  expected = {4, 3, 2, 0, 1};
  order = Solution::getOrder(tasks);
  display1D(order);
  cout << "--> Correct CPU processing order: " << validateAns(order, expected) << "\n - - - - \n";

  tasks = {{19, 13}, {16, 9}, {21, 10}, {32, 25}, {37, 4}, {49, 24}, {2, 15}, {38, 41}, {37, 34}, {33, 6}, {45, 4}, {18, 18}, {46, 39}, {12, 24}};
  expected = {6, 1, 2, 9, 4, 10, 0, 11, 5, 13, 3, 8, 12, 7};
  order = Solution::getOrder(tasks);
  display1D(order);
  cout << "--> Correct CPU processing order: " << validateAns(order, expected) << "\n - - - - \n";
}

bool validateAns(const vector<int> &ans, const vector<int> &expected) {
  if (ans.size() != expected.size())
    return false;

  for (int i{0}; i < ans.size(); ++i) {
    if (ans.at(i) != expected.at(i))
      return false;
  }
  return true;
}

void display1D(const vector<int> &taskOrder) {
  cout << "[";
  for (const auto &order : taskOrder) {
    cout << order << "  ";
  }
  cout << "]\n";
}

void display2D(const vector<vector<int>> &tasks) {
  cout << "[";
  for (const auto &task : tasks) {
    cout << " [" << task[0] << "," << task[1] << "] ";
  }
  cout << "]\n";
}