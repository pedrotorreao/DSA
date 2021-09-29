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

--Time complexity: 
 
--Space complexity: 
*/

#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "singlyLinkedList/singlyLinkedList.h"

Node *loopDetection(Node *ll_head, int &pos)
{
  Node *cycle_first = nullptr;
  // ..

  return cycle_first;
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