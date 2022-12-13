/*********************************************************************************************/
/* Problem: 23. Merge k Sorted Lists   ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given an array of 'k' linked-lists lists, each linked-list is sorted in ascending order.
  Merge all the linked-lists into one sorted linked-list and return it.

  > Example 1:
  Input: lists = [[1,4,5],[1,3,4],[2,6]]
  Output: [1,1,2,3,4,4,5,6]
  Explanation:
    The linked-lists are:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    merging them into one sorted list:
    1->1->2->3->4->4->5->6

  > Example 2:
  Input: lists = []
  Output: []

  > Example 3:
  Input: lists = [[]]
  Output: []
   
--Inputs:
  -ListNode[]: array of 'k' linked-lists lists

--Output:
  -ListNode: head of the sorted linked-list

--Constraints:
  :: k == lists.length
  :: 0 <= k <= 10^4
  :: 0 <= lists[i].length <= 500
  :: -10^4 <= lists[i][j] <= 10^4
  :: lists[i] is sorted in ascending order.
  :: The sum of lists[i].length will not exceed 10^4.

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <queue>
#include <vector>

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

/* Approach #1 - Using a Priority Queue:
--Reasoning:
  First, iterate over all the lists adding the node values to a priority queue in order to keep
  the ordering of the list nodes. After that, it's just a matter of adding the top values of the
  priority queue to a new list while popping these top values until there is no nodes left in the
  priority queue.
--Time Complexity: O(k*n*log(n))
--Space Complexity: O(n*k)
*/
ListNode *mergeKLists_1(std::vector<ListNode *> &lists) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  const int k = lists.size();

  for (int i{0}; i < k; ++i) {
    ListNode *node = lists.at(i);
    while (node) {
      pq.push(node->val);
      node = node->next;
    }
  }

  if (pq.empty())
    return nullptr;

  ListNode *new_head = new ListNode(pq.top());
  pq.pop();
  ListNode *curr = new_head;

  while (!pq.empty()) {
    curr->next = new ListNode(pq.top());
    pq.pop();
    curr = curr->next;
  }

  return new_head;
}

/* Approach #2 - Progressively merge the lists, 2 by 2:
--Reasoning:
  Utilize a divide and conquer approach and iterate over the lists array merging two each time.
--Time Complexity: O(n * log(k))
--Space Complexity: O(1)
*/
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (!list1 && !list2)
    return nullptr;
  if (!list1)
    return list2;
  if (!list2)
    return list1;

  ListNode *curr_1 = list1;
  ListNode *curr_2 = list2;
  ListNode *merged_list;

  if (curr_1->val < curr_2->val) {
    merged_list = new ListNode(curr_1->val);
    curr_1 = curr_1->next;
  } else {
    merged_list = new ListNode(curr_2->val);
    curr_2 = curr_2->next;
  }

  ListNode *curr_m = merged_list;

  while (curr_1 || curr_2) {
    if (!curr_1) {
      curr_m->next = curr_2;
      break;
    }

    if (!curr_2) {
      curr_m->next = curr_1;
      break;
    }

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

ListNode *mergeKLists_2(std::vector<ListNode *> &lists) {
  int k = lists.size();
  if (!k)
    return nullptr;

  while (k > 1) {
    for (int i{0}; i < (k / 2); ++i)
      lists.at(i) = mergeTwoLists(lists.at(i), lists.at(k - i - 1));
    k = (k + 1) / 2; // account for odd-sized lists
  }

  return lists.at(0);
}

int main() {
  // testes perform on LC platform

  return 0;
}