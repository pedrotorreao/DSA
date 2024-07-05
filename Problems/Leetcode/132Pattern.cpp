/***
Problem: LC 456. 132 Pattern
(https://leetcode.com/problems/132-pattern/description/)

--Problem statement:
Given an array of 'n' integers 'nums', a 132 pattern is a subsequence of three integers nums[i], 
nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in 'nums', otherwise, return false.

    > Example 1:
        Input: nums = [1,2,3,4]
        Output: false
        Explanation: There is no 132 pattern in the sequence.

    > Example 2:
        Input: nums = [3,1,4,2]
        Output: true
        Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

    > Example 3:
        Input: nums = [-1,3,2,0]
        Output: true
        Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].

--Inputs:
    int[]: integer array 'nums'

--Output:
    bool: true if there is a 132 pattern in 'nums', false otherwise

--Constraints:
    :: n == nums.length
    :: 1 <= n <= 2 * 10^5
    :: -10^9 <= nums[i] <= 10^9

--Reasoning: Single for-loop approach. Iterate backwards from the end and use a stack for keeping track of
the values seen so far. Whenever the current value, nums[idx], is larger than the element at the top of the
stack, this value is a candidate for the '3' in the pattern and the top of the stack a candidate for the 
'2'. If we then find a value which is less than '2', we've found the '1', and our '132' pattern is complete. 

--Time complexity: O(n), where 'n' is the size of the 'nums' input array. Even though we have a inner loop
for going over the stack, each value is only pushed/popped once to/from the stack.

--Space complexity: O(n), where 'n' is the size of the 'nums' input array. This is achieved when the input 
array is sorted is decreasing order and all the elements end up in the stack.

*/
#include <iostream>
#include <vector>
#include <stack>
#include <climits>

class Solution {
public:
    bool find132pattern(std::vector<int>& nums) {
        // not enough numbers for a 132 pattern:
        if (nums.size() < 3) 
            return false;
        // stack for remembering the largest value:
        std::stack<int> st;
        // nums[k], largest valid value where j < k and nums[k] < nums[j]:
        int numK = INT_MIN;

        // iterate over the input array from the end:
        for (int idx = nums.size()-1; idx >= 0; idx--) {
            // we've found a nums[i], such as nums[i] < nums[k]:
            if (nums.at(idx) < numK)
                return true;

            // while the stack is not empty:
            // - if nums[idx] > st.top(): nums[idx] is a possible candidate for the middle element, nums[j] or 3, 
            // in the 132 pattern and st.top() is now a candidate for the last element, nums[k] or 2:
            while (!st.empty() && nums.at(idx) > st.top()) {
                numK = st.top();   
                st.pop();
            }
            
            st.push(nums.at(idx));
        }

        return false;
    }
};

int main() {
    std::cout << std::boolalpha;

    Solution sol;

    std::vector<int> nums{};
    bool res{false}, expected{false};
        
    nums = {1,2,3,4};
    res = sol.find132pattern(nums);
    expected = false;
    std::cout << ">> Input contains a 132 pattern: " << res << (res == expected ? "\t--PASSED\n" : "\t--FAILED\n");

    nums = {3,1,4,2};
    res = sol.find132pattern(nums);
    expected = true;
    std::cout << ">> Input contains a 132 pattern: " << res << (res == expected ? "\t--PASSED\n" : "\t--FAILED\n");

    nums = {-1,3,2,0};
    res = sol.find132pattern(nums);
    expected = true;
    std::cout << ">> Input contains a 132 pattern: " << res << (res == expected ? "\t--PASSED\n" : "\t--FAILED\n");

    return 0;
}
