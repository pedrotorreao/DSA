/* * * * * * * * * * * * * * * * * *
 Problem: Reverse alternating K-element Sub-list

--Problem statement:
  Given the head of a LinkedList and a number ‘k’, reverse every
  alternating ‘k’ sized sub-list starting from the head.
  If, in the end, you are left with a sub-list with less than ‘k’ elements,
  reverse it too.
  You may not alter the values in the list's nodes, only nodes themselves
  may be changed.

  > Example 1:
    Input: head = [1,2,3,4,5,6,7,8], k = 2
    Output: [2,1,3,4,6,5,7,8]

--Inputs:
  - ListNode*: head of the singly linked list

--Outputs:
  - ListNode*: head of the modified singly linked list

--Reasoning:
  See comments below.

--Time complexity:
    :: O(n), where n is the total number of nodes in the linked list.

--Space complexity:
    :: O(1), since no additional input-dependent space is allocated.

* * * * * * * * * * * * * * * * * */

#include <iostream>

class ListNode {
public:
  int val = 0;
  ListNode *next;

  ListNode(int value) {
    this->val = value;
    next = nullptr;
  }
};

class Solution {
public:
  static ListNode *reverseAltKGroupSLL(ListNode *head, int k) {
    if (k <= 1 || head == nullptr || head->next == nullptr)
      return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (true) {
      // store a pointer to the node before the 'left' node
      // so we can reconnect the nodes after the reversal:
      ListNode *lastNodePrevSubList = prev;
      // store a pointer to the node which will become the
      // last node after the sublist is reversed:
      ListNode *lastNodeCurrSubList = curr;
      // standard iterative list reversal:
      for (int i{0}; (i < k) && (curr != nullptr); ++i) {
        ListNode *next = curr->next;

        curr->next = prev;
        prev = curr;

        curr = next;
      }

      // reattach the reversed sublist to the remaining nodes.
      // if left = 1, then the reversal begins at the head node
      // and 'lastNodePrevSubList' will be equal to nullptr:
      if (lastNodePrevSubList != nullptr)
        // 'prev' is now the first node in the sublist:
        lastNodePrevSubList->next = prev;
      else
        head = prev;

      lastNodeCurrSubList->next = curr;

      if (curr == nullptr)
        break;

      prev = lastNodeCurrSubList;

      // skip 'k' nodes:
      int nodesToSkip = k;
      while (nodesToSkip && curr && curr->next) {
        prev = curr;
        curr = curr->next;

        --nodesToSkip;
      }
    }
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
  curr = curr->next;
  curr->next = new ListNode(6);
  curr = curr->next;
  curr->next = new ListNode(7);
  curr = curr->next;
  curr->next = new ListNode(8);

  head = Solution::reverseAltKGroupSLL(head, 2);

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