/*********************************************************************************************/
/* Problem: 143. Reorder List   ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given the head of a singly linked-list. The list can be represented as:
  L0 → L1 → … → Ln - 1 → Ln

  Reorder the list to be on the following form:
  L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

  You may not modify the values in the list's nodes. Only nodes themselves may be changed.

  Example 1:
    Input: head = [1,2,3,4]
    Output: [1,4,2,3]

  Example 2:
    Input: head = [1,2,3,4,5]
    Output: [1,5,2,4,3]

--Inputs:
  -ListNode: head of a singly linked-list

--Output:
  -ListNode: head of the reordered singly linked-list

--Constraints:
  :: The number of nodes in the list is in the range [1, 5 * 10^4].
  :: 1 <= Node.val <= 1000

--Reasoning:
  Use the "slow and fast pointers" technique to reach the middle of the list without
  having to traverse it twice. After one pass, the 'fast' pointer will have reached the end
  of the list, while the 'slow' pointer will be exactly at the middle of the list. We'll
  also keep a 'temp' pointer to the node before the middle. After this, it's just a matter of
  reversing the second half of the list and merging the two lists.

--Time complexity: O(N), where N is the size of the list.

--Space complexity: O(1), no additional input dependent space is allocated.

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

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void mergeTwoLists(ListNode *l1, ListNode *l2) {
  while (l1 && l2) {
    ListNode *p1 = l1->next;
    ListNode *p2 = l2->next;

    l1->next = l2;
    if (p1 == nullptr)
      break;
    l2->next = p1;

    l1 = p1;
    l2 = p2;
  }
}

ListNode *reverseList(ListNode *head) {
  if (!head || !head->next)
    return head;

  ListNode *first = head;
  ListNode *second = first->next;

  while (second) {
    ListNode *temp = second->next;

    second->next = first;
    first = second;

    second = temp;
  }

  head->next = nullptr;
  head = first;

  return head;
}

void reorderList(ListNode *head) {
  if (!head || !head->next)
    return;

  ListNode *prev = nullptr;
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  prev->next = nullptr;

  ListNode *l1 = head;
  ListNode *l2 = reverseList(slow);

  mergeTwoLists(l1, l2);
}

int main() {
  // tested on LC platform itself

  return 0;
}