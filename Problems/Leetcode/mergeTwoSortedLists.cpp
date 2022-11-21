/*********************************************************************************************/
/* Problem: LC 21. Merge Two Sorted Lists  ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given the heads of two sorted linked lists list1 and list2. Merge the two lists in a
  one sorted list. The list should be made by splicing together the nodes of the first two lists.
  Return the head of the merged linked list.

  > Example 1:
  Input: list1 = [1,2,4], list2 = [1,3,4]
  Output: [1,1,2,3,4,4]

  > Example 2:
  Input: list1 = [], list2 = []
  Output: []

  > Example 3:
  Input: list1 = [], list2 = [0]
  Output: [0]
 
--Inputs:
  - TreeNode*: the heads of two sorted linked lists

--Output:
  - TreeNode*: head of the merged linked list

--Constraints:
  :: The number of nodes in both lists is in the range [0, 50].
  :: -100 <= Node.val <= 100
  :: Both list1 and list2 are sorted in non-decreasing order.


--Reasoning: See comments below.

--Time complexity: O(N), since we traverse all the nodes of the lists once.

--Space complexity: O(1), if we don't consider the output list.

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

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  // list1 is empty, return list2:
  if (!list1)
    return list2;
  // list2 is empty, return list1:
  if (!list2)
    return list1;

  ListNode *curr_1 = list1;
  ListNode *curr_2 = list2;
  ListNode *merged_list;

  // choose the smallest head node value between the two lists:
  if (curr_1->val < curr_2->val) {
    merged_list = new ListNode(curr_1->val);
    curr_1 = curr_1->next;
  } else {
    merged_list = new ListNode(curr_2->val);
    curr_2 = curr_2->next;
  }

  ListNode *curr_m = merged_list;

  while (curr_1 || curr_2) {
    // no nodes left in 'list1', append 'list2' to the result:
    if (!curr_1) {
      curr_m->next = curr_2;
      break;
    }
    // no nodes left in 'list2', append 'list1' to the result:
    if (!curr_2) {
      curr_m->next = curr_1;
      break;
    }
    // select the smaller node value between the current nodes in 'list1' and 'list2':
    if (curr_1->val < curr_2->val) {
      curr_m->next = new ListNode(curr_1->val);
      curr_1 = curr_1->next;
    } else {
      curr_m->next = new ListNode(curr_2->val);
      curr_2 = curr_2->next;
    }

    curr_m = curr_m->next;
  }

  return merged_list;
}

int main() {
  // tests handled by LC platform

  return 0;
}