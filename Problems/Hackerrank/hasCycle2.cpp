/****************************************************************/
/*Problem: Cycle Detection (HR) ********/
/****************************************************************/
/*
-- Summary:
A linked list is said to contain a cycle if any node is visited more than once while traversing the list. Complete the function provided for you in your editor. It has one parameter: a pointer to a Node object named head that points to the head of a linked list. Your function must return a boolean denoting whether or not there is a cycle in the list. If there is a cycle, return true; otherwise, return false.
-- Input(s):
HR default.
-- Expected output(s):
If the list contains a cycle, your function must return true. If the list does not contain a cycle, it must return false. Note that the head pointer may be 'NULL' if the list is empty.
-- Constraints:
*/

#include <iostream>
#include <map>

struct Node
{
  int data;
  struct Node *next;
};

bool has_cycle(Node *head)
{
  if (head == NULL)
  {
    return false;
  }
  std::map<Node *, bool> llMap;
  Node *currentNode;

  currentNode = head;

  while (currentNode != NULL)
  {
    if (llMap[currentNode])
    {
      return true;
    }
    llMap[currentNode] = true;
    currentNode = currentNode->next;
  }
  return false;
}