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
      prev_node = current_node;
    }
    else
    {
      prev_node->next = current_node->next;
      sll.decLength();
    }

    current_node = current_node->next;
  }
}

int main()
{
  SinglyLinkedList sll;

  sll.feedList(10, 1, 10);

  std::cout << "--original linked list: ";
  sll.display();

  removeDups(sll);
  std::cout << "--edited linked list: ";
  sll.display();

  return 0;
}