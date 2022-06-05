/*********************************************************************************************/
/* Problem: Copy List with Random Pointer (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  A linked list of length 'n' is given such that each node contains an additional random pointer,
  which could point to any node in the list, or 'null'.

  Construct a deep copy of the list. The deep copy should consist of exactly 'n' brand new nodes,
  where each new node has its value set to the value of its corresponding original node. Both
  the 'next' and 'random' pointer of the new nodes should point to new nodes in the copied list
  such that the pointers in the original list and copied list represent the same list state.
  None of the pointers in the new list should point to nodes in the original list.

  For example, if there are two nodes 'X' and 'Y' in the original list, where
      X.random --> Y,
  then for the corresponding two nodes 'x' and 'y' in the copied list,
      x.random --> y.

  Return the head of the copied linked list.

  The linked list is represented in the input/output as a list of 'n' nodes. Each node is represented
  as a pair of [val, random_index] where:
    -val: an integer representing Node.val
    -random_index: the index of the node (range from 0 to n-1) that the random pointer points to,
    or 'null' if it does not point to any node.

  Your code will only be given the head of the original linked list.

  > Example 1:
    Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
    Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

  > Example 2:
    Input: head = [[1,1],[2,1]]
    Output: [[1,1],[2,1]]

  > Example 3:
    Input: head = [[3,null],[3,0],[3,null]]
    Output: [[3,null],[3,0],[3,null]]

--Inputs:
  -Node*: head node of the original linked list.

--Output:
  -Node*: head node of the deep copied linked list.

--Constraints:
    0 <= n <= 1000
    -104 <= Node.val <= 104
    Node.random is null or is pointing to some node in the linked list.

--Reasoning: See comments below.

--Time complexity: O(N), where N is the length of the linked list.

--Space complexity: O(N), due to the hash map created, where N is the length of the linked list.

*/

#include <iostream>
#include <unordered_map>

// Definition for a Node:
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

Node *copyRandomList(Node *head) {
  // hash map for mapping each list1 node to its copy:
  std::unordered_map<Node *, Node *> nodeMap;
  // pointer to the head of the original linked list:
  Node *curr = head;
  // iterate over list1 until the end of the list. This 1st pass
  // is to deep copy each node:
  while (curr != NULL) {
    // map current list1 node to its copy:
    nodeMap[curr] = new Node(curr->val);
    // advance to the next node in list1:
    curr = curr->next;
  }
  // get pointer back to the head of list1:
  curr = head;
  // iterate over list1 again. In this 2nd pass we use the hash map
  // built previously to assign the pointers for the copy list:
  while (curr != NULL) {
    Node *new_curr = nodeMap[curr];         // copy of current node
    Node *new_next = nodeMap[curr->next];   // copy of current node 'next' pointed node
    Node *new_rndm = nodeMap[curr->random]; // copy of current node 'random' pointed node

    // assign the pointers for the copied list:
    new_curr->next = new_next;
    new_curr->random = new_rndm;

    // advance to the next node in list1:
    curr = curr->next;
  }

  // return the head node of the copied list:
  return nodeMap[head];
}

int main() {
  //..
  return 0;
}
