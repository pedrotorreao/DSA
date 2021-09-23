/*********************************************************************************************/
/* Problem: Sum Lists (CtCi 2.5) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You have two numbers represented by a linked list, where each node contains a single digit.
  The digits are stored in reverse order, such that the 1's digit is at the head of the list.
  Write a function that adds the two numbers and returns the sum as a linked list.
  Example:
    Input: (7->1->6) + (5->9->2) ----> 617 + 295 = 912
    Output: (2->1->9)

--Reasoning:
  Assuming both linked lists represent positive integer numbers, iterate through both linked lists
  and at each step multiply each element by its radix and sum to the previous result. In this way 
  we can build the calculate the number represented by each list. After that, sum the numbers and 
  use the modulus operator in order to get each individual digit of this number and append it to 
  a new list.

--Time complexity: O(L), where L is the length of the largest linked list.
 
--Space complexity: O(L'), where L' is the length of the resulting linked list.
*/

#include <iostream>
#include <vector>
#include "singlyLinkedList/singlyLinkedList.h"

SinglyLinkedList sumLists(const SinglyLinkedList &ll1, const SinglyLinkedList &ll2)
{
  SinglyLinkedList sll_sum;

  Node *current_node = ll1.getH();
  int numll_1{}, mult{1};

  // extract integer from the linked list 1:
  while (current_node != nullptr)
  {
    numll_1 += ((current_node->data) * mult);
    mult *= 10;

    current_node = current_node->next;
  }

  current_node = ll2.getH();
  int numll_2{};
  mult = 1;

  // extract integer from the linked list 2:
  while (current_node != nullptr)
  {
    numll_2 += ((current_node->data) * mult);
    mult *= 10;

    current_node = current_node->next;
  }

  int sum_ll = numll_1 + numll_2;
  int prev_divisor{1}, divisor{10};

  while (sum_ll > 0)
  {
    // extract current digit from the sum:
    //    If (sum_ll > divisor): current sum is big enough to use modulus operator.
    //    Then ((sum_ll % divisor) / prev_divisor)
    //    Else (sum_ll / prev_divisor): all digits were extracted but the most significant one.
    // the division by prev_divisor aims to single out the exact digit from the result of the modulus operation.
    int data = (sum_ll > divisor) ? ((sum_ll % divisor) / prev_divisor) : (sum_ll / prev_divisor);
    sll_sum.append(data); // add digit to the end of the list

    sum_ll = (sum_ll - (sum_ll % divisor)); // update current sum
    prev_divisor = divisor;                 // update both divisors to another radix
    divisor *= 10;
  }

  return sll_sum;
}

int main()
{
  SinglyLinkedList sll_1;
  sll_1.append(7);
  sll_1.append(1);
  sll_1.append(6);
  std::cout << "Linked List 1: ";
  sll_1.display();

  SinglyLinkedList sll_2;
  sll_2.append(5);
  sll_2.append(9);
  sll_2.append(0);
  sll_2.append(3);
  std::cout << "Linked List 2: ";
  sll_2.display();

  SinglyLinkedList sll_sum;
  sll_sum = sumLists(sll_1, sll_2);
  std::cout << "Linked List Sum: ";
  sll_sum.display();

  return 0;
}