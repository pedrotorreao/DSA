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
  The approach may not be the cleanest but it's quite simple. It consists of using two arrays
  in order to keep track of the elements smaller and greater than x. Also, a counter keeps
  track of how many times x appears in the linked list, if any. After a first iteration through
  the list, we'll have the exact count for each of these cases. Now it's just a matter of 
  iterating through the list a second time replacing the current node data by the arrays elements
  beginning by the smaller, then by x and finally by the greater until they are all empty and the
  count is zero.
--Time complexity: O(n), n being the linked list length.
 
--Space complexity: O(n), in the worst case where we have only smaller/greater than x elements.
*/

#include <iostream>
#include <vector>
#include "singlyLinkedList/singlyLinkedList.h"

void partition(Node *ll_head, int x)
{
  if (ll_head == nullptr)
  {
    return;
  }

  Node *current_node = ll_head;
  std::vector<int> smaller{}; // store ll elements smaller than x
  std::vector<int> greater{}; // store ll elements greater than x
  int x_count{0}, ll_size{0};

  while (current_node != nullptr)
  {
    ll_size++; // count list elements

    if (current_node->data < x)
    {
      smaller.push_back(current_node->data);
    }
    else if (current_node->data > x)
    {
      greater.push_back(current_node->data);
    }
    else
    {
      x_count++; // count x frequency
    }

    current_node = current_node->next;
  }

  // if there are only elementes smaller than or greater than x in the
  // list, there is no partition to be done:
  if ((smaller.size() == ll_size) || (greater.size() == ll_size))
  {
    return;
  }

  current_node = ll_head; // restart pointer

  while (current_node != nullptr)
  {
    if (smaller.size())
    { // replace current data by the smaller elements
      current_node->data = smaller.back();
      smaller.pop_back();
    }
    else if (x_count)
    { // replace current data by x
      current_node->data = x;
      --x_count;
    }
    else if (greater.size())
    { // replace current data by the greater elements
      current_node->data = greater.back();
      greater.pop_back();
    }
    current_node = current_node->next;
  }
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

  std::cout << "Modified linked list: ";
  sll.display();

  return 0;
}