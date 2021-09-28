/*********************************************************************************************/
/* Problem: Intersection (CtCi 2.7) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given two (singly) linked lists, determine if the two lists intersect. Return the intersecting
  node. Note that the intersection is defined based on reference, not value. That is, if the kth
  node of the first linked list is the exact same node (by reference) as the jth node of the 
  second linked list, then they are intersecting.

--Reasoning:
  Traverse the lists while mapping the nodes to a hash map until we find a node already mapped or
  until we reach the end of both lists. For this solution I'm assuming that there are no cycles
  present in the lists.

--Time complexity: 
  O(L), where L is the length of the longest list and either there are no intersections or the 
  intersection is at the last node of the longest linked list.
 
--Space complexity: 
  O(L'), for the case where there is no intersection and we need to store (L' = L1 + L2) nodes
  in the hash map.
*/
#include <iostream>
#include <unordered_map>
#include "singlyLinkedList/singlyLinkedList.h"

Node *intersection(Node *ll_head1, Node *ll_head2)
{
  std::unordered_map<Node *, bool> ll_map;

  Node *current_1 = ll_head1;
  Node *current_2 = ll_head2;

  // keep traversing the lists until we reach the end on both lists or we find the intersection
  while (current_1 != nullptr || current_2 != nullptr)
  {
    if (current_1 != nullptr)
    {
      if (ll_map[current_1]) // intersection: current_1 has already been found in ll_2
      {
        return current_1;
      }
      ll_map[current_1] = true;
      current_1 = current_1->next;
    }

    if (current_2 != nullptr)
    {
      if (ll_map[current_2]) // intersection: current_2 has already been found in ll_1
      {
        return current_2;
      }
      ll_map[current_2] = true;
      current_2 = current_2->next;
    }
  }

  return nullptr;
}

int main()
{
  SinglyLinkedList sll_1, sll_2;
  // -- test case 1: intersection at node (data: 0, next: 8..)
  /* 9 -> 3 -> 7
                \
                 0 -> 8 -> 4
               /
        1 -> 2
  */
  sll_1.append(9);
  sll_1.append(3);
  sll_1.append(7);
  sll_2.append(1);
  sll_2.append(2);

  Node *new_node = new Node(0);

  sll_1.appendNode(new_node);
  sll_2.appendNode(new_node);

  sll_1.append(8);
  sll_1.append(4);

  sll_1.display();
  sll_2.display();

  Node *ll_intersection = intersection(sll_1.getH(), sll_2.getH()); // intersection at node 0

  if (ll_intersection != nullptr)
  {
    std::cout << "Lists intersect at node - value: " << ll_intersection->data << " | next node: " << ll_intersection->next->data << "\n";
  }
  else
  {
    std::cout << "Lists do not intersect!\n";
  }

  sll_1.clearList();
  sll_2.clearList();
  new_node = nullptr;
  ll_intersection = nullptr;

  // -- test case 2: intersection at node (data: 9, next: 8..)
  /* 9 -> 3 -> 7
                \
                 9 -> 8 -> 4
               /
        9 -> 2
  */
  sll_1.append(9);
  sll_1.append(3);
  sll_1.append(7);
  sll_2.append(9);
  sll_2.append(2);

  new_node = new Node(9);

  sll_1.appendNode(new_node);
  sll_2.appendNode(new_node);

  sll_1.append(8);
  sll_1.append(4);

  sll_1.display();
  sll_2.display();

  ll_intersection = intersection(sll_1.getH(), sll_2.getH()); // intersection at node 0

  if (ll_intersection != nullptr)
  {
    std::cout << "Lists intersect at node - value: " << ll_intersection->data << " | next node: " << ll_intersection->next->data << "\n";
  }
  else
  {
    std::cout << "Lists do not intersect!\n";
  }

  sll_1.clearList();
  sll_2.clearList();
  new_node = nullptr;
  ll_intersection = nullptr;

  // -- test case 3: intersection at node (data: 0, next: 8..)
  /* 9 -> 3 -> 7
                \
                 0 -> 8 -> 4
  */
  sll_1.append(9);
  sll_1.append(3);
  sll_1.append(7);

  new_node = new Node(0);

  sll_1.appendNode(new_node);
  sll_2.appendNode(new_node);

  sll_1.append(8);
  sll_1.append(4);

  sll_1.display();
  sll_2.display();

  ll_intersection = intersection(sll_1.getH(), sll_2.getH()); // intersection at node 0

  if (ll_intersection != nullptr)
  {
    std::cout << "Lists intersect at node - value: " << ll_intersection->data << " | next node: " << ll_intersection->next->data << "\n";
  }
  else
  {
    std::cout << "Lists do not intersect!\n";
  }

  sll_1.clearList();
  sll_2.clearList();
  new_node = nullptr;
  ll_intersection = nullptr;

  // -- test case 4: no intersection (2 random LLs)
  sll_1.feedList(10, 1, 10);
  sll_2.feedList(5, 3, 8);

  sll_1.display();
  sll_2.display();

  ll_intersection = intersection(sll_1.getH(), sll_2.getH());

  if (ll_intersection != nullptr)
  {
    std::cout << "Lists intersect at node - value: " << ll_intersection->data << " | next node: " << ll_intersection->next->data << "\n";
  }
  else
  {
    std::cout << "Lists do not intersect!\n";
  }

  sll_1.clearList();
  sll_2.clearList();
  new_node = nullptr;
  ll_intersection = nullptr;

  return 0;
}