/******************************************************************************
Problem: LC 19. Remove Nth Node From End of List
*******************************************************************************/
/*
--Problem statement:
  Given the 'head' of a linked list, remove the nth node from the end of the list
  and return its 'head'.

  > Example 1:
  Input: head = [1,2,3,4,5], n = 2
  Output: [1,2,3,5]

  > Example 2:
  Input: head = [1], n = 1
  Output: []

  > Example 3:
  Input: head = [1,2], n = 1
  Output: [1]

--Inputs:
  ListNode*: 'head' of a linked list

--Output:
  ListNode*: 'head' of the linked list with its Nth node from the end removed.

--Constraints:
    :: The number of nodes in the list is 'sz'
    :: 1 <= sz <= 30
    :: 0 <= Node.val <= 100
    :: 1 <= n <= sz

--Reasoning: See comments below.

--Time complexity: O(N), where N is the size of the list.

--Space complexity: O(1), no additional input dependent memory needs to be allocated.

*/

#include <iostream>

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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeNthFromEnd(ListNode *head, int n) {
  if (!head)
    return head;

  // initialize two pointers:
  ListNode *slow = head;
  ListNode *fast = head;

  // move "fast" pointer "n" nodes forward:
  while (n--)
    fast = fast->next;

  // if "fast" is nullptr, it means that n = sz,
  // so the node to be removed is the "head" node:
  if (!fast)
    return head->next;

  // iterate moving both pointers forward until "fast" reaches the end
  // of the end at which, since "slow" ans "fast" are "n" nodes apart,
  // "slow->next" is the nth node and can be removed by reassigning
  // the "slow->next" reference to skip the nth node:
  while (fast->next) {
    slow = slow->next;
    fast = fast->next;
  }
  slow->next = slow->next->next;

  return head;
}

int main() {
  // test cases run on LC.

  return 0;
}
