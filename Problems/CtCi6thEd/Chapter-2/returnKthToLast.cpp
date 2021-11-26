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

int returnKthToLast_1(SinglyLinkedList &sll, const int k)
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

// CtCi Solution #3:
int returnKthToLast_2(SinglyLinkedList &sll, const int k)
{
  Node *p1 = sll.getH();
  Node *p2 = sll.getH();

  // Move p1 k nodes into the list:
  for (int i{0}; i <= k; ++i)
  {
    if (p1 == nullptr)
    {
      p1 = new Node(INT_MIN);
      return p1->data;
    }
    p1 = p1->next;
  }

  // Move them at the same pace. When p1 gets hits the end,
  // p2 will be at the rigth element.
  while (p1 != nullptr)
  {
    p1 = p1->next;
    p2 = p2->next;
  }

  return p2->data;
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

  std::cout << "--kth element to last: " << returnKthToLast_1(sll, k) << "\n";
  std::cout << "--kth element to last: " << returnKthToLast_2(sll, k) << "\n";

  return 0;
}