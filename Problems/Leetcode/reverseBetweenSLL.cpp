/* * * * * * * * * * * * * * * * * *
 Problem: LC 92. Reverse Linked List II

--Problem statement:
  Given the head of a singly linked list and two integers 'left' and 'right' where 'left <= right',
  reverse the nodes of the list from position 'left' to position 'right', and return the reversed list.

  > Example 1:
    Input: head = [1,2,3,4,5], left = 2, right = 4
    Output: [1,4,3,2,5]

  > Example 2:
    Input: head = [5], left = 1, right = 1
    Output: [5]

--Constraints:
    :: The number of nodes in the list is n.
    :: 1 <= n <= 500
    :: -500 <= Node.val <= 500
    :: 1 <= left <= right <= n

--Inputs:
  - ListNode*: head of the singly linked list

--Outputs:
  - ListNode*: head of the modified singly linked list

--Reasoning:
  See comments below.

--Time complexity:
    :: O(N), where N is the size of the list, fot the worst case in which 'left' and
    'right' point to the first and last nodes of the list respectively.

--Space complexity: O(1), no extra space is allocated, besides a few pointers.

* * * * * * * * * * * * * * * * * */
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  static ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (left == right || head == nullptr || head->next == nullptr)
      return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    // skip the first "left-1" nodes, 'curr' will then point
    // to the 'left' node:
    for (int i{0}; (i < left - 1) && (curr != nullptr); ++i) {
      prev = curr;
      curr = curr->next;
    }
    // store a pointer to the node before the 'left' node
    // so we can reconnect the nodes after the reversal:
    ListNode *nodePreviousToLeft = prev;
    // store a pointer to the node which will become the
    // last node after the sublist is reversed:
    ListNode *lastNodeAfterReversal = curr;

    // reverse nodes between 'left' and 'right':
    for (int i{0}; (i < right - left + 1) && (curr != nullptr); ++i) {
      ListNode *next = curr->next;

      curr->next = prev;
      prev = curr;

      curr = next;
    }

    // reattach the reversed sublist to the remaining nodes.
    // if left = 1, then the reversal begins at the head node
    // and 'nodePreviousToLeft' will be equal to nullptr:
    if (nodePreviousToLeft != nullptr)
      // 'prev' is now the first node in the sublist:
      nodePreviousToLeft->next = prev;
    else
      head = prev;

    lastNodeAfterReversal->next = curr;

    return head;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  ListNode *curr = head;

  curr->next = new ListNode(2);
  curr = curr->next;
  curr->next = new ListNode(3);
  curr = curr->next;
  curr->next = new ListNode(4);
  curr = curr->next;
  curr->next = new ListNode(5);

  head = Solution::reverseBetween(head, 2, 4);

  curr = head;
  while (curr) {
    std::cout << curr->val;

    if (curr->next)
      std::cout << " -> ";
    else
      std::cout << "\n";

    curr = curr->next;
  }

  return 0;
}