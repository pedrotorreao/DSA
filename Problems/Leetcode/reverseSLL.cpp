/*********************************************************************************************/
/* Problem: Reverse a Singly Linked List (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the 'head' of a singly linked list, reverse the list, and return the reversed list.
  > Example:
      Input: head = [1,2]
      Output: [2,1]

--Inputs:
  -ListNode: the 'head' of a singly linked list

--Output:
  - ListNode: the 'head' of the reversed list

--Constraints:
  The number of nodes in the list is the range [0, 5000].
  -5000 <= Node.val <= 5000

--Reasoning: See comments below.

--Time complexity:

--Space complexity:
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
  ListNode(int x) : val{x}, next{nullptr} {}
};

// helper methods - forward declarations:
void fillList(ListNode *head, int size);
void displayList(ListNode *head);

int main() {
  // generate two equal lists:
  ListNode *head_1 = new ListNode(5);
  ListNode *head_2 = new ListNode(5);
  fillList(head_1, 5);
  fillList(head_2, 5);

  return 0;
}

// helper methods - definitions:
void fillList(ListNode *head, int size) {
  ListNode *curr = head;
  int seed = head->val;

  while (--size) {
    curr->next = new ListNode(seed * 3);

    curr = curr->next;
    ++seed;
  }
}

void displayList(ListNode *head) {
  ListNode *curr = head;

  while (curr != nullptr) {
    std::cout << curr->val;
    if (curr->next != nullptr)
      std::cout << " -> ";

    curr = curr->next;
  }
  std::cout << "\n";
}