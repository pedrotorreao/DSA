/*********************************************************************************************/
/* Problem: Partition (CtCi 2.4) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write code to partition a linked list around a value x, such that all nodes less than x come
  before all nodes greater than or equal to x. If x is contained within the list, the values of
  x only need to be after the elements less than x. The partition element x can appear anywhere
  in the "right partition"; it does not need to appear between the left and right partitions.
    Input:  3->5->8->5->10->2->1  [partition = 5]
    Output: 3->1->2->10->5->5->8

--Reasoning:

--Time complexity: 

--Space complexity: 
*/

#include <iostream>
#include "singlyLinkedList/singlyLinkedList.h"

void partition(Node *ll_head, int x)
{
  //..code
}

int main()
{
  SinglyLinkedList sll;
  int ll_size{0}, min_val{0}, max_value{0}, x{0};

  // -- Get list info. and generate list:
  std::cout << "Enter linked list info...\n"
            << "-- number of nodes: ";
  std::cin >> ll_size;
  std::cout << "-- min. value: ";
  std::cin >> min_val;
  std::cout << "-- max. value: ";
  std::cin >> max_value;

  sll.feedList(ll_size, min_val, max_value);
  // --

  std::cout << "Enter the value to partition the list around (x): ";
  std::cin >> x;

  std::cout << "Original linked list: ";
  sll.display();

  Node *ll_head = sll.getH();

  partition(ll_head, x);

  std::cout << "Partitioned linked list: ";
  sll.display();

  return 0;
}