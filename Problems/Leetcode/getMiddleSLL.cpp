/******************************************************************************
Problem: LC 876. Middle of the Linked List
*******************************************************************************/
/*
--Problem statement:
  Given the 'head' of a singly linked list, return the middle node of the linked
  list. If there are two middle nodes, return the second middle node.

  > Example 1:
      Input: head = [1,2,3,4,5]
      Output: [3,4,5]
      Explanation: The middle node of the list is node 3.

  > Example 2:
      Input: head = [1,2,3,4,5,6]
      Output: [4,5,6]
      Explanation:
        Since the list has two middle nodes with values 3 and 4, we return the
        second one.

--Inputs:
  ListNode*: head of a linked list

--Output:
  ListNode*: head of the modified linked list

--Constraints:
    :: The number of nodes in the list is in the range [1, 100].
    :: 1 <= Node.val <= 100

--Reasoning: Used the 'slow and fast pointers' approach.

--Time complexity: O(N)

--Space complexity: O(1), since there is no input dependent memory allocated.

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

ListNode *middleNode(ListNode *head) {
  ListNode *slowPtr = head, *fastPtr = slowPtr;

  while (fastPtr != nullptr && fastPtr->next != nullptr) {
    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;
  }

  return slowPtr;
}

int main() {
  /* tests were done on LC itself */

  return 0;
}