/*********************************************************************************************/
/* Problem: Return Kth to Last (CtCi 2.2) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement an algorithm to find the kth to last element of a singly linked list.

--Reasoning:
  Since we track the size of the list as we append elements, it is just a matter 
  of iterating through the list until we get to the (list_size - k)th node and 
  return its value.

--Time complexity: O(N), where N is the size of the list.

--Space complexity: O(1), no extra space needed.
*/

#include <iostream>
#include <limits.h>
#include "singlyLinkedList/singlyLinkedList.h"

int returnKthToLast(SinglyLinkedList &sll, const int k)
{
  int ll_length{};
  ll_length = sll.getLength();

  if (k > ll_length)
  {
    std::cerr << "k is greater than the size of the list, try again!\n";
    return INT_MIN;
  }

  Node *current_node = sll.getH();

  for (int i{1}; i < (ll_length - k); i++)
  {
    current_node = current_node->next;
  }

  return current_node->data;
}

int main()
{
  SinglyLinkedList sll;
  int k{0};

  sll.feedList(10, 1, 10);

  std::cout << "--linked list: ";
  sll.display();

  std::cout << "Enter the distance to last element (k): ";
  std::cin >> k;

  std::cout << "--kth element to last: " << returnKthToLast(sll, k) << "\n";

  return 0;
}