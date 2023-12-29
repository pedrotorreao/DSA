/* * * * * * * * * * * * * * * * * *
 Problem: LC 25. Reverse Nodes in k-Group

--Problem statement:
  Given the 'head' of a linked list, reverse the nodes of the list 'k' at a time,
  and return the modified list. 'k' is a positive integer and is less than or
  equal to the length of the linked list. If the number of nodes is not a
  multiple of 'k' then left-out nodes, in the end, should remain as it is.

  You may not alter the values in the list's nodes, only nodes themselves
  may be changed.

  > Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [2,1,4,3,5]

  > Example 2:
    Input: head = [1,2,3,4,5], k = 3
    Output: [3,2,1,4,5]

--Constraints:
    :: The number of nodes in the list is n.
    :: 1 <= k <= n <= 5000
    :: 0 <= Node.val <= 1000

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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  static ListNode *reverseKGroup(ListNode *head, int k) {
    if (k <= 1 || head == nullptr || head->next == nullptr)
      return head;

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (true) {
      // for each sub-list, check first if there are enough nodes
      // left in the list before reversing another sub-list:
      int nodesLeft = k;
      ListNode *c = curr;
      while (c) {
        c = c->next;
        --nodesLeft;
        // if there are at least k more nodes left in the list,
        // there is no need to keep iterating, reverse the next
        // k nodes' sub-list:
        if (nodesLeft <= 0)
          break;
      }
      // if there are less than k nodes left, we are done reversing and break:
      if (nodesLeft > 0)
        break;
      // store a pointer to the node before the 'left' node
      // so we can reconnect the nodes after the reversal:
      ListNode *lastNodePrevSubList = prev;
      // store a pointer to the node which will become the
      // last node after the sublist is reversed:
      ListNode *lastNodeCurrSubList = curr;

      // reverse nodes between 'left' and 'right':
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

  head = Solution::reverseKGroup(head, 2);

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