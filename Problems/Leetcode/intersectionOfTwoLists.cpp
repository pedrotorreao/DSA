/*********************************************************************************************/
/* Problem: Intersection of Two Linked Lists ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given the heads of two singly linked-lists 'headA' and 'headB', return the node at which the
  two lists intersect. If the two linked lists have no intersection at all, return 'null'.

  The test cases are generated such that there are no cycles anywhere in the entire linked
  structure. Note that the linked lists must retain their original structure after the function
  returns.

  The inputs to the judge are given as follows (your program is not given these inputs):
    > intersectVal - The value of the node where the intersection occurs. This
    is 0 if there is no intersected node.
    > listA - The first linked list.
    > listB - The second linked list.
    > skipA - The number of nodes to skip ahead in listA (starting from the head)
    to get to the intersected node.
    > skipB - The number of nodes to skip ahead in listB (starting from the head)
    to get to the intersected node.

  The judge will then create the linked structure based on these inputs and pass the two heads,
  'headA' and 'headB' to your program. If you correctly return the intersected node, then your
  solution will be accepted.

--Input:
  ListNode* : the pointers for both linked lists heads

--Output:
  ListNode*: the node at which the lists intersect

--Constraints:
    > The number of nodes of listA is in the m.
    > The number of nodes of listB is in the n.
    > 1 <= m, n <= 3 * 104
    > 1 <= Node.val <= 105
    > 0 <= skipA < m
    > 0 <= skipB < n
    > intersectVal is 0 if listA and listB do not intersect.
    > intersectVal == listA[skipA] == listB[skipB] if listA and listB intersect.

--Reasoning: See comments below.

--Time complexity: O(N + M), where N and M are the lengths of the lists.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iostream>

/*
-- listA.size == listB.size: traverse the list equally comparing the nodes
-- listA.size != listB.size: get which list is larger and the diff between their sizes
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val{x}, next{nullptr} {}
};

struct TailAndLength {
  ListNode *tail;
  int length;

  TailAndLength(ListNode *node, int size) : tail{node}, length{size} {}
};

TailAndLength *getTailAndLength(ListNode *head) {
  int size{1};
  ListNode *curr = head;

  while (curr->next != nullptr) {
    curr = curr->next;
    ++size;
  }

  return (new TailAndLength(curr, size));
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if (headA == nullptr || headB == nullptr)
    return nullptr;

  // get the tail node and the sizes of both lists:
  TailAndLength *tailLength_A = getTailAndLength(headA);
  TailAndLength *tailLength_B = getTailAndLength(headB);

  // if the tail nodes differ, there's no intersection:
  if (tailLength_A->tail != tailLength_B->tail)
    return nullptr;

  // find out the shorter/longer list and set pointers to their start:
  ListNode *shorter = (tailLength_A->length < tailLength_B->length) ? headA : headB;
  ListNode *longer = (tailLength_A->length < tailLength_B->length) ? headB : headA;

  // amount of nodes to be advanced in the longer list so they are
  // at the same distance from the intersection node:
  int nodesToSkip = abs(tailLength_A->length - tailLength_B->length);

  // skip the nodes in the longer list:
  while (nodesToSkip--) {
    longer = longer->next;
  }

  // move both pointer equally until we find the intersection:
  while (shorter != longer) {
    shorter = shorter->next;
    longer = longer->next;
  }

  return shorter;
}

int main() {
  // ---- TC #1:
  /*
  ListNode *headA = new ListNode(4);
  ListNode *node_A1 = new ListNode(1);
  headA->next = node_A1;

  ListNode *headB = new ListNode(5);
  ListNode *node_B1 = new ListNode(6);
  ListNode *node_B2 = new ListNode(1);
  headB->next = node_B1;
  node_B1->next = node_B2;

  ListNode *node = new ListNode(8);
  ListNode *node_1 = new ListNode(4);
  ListNode *node_2 = new ListNode(4);
  node->next = node_1;
  node_1->next = node_2;

  node_A1->next = node;
  node_B2->next = node;

  ListNode *intersection = getIntersectionNode(headA, headB);

  if(intersection != nullptr)
      std::cout << "Intersection: " << intersection->val << "\n";
  else
      std::cout << "No intersection\n";
  */
  // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

  // ---- TC #2:
  /*
  ListNode *headA = new ListNode(1);
  ListNode *node_A1 = new ListNode(9);
  ListNode *node_A2 = new ListNode(1);
  headA->next = node_A1;
  node_A1->next = node_A2;

  ListNode *headB = new ListNode(3);

  ListNode *node = new ListNode(2);
  ListNode *node_1 = new ListNode(4);
  node->next = node_1;

  node_A2->next = node;
  headB->next = node;

  ListNode *intersection = getIntersectionNode(headA, headB);

  if(intersection != nullptr)
      std::cout << "Intersection: " << intersection->val << "\n";
  else
      std::cout << "No intersection\n";
  */
  // ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ----

  // ---- TC #3:
  ListNode *headA = new ListNode(2);
  ListNode *node_A1 = new ListNode(6);
  ListNode *node_A2 = new ListNode(4);
  headA->next = node_A1;
  node_A1->next = node_A2;

  ListNode *headB = new ListNode(1);
  ListNode *node_B1 = new ListNode(5);
  headB->next = node_B1;

  ListNode *intersection = getIntersectionNode(headA, headB);

  if (intersection != nullptr)
    std::cout << "Intersection: " << intersection->val << "\n";
  else
    std::cout << "No intersection\n";

  return 0;
}