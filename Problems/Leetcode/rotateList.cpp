/******************************************************************************
LC 61. Rotate List
*******************************************************************************/
/*
Given the head of a linked list, rotate the list to the right by k places.
Example 1:
    Input: head = [1,2,3,4,5], k = 2
    Output: [4,5,1,2,3]

Example 2:
    Input: head = [0,1,2], k = 4
    Output: [2,0,1]

Constraints:
    The number of nodes in the list is in the range [0, 500].
    -100 <= Node.val <= 100
    0 <= k <= 2 * 109
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

ListNode *rotateRight_1(ListNode *head, int k) {
  if (head == nullptr || head->next == nullptr || k == 0)
    return head;

  ListNode *curr = head;
  ListNode *nh = head;
  int ll_length{1};

  // find the length of the list:
  while (curr->next != nullptr) {
    ++ll_length;
    curr = curr->next;
  }

  // if (k = length), it's equivalent to rotating all the elements, which would
  // get us right back to the original list, so just return the original list:
  if (k == ll_length)
    return head;

  // if (k > length), we only need to rotate (k % ll_length) elements since, as
  // we know, rotating (ll_length) elements get us the same list as the original:
  int rotations = (k > ll_length) ? (k % ll_length) : k;

  curr = head;

  // advance curr pointer to get to the new head node:
  while (ll_length - 1 > rotations) {
    --ll_length;
    curr = curr->next;
  }

  nh = curr->next; // new head node
  if (nh == nullptr)
    return head;

  curr->next = nullptr; // dettach the rest of the list
  curr = nh;            // pointer to the new head node

  // get to the end of the new head node list:
  while (curr->next != nullptr) {
    curr = curr->next;
  }

  // attach new tail to old head:
  curr->next = head;
  // head is now the new head:
  head = nh;

  return head;
}

ListNode *rotateRight_2(ListNode *head, int k) {
  // in case the list is empty, has only one node or
  // no rotation is needed, return head:
  if (head == nullptr || head->next == nullptr || k == 0)
    return head;

  ListNode *tail = head;
  int ll_length{1};

  // calculate the list length:
  while (tail->next != nullptr) {
    ++ll_length;
    tail = tail->next;
  }
  // attach tail to head node, creating a loop:
  tail->next = head;
  // number of shifts needed:
  int rotations = ll_length - (k % ll_length);

  for (int i{0}; i < rotations; ++i)
    tail = tail->next;

  head = tail->next;
  tail->next = nullptr;

  return head;
}

void displayList(ListNode *head);

int main() {
  int val{0};
  ListNode *h = new ListNode(0);
  ListNode *c = h;

  for (int i{0}; i < 5; ++i) {
    c->next = new ListNode(++val);
    c = c->next;
  }
  displayList(h);

  // ListNode *h1 = rotateRight_1(h,3);
  ListNode *h2 = rotateRight_2(h, 3);

  // displayList(h1);
  displayList(h2);

  return 0;
}

void displayList(ListNode *head) {
  ListNode *c = head;
  std::cout << "List: ";

  while (c != nullptr) {
    std::cout << c->val << "   ";
    c = c->next;
  }

  std::cout << "\n";
}
