/* * * * * * * * * * * * * * * * * *
Problem: LC 496. Next Greater Element I

--Problem statement:
The next greater element of some element x in an array is the first greater element that is to
the right of x in the same array. You are given two distinct 0-indexed integer arrays 'nums1'
and 'nums2', where nums1 is a subset of 'nums2'.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine
the next greater element of nums2[j] in nums2. If there is no next greater element, then the
answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as
described above.

  > Example 1:
      Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
      Output: [-1,3,-1]
      Explanation: The next greater element for each value of nums1 is as follows:
      - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
      - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
      - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

  > Example 2:
    Input: nums1 = [2,4], nums2 = [1,2,3,4]
    Output: [3,-1]
    Explanation: The next greater element for each value of nums1 is as follows:
    - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
    - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

--Constraints:
    :: 1 <= nums1.length <= nums2.length <= 1000
    :: 0 <= nums1[i], nums2[i] <= 104
    :: All integers in nums1 and nums2 are unique.
    :: All the integers of nums1 also appear in nums2.

--Inputs:
  - int[]: integer arrays nums1 and nums2.

--Outputs:
  - int[]: array ans of length nums1.length such that ans[i] is the next greater element as described above.

--Reasoning: We can use a Monotonic Stack to find the next greater element for each element in nums2, and
a Hashmap for mapping each element to its next greater element.

--Time complexity:
    :: O(n), where n is the length of the input array nums2, since each element is pushed and popped from
    the stack exactly once.

--Space complexity:
    :: O(n), due to the additional space needed for the hashmap and the stack.

* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

void display1D(const std::vector<int> &vec);

class Solution {
public:
  static std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> ans;
    std::unordered_map<int, int> hm;
    std::stack<int> st;

    // Iterate over the input array nums2:
    for (int i{0}; i < nums2.size(); i++) {
      // Pop the elements from the stack which are smaller than current number:
      while (!st.empty() && st.top() < nums2.at(i)) {
        // Before removing the smaller number, map it to nums2.at(i) so we remember the next
        // greater element:
        hm[st.top()] = nums2.at(i);
        st.pop();
      }
      // Add current nums2.at(i) to the stack:
      st.push(nums2.at(i));
    }

    // Numbers remaining on the stack don't have a next greater element, so map them to -1 on the hashmap:
    while (!st.empty()) {
      hm[st.top()] = -1;
      st.pop();
    }

    // Populate the output array by adding the next greater element for each value in nums1:
    for (int i{0}; i < nums1.size(); i++) {
      ans.push_back(hm[nums1.at(i)]);
    }
    return ans;
  }
};

int main() {
  std::vector<int> nums1{}, nums2{}, res{};

  nums1 = {4, 1, 2};
  nums2 = {1, 3, 4, 2};
  res = Solution::nextGreaterElement(nums1, nums2);

  std::cout << "Next greater elements for ";
  display1D(nums1);
  std::cout << "in ";
  display1D(nums2);
  std::cout << "--> ";
  display1D(res);
}

void display1D(const std::vector<int> &vec) {
  std::cout << "[ ";
  for (const auto &num : vec) {
    std::cout << num << " ";
  }
  std::cout << "]\n";
}