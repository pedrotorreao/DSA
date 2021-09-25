/*********************************************************************************************/
/* Problem: Palindrome (CtCi 2.6) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement a function to check if a linked list is a palindrome.

--Reasoning:

--Time complexity: 
 
--Space complexity: 
*/
#include <iostream>
#include "singlyLinkedList/singlyLinkedList.h"

bool isPalindrome(const Node *ll_head)
{
  bool is_palindrome{false};

  //... code

  return is_palindrome;
}

int main()
{
  SinglyLinkedList sll_1;

  // 1->2->3->2->1
  sll_1.append(1);
  sll_1.append(2);
  sll_1.append(3);
  sll_1.append(2);
  sll_1.append(1);
  std::cout << "Linked List is a palindrome: " << isPalindrome(sll_1.getH()) << "\n"; // should output 'true'

  // 1->2->3->2->1->9
  sll_1.append(9);
  std::cout << "Linked List is a palindrome: " << isPalindrome(sll_1.getH()) << "\n"; // should output 'false'

  // 9->1->2->3->2->1->9
  sll_1.prepend(9);
  std::cout << "Linked List is a palindrome: " << isPalindrome(sll_1.getH()) << "\n"; // should output 'true'

  return 0;
}