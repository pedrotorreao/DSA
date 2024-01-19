/* * * * * * * * * * * * * * * * * *
Problem: LC 2487. Remove Nodes From Linked List

--Problem statement:
You are given the head of a linked list. Remove every node which has a node with a greater
value anywhere to the right side of it. Return the head of the modified linked list.

  Example 1:
    Input: head = [5,2,13,3,8]
    Output: [13,8]
    Explanation: The nodes that should be removed are 5, 2 and 3.
    - Node 13 is to the right of node 5.
    - Node 13 is to the right of node 2.
    - Node 8 is to the right of node 3.

  Example 2:
    Input: head = [1,1,1,1]
    Output: [1,1,1,1]
    Explanation: Every node has value 1, so no nodes are removed.

--Constraints:
    :: The number of the nodes in the given list is in the range [1, 10^5].
    :: 1 <= Node.val <= 105

--Inputs:
  - ListNode*: the head of a linked list.

--Outputs:
  - ListNode*: the head of the modified linked list.

--Reasoning: Monotonic Stack approach. See comments below.

--Time complexity:
    :: O(n), where n is the length of the linked list, since every node is visited once while
    traversing the list. Also, each node is pushed and popped from the stack at most once, so
    the total operations are still proportional to n.

--Space complexity:
    :: O(n), due to the additional space needed for the stack.

* * * * * * * * * * * * * * * * * */

#include <iostream>
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int val) : val(val), next(nullptr) {}
};

void displaySLL(ListNode *head);

class Solution {
public:
  static ListNode *removeNodes(ListNode *head) {
    // stack for storing the list nodes:
    std::stack<ListNode *> st;

    ListNode *curr = head;

    while (curr) {
      // remove from the stack the nodes with values smaller than the current node:
      while (!st.empty() && st.top()->val < curr->val) {
        ListNode *st_top = st.top();
        st.pop();
        // invalidate the pointer:
        st_top->next = nullptr;
      }
      // update the 'next' pointer of the node at the top of the stack to point to the
      // current node, which has a smaller value:
      if (!st.empty())
        st.top()->next = curr;
      // otherwise, if the stack is empty, it means that the current node has the largest
      // value so far, so make it the new head:
      else
        head = curr;

      // push the current node onto the stack:
      st.push(curr);

      curr = curr->next;
    }
    return head;
  }
};

int main() {
  ListNode *h = new ListNode(5);
  ListNode *c = new ListNode(2);
  h->next = c;
  c->next = new ListNode(13);
  c = c->next;
  c->next = new ListNode(3);
  c = c->next;
  c->next = new ListNode(8);

  displaySLL(h);

  h = Solution::removeNodes(h);
  displaySLL(h);
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