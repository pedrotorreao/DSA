/******************************************************************************
- Data Structure: Singly Linked List (SLL)
*******************************************************************************/
#include <iostream>
#include <random>
#include "singlyLinkedList.h"

Node::Node(int d)
{
  this->data = d;
}

Node::~Node() = default;

SinglyLinkedList::SinglyLinkedList()
{
  this->head = nullptr;
  this->tail = this->head;
  this->length = 0;
}

SinglyLinkedList::~SinglyLinkedList() = default;

void SinglyLinkedList::append(int d)
{
  Node *new_node = new Node(d);

  if (head == nullptr)
  {
    this->head = new_node;
    this->tail = this->head;
  }
  else
  {
    this->tail->next = new_node;
    this->tail = new_node;
  }
  ++this->length;
}

void SinglyLinkedList::display()
{
  if (head == nullptr)
  {
    std::cerr << "Empty List!" << std::endl;
    return;
  }

  Node *current_node = this->head;

  while (current_node != nullptr)
  {
    std::cout << current_node->data;
    if (current_node->next != nullptr)
    {
      std::cout << " -> ";
    }
    current_node = current_node->next;
  }
  std::cout << "\n";
}

Node *SinglyLinkedList::getH() const
{
  return this->head;
}

int SinglyLinkedList::getLength()
{
  return this->length;
}

void SinglyLinkedList::incLength()
{
  this->length++;
}

void SinglyLinkedList::decLength()
{
  this->length--;
}

void SinglyLinkedList::feedList(int numOfNodes, int min, int max)
{
  std::random_device rndm;
  std::mt19937 mt(rndm());
  std::uniform_int_distribution<int> distribution(min, max);

  for (int i{0}; i < numOfNodes; i++)
  {
    this->append(distribution(mt));
  }
}