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

// helper methods - forward declarations:
void fillList(ListNode *head, int size);
void displayList(ListNode *head);

ListNode *oddEvenList(ListNode *head) {
  if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
    return head;

  ListNode *odds = head;        // head of the odd indexed list
  ListNode *evens = head->next; // head of the even indexed list

  ListNode *curr_odd = odds;   // pointer to the current odd indexed node
  ListNode *curr_even = evens; // pointer to the current even indexed node

  while (curr_even != nullptr) {
    // skip even node and set the 'next' ref. to the next odd node:
    curr_odd->next = curr_even->next;
    // advance in case we haven't got to the end of the odd nodes list:
    if (curr_odd->next)
      curr_odd = curr_odd->next;

    // skip odd node and set the 'next' ref. to the next even node:
    curr_even->next = curr_odd->next;
    // advance until we get to the end of the even nodes list:
    curr_even = curr_even->next;
  }
  // curr_odd now is the last node in the odd list, point it to the head of the even list:
  curr_odd->next = evens;

  return head;
}

int main() {
  // .. add test cases

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