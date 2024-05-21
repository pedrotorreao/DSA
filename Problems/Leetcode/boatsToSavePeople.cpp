/***
Problem: LC 881. Boats to Save People
(https://leetcode.com/problems/boats-to-save-people/description/)

--Problem statement:
  You are given an array people where people[i] is the weight of the ith person, and an infinite
  number of boats where each boat can carry a maximum weight of limit. Each boat carries at most
  two people at the same time, provided the sum of the weight of those people is at most limit.

  Return the minimum number of boats to carry every given person.

  > Example 1:
      Input: people = [1,2], limit = 3
      Output: 1
      Explanation: 1 boat (1, 2)

  > Example 2:
      Input: people = [3,2,2,1], limit = 3
      Output: 3
      Explanation: 3 boats (1, 2), (2) and (3)

  > Example 3:
      Input: people = [3,5,3,4], limit = 5
      Output: 4
      Explanation: 4 boats (3), (3), (4), (5)

--Inputs:
  int[]: people's weights

--Output:
  int: minimum number of boats

--Constraints:
    :: 1 <= people.length <= 5 * 10^4
    :: 1 <= people[i] <= limit <= 3 * 10^4

--Time complexity:
    O(N*log(N)), where is the size of the input array, since we sort the array.

--Space complexity:
    ~O(log(N)), due to the stack space allocated for the sorting.

*/
#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int numRescueBoats(std::vector<int> &people, int limit) {
    int boatCount = 0, idxLighest = 0, idxHeaviest = people.size() - 1;

    // sort input to make it possible to pair lightest and heaviest:
    std::sort(people.begin(), people.end());

    while (idxLighest <= idxHeaviest) {
      // calculate the total weight of the pair:
      int totalWeight = people[idxLighest] + people[idxHeaviest];
      // if total weight is inside the limit, add both people to the boat,
      // i.e. move both pointers:
      if (totalWeight <= limit) {
        ++idxLighest, --idxHeaviest;
      }
      // otherwise, add only the heaviest:
      else {
        --idxHeaviest;
      }
      // add one more boat to the count:
      ++boatCount;
    }

    return boatCount;
  }
};

int main() {
  Solution sol;

  std::vector<int> people;
  int limit{0}, minNumOfBoats{0};

  people = {1, 2};
  limit = 3;
  minNumOfBoats = sol.numRescueBoats(people, limit);
  std::cout << ">> Min. number of boats: " << minNumOfBoats << "\n";

  people = {3, 2, 2, 1};
  limit = 3;
  minNumOfBoats = sol.numRescueBoats(people, limit);
  std::cout << ">> Min. number of boats: " << minNumOfBoats << "\n";

  return 0;
}