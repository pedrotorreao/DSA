/*********************************************************************************************/
/* Problem: Delete Middle Node (CtCi 2.3) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement an algorithm to delete a node in the middle (i.e., anynode but the first and last
  node, noot necessarily the exact middle) of a singly linked list, given only access to that
  node.
  Example:
    input: the node c from the linked list a->b->c->d->e->f 
    result: nothing is returned, but the new linked list looks like a->b->d->e->f 

--Reasoning:
  As we only have access to the node which must be deleted, we can perform the deletion by 
  replacing the node data with the next node data and pointing its *next reference to the next 
  node reference. After that, we can just remove the next node since all of its data have been
  copied already.

--Time complexity: O(1), it is just a matter of manipulating the references.

--Space complexity: O(1), used space does not depend on the input size.
*/

#include <iostream>
#include "singlyLinkedList/singlyLinkedList.h"

void deleteMiddleNode(Node *middle_node)
{
  if (middle_node->next == nullptr)
  {
    std::cerr << "cannot delete tail node!\n";
    return;
  }

  if (middle_node != nullptr)
  {
    Node *new_middle = middle_node->next;

    middle_node->data = new_middle->data;
    middle_node->next = new_middle->next;

    delete new_middle;
  }
}

int main()
{
  SinglyLinkedList sll;
  int ll_size{0}, min_val{0}, max_value{0};

  std::cout << "Enter linked list info...\n"
            << "-- number of nodes: ";
  std::cin >> ll_size;
  std::cout << "-- min. value: ";
  std::cin >> min_val;
  std::cout << "-- max. value: ";
  std::cin >> max_value;

  sll.feedList(ll_size, min_val, max_value);

  std::cout << "Original linked list: ";
  sll.display();

  Node *ll_head = sll.getH();
  Node *ll_mid = ll_head->next->next->next;

  deleteMiddleNode(ll_mid);
  sll.decLength();

  std::cout << "Modified linked list: ";
  sll.display();

  return 0;
}