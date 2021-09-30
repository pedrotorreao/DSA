/*********************************************************************************************/
/* Problem: Loop Detection (CtCi 2.7) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a circular linked list, implement an algorithm that returns the node at the the 
  beginning of the loop. 
  Definition - Circular linked list: a corrupt linked list in which a node's next pointer
  points to an earlier node, so as to make a loop in the linked list.
  Example:
    Input: A->B->C*->D->E->C*
    Output: C*

--Reasoning:
  Traverse the list while mapping the nodes and their positions to a hash map until we find a 
  node that was already mapped, which indicates the presence of a cycle, since the only way we
  visit the same node again is if there is another node further down the list whose next 
  pointer is  pointing back to this node. Then we return this node and update the position to
  this node's position. In case we reach the end of the linked list without coming across a 
  repeated node, we return the nullptr to indicate that a cycle was not found.

--Time complexity: 
  O(L), where L is the length of the linked list.
 
--Space complexity: 
  O(L), where L is the length of the linked list, since we need to store L nodes in the hash map.
*/

#include <iostream>
#include <unordered_map>
#include "singlyLinkedList/singlyLinkedList.h"

Node *loopDetection(Node *ll_head, int &pos)
{
  Node *current_node = ll_head;
  std::unordered_map<Node *, int> map_sll;

  while (current_node != nullptr)
  {
    if (!map_sll[current_node])
    {
      map_sll[current_node] = pos;
    }
    else
    {
      pos = map_sll[current_node];

      return current_node;
    }

    current_node = current_node->next;
    ++pos;
  }

  return nullptr;
}

int main()
{
  SinglyLinkedList sll;

  // sll: 4->8->1->2->9->8*
  sll.append(4);

  Node *new_node = new Node(8);
  sll.appendNode(new_node);

  sll.append(1);
  sll.append(2);
  sll.append(9);

  sll.appendNode(new_node);

  Node *cycle_node = nullptr;
  int cycle_position{1}; // 1-based length

  cycle_node = loopDetection(sll.getH(), cycle_position);

  if (cycle_node)
  {
    std::cout << "Cycle detected at position: " << cycle_position
              << " in the list - Node: " << cycle_node->data << "\n";
  }
  else
  {
    std::cout << "No cycle detected!\n";
  }

  return 0;
}