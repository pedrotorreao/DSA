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
    Iterative approach: O(N), where N is the lenght of the SLL.
    Recursive approach: O(N), where N is the lenght of the SLL.

--Space complexity:
    Iterative approach: O(1), no additional input dependent space is needed.
    Recursive approach: O(N), due to stack space allocation, where N is the lenght of the SLL.
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

// reverse sll - iterative solution:
ListNode *reverseList_Iter(ListNode *head) {
  if (head == nullptr)
    return nullptr;

  ListNode *first = head;
  ListNode *second = first->next;

  while (second != nullptr) {
    ListNode *temp = second->next; // reference to the rest of the list
    // rearrange pointers:
    second->next = first;
    first = second;
    second = temp;
  }
  // set the old 'head->next' ref. to nullptr to mark the end of the list:
  head->next = nullptr;
  // point 'head' to the new head node:
  head = first;

  return head;
}

// reverse sll - recursive solution:
ListNode *reverseList_Rec(ListNode *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  ListNode *temp = reverseList_Rec(head->next);

  head->next->next = head;
  head->next = nullptr;

  return temp;
}

int main() {
  // generate two equal lists:
  ListNode *head_1 = new ListNode(5);
  ListNode *head_2 = new ListNode(5);
  fillList(head_1, 5);
  fillList(head_2, 5);

  std::cout << "Original list: ";
  displayList(head_1);
  head_1 = reverseList_Iter(head_1);
  std::cout << "List reversed iteratively: ";
  displayList(head_1);
  head_2 = reverseList_Rec(head_2);
  std::cout << "List reversed recursively: ";
  displayList(head_2);

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