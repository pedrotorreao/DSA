/*********************************************************************************************/
/* Problem: Palindrome (CtCi 2.6) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Implement a function to check if a linked list is a palindrome.

--Reasoning:
  Considering that we pass as argument just the linked list head and not the list itself, we
  first iterate through the entire list once to get the size of the list and map into a hash
  table each position and its element, hashtable(key, value) --> hashtable(position, element).
  After that, we iterate over the hash table, but this time only until the position that 
  corresponds to the list size divided by two, since if it's a permutation, the elements will
  be mirrored. And that is basically it, at each position until list_size/2 we check if the
  element in that same position from the end is the same. If not, we return false. If we get 
  to the end of the lookups for the hash table without mismatches, it means that the list is
  a palindrome and we return true.

--Time complexity: O(L), where L is the length of the linked list (the number of elements)
 
--Space complexity: O(L), since we need additional space for mapping the L elements.
*/
#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include "singlyLinkedList/singlyLinkedList.h"

bool isPalindrome(Node *ll_head)
{
  std::unordered_map<int, int> map_ll;
  int ll_size{}; //since we are not passing the LL as argument, we need to measure its size.

  Node *current_node = ll_head;

  while (current_node != nullptr)
  {
    ++ll_size;

    map_ll[ll_size] = current_node->data; // map key:position, value:list_element

    current_node = current_node->next;
  }

  int i{1}; // position tracker
  // iterate until we reach the middle of the list checking if the current element matches its
  // mirrored counterpart:
  while (i <= ceil(ll_size / 2)) // 'ceil' is used for the case where we have an odd sized list
  {
    if (map_ll[i] != map_ll[ll_size - i + 1])
    {
      return false;
    }
    ++i;
  }

  return true;
}

int main()
{
  std::cout << std::boolalpha;

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

  SinglyLinkedList sll_2;
  //0->1->1->2->9->9->2->1->1->0
  sll_2.append(0);
  sll_2.append(1);
  sll_2.append(1);
  sll_2.append(2);
  sll_2.append(9);
  sll_2.append(9);
  sll_2.append(2);
  sll_2.append(1);
  sll_2.append(1);
  sll_2.append(0);
  std::cout << "Linked List is a palindrome: " << isPalindrome(sll_2.getH()) << "\n"; // should output 'true'

  SinglyLinkedList sll_3;
  sll_3.feedList(10, 1, 5);
  sll_3.display();
  std::cout << "Linked List is a palindrome: " << isPalindrome(sll_3.getH()) << "\n";

  return 0;
}