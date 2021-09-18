/*********************************************************************************************/
/* Problem: Remove Duplicates (CtCi 2.1) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write code to remove duplicates from an unsorted linked list. FOLLOW UP: How would you solve
  this problem if a temporary buffer is not allowed?

--Reasoning:
  Iterate through the list mapping the elements into the hash table, once an element is seen 
  again, set the previous node' next pointer to the current node' next node.

--Time complexity: O(N), where N is the length of the linked list.

--Space complexity: O(N), due to the space used to map the linked list elements.
*/

#include <iostream>
#include <list>
#include <unordered_map>
#include "singlyLinkedList/singlyLinkedList.h"

void removeDups(SinglyLinkedList &sll)
{
  std::unordered_map<int, bool> map_duplicates;

  Node *current_node = sll.getH();
  Node *prev_node = nullptr;

  while (current_node != nullptr)
  {
    if (!map_duplicates[current_node->data])
    {
      map_duplicates[current_node->data] = true;
    }
    else
    {
      prev_node->next = current_node->next;
    }

    prev_node = current_node;
    current_node = current_node->next;
  }

  sll.decLength();
}

int main()
{
  SinglyLinkedList sll;

  sll.append(2);
  sll.append(0);
  sll.append(2);
  sll.append(5);
  sll.append(1);
  sll.append(3);
  sll.append(6);
  sll.append(9);
  sll.append(5);
  sll.append(7);

  std::cout << "--original linked list: ";
  sll.display();

  removeDups(sll);
  std::cout << "--edited linked list: ";
  sll.display();

  return 0;
}