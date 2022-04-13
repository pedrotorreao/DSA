/*********************************************************************************************/
/* Problem: Odd Even Linked List (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the 'head' of a singly linked list, group all the nodes with odd indices together followed
  by the nodes with even indices, and return the reordered list. The first node is considered odd,
  and the second node is even, and so on. Note that the relative order inside both the even and
  odd groups should remain as it was in the input.

  You must solve the problem in O(1) extra space complexity and O(n) time complexity.

  > Example:
    Input: head = [1,2,3,4,5]
    Output: [1,3,5,2,4]

  > Example:
    Input: head = [2,1,3,5,6,4,7]
    Output: [2,3,6,7,1,5,4]

--Inputs:
  -ListNode: the 'head' of a singly linked list

--Output:
  - ListNode: the 'head' of the rearranged list

--Constraints:
  n == number of nodes in the linked list
  0 <= n <= 104
  -106 <= Node.val <= 106

--Reasoning: See comments below.

--Time complexity: O(N), where N is the lenght of the SLL.

--Space complexity: O(1), no additional input dependent space is needed.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *oddEvenList(ListNode *head) {
  // .. add solution

  return head;
}

int main() {
  // .. add test cases

  return 0;
}