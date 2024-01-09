/* * * * * * * * * * * * * * * * * *
Problem: LC 83. Remove Duplicates from Sorted List

url: https://leetcode.com/problems/remove-duplicates-from-sorted-list/description/

--Problem statement:
Given the head of a sorted linked list, delete all duplicates such that
each element appears only once. Return the linked list sorted as well.

  > Example 1:
      Input: head = [1,1,2]
      Output: [1,2]

  > Example 2:
      Input: head = [1,1,2,3,3]
      Output: [1,2,3]

--Constraints:
    :: The number of nodes in the list is in the range [0, 300].
    :: -100 <= Node.val <= 100
    :: The list is guaranteed to be sorted in ascending order.

--Inputs:
  - ListNode *: head of a sorted linked list.

--Outputs:
  - ListNode *: head of the modified linked list.

--Reasoning: Use the fast and slow pointers approach.
      slow pointer: first
      fast pointer: frwrd
    The pointer first points to the current unique value, while frwrd goes
    one step ahead checking for duplicates. Whenever it encounters one, it iterates
    until the last duplicate is found. Then, we make the next pointer of first
    point to the next unique value. The process is repeated until we get to the end of the list.

--Time complexity:
    :: O(n), even though we have a nested while loop, we only iterate over the entire list once.

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

void displaySLL(ListNode *head);

class Solution {
public:
  static ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr || head->next == nullptr)
      return head;

    ListNode *first = head;
    ListNode *frwrd = head;

    while (frwrd) {

      if (first->val == frwrd->val) {
        while (frwrd && first->val == frwrd->val)
          frwrd = frwrd->next;

        first->next = frwrd;
      }
      first = first->next;

      if (frwrd)
        frwrd = frwrd->next;
    }

    return head;
  }
};

int main() {
  ListNode *head = new ListNode(1);
  ListNode *curr = new ListNode(1);
  head->next = curr;

  curr->next = new ListNode(2);
  curr = curr->next;
  curr->next = new ListNode(3);
  curr = curr->next;
  curr->next = new ListNode(3);
  curr = curr->next;
  curr->next = new ListNode(3);
  curr = curr->next;
  curr->next = new ListNode(4);
  curr = curr->next;
  curr->next = new ListNode(4);
  curr = curr->next;
  curr->next = new ListNode(5);
  curr = curr->next;

  displaySLL(head);

  head = Solution::deleteDuplicates(head);

  displaySLL(head);
}

void displaySLL(ListNode *head) {
  ListNode *curr = head;

  while (curr) {
    std::cout << curr->val;

    if (curr->next)
      std::cout << " -> ";

    curr = curr->next;
  }
  std::cout << "\n";
}