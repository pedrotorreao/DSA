/******************************************************************************
DS: Singly Linked List (SLL)
*******************************************************************************/
#include <iostream>
#include <string>

class Node
{
public:
  std::string data;
  Node *next;

  Node(std::string s)
  {
    this->data = s;
    this->next = nullptr;
  }
};

class SinglyLinkedList
{
private:
  Node *head;
  Node *tail;
  int length;

public:
  void append(std::string s);                   // add s to the end
  void prepend(std::string s);                  // add s to the beginning
  void insertNode(std::string s, int position); // insert s at a specific position
  void deleteNode(std::string s);               // remove s from the LL
  void search(std::string s);                   // search for s in the LL
  void reverse(void);
  void displayLinkedList(void);

  SinglyLinkedList()
  {
    this->head = nullptr;
    this->tail = this->head;
    this->length = 0;
  }
  ~SinglyLinkedList() {}
};

void SinglyLinkedList::append(std::string s) // add s to the end
{
  Node *temp = new Node(s);

  if (this->head == nullptr)
  {
    this->head = temp;
    this->tail = this->head;
  }
  else
  {
    this->tail->next = temp;
    this->tail = temp;
  }
  ++this->length;
}

void SinglyLinkedList::prepend(std::string s) // add s to the beginning
{
  Node *temp = new Node(s);

  if (head == nullptr)
  {
    this->head = temp;
    this->tail = this->head;
  }
  else
  {
    temp->next = this->head;
    this->head = temp;
  }
  ++this->length;
}

void SinglyLinkedList::insertNode(std::string s, int position) // insert s at a specific position
{
  if (position <= 1)
  {
    this->prepend(s);
    return;
  }
  else if (position > this->length)
  {
    this->append(s);
    return;
  }

  Node *temp = this->head;
  Node *new_node = new Node(s);
  int pos = 1;

  while (pos < position - 1)
  {
    temp = temp->next;
    pos++;
  }
  new_node->next = temp->next;
  temp->next = new_node;
}

void SinglyLinkedList::deleteNode(std::string s) // remove s from the LL
{
  Node *temp = this->head;

  while (temp->next->data != s)
  {
    temp = temp->next;
  }

  temp->next = temp->next->next;
}

void SinglyLinkedList::search(std::string s) // search for s in the LL
{
  Node *temp = this->head;
  int pos = 1;

  while (temp != nullptr)
  {
    if (temp->data == s)
    {
      std::cout << "Found " << s << " at position " << pos << "\n";
      return;
    }
    temp = temp->next;
    ++pos;
  }
  std::cout << s << " is not stored."
            << "\n";
}
void SinglyLinkedList::reverse(void)
{
  if (!this->head->next)
    return;

  Node *first = this->head;
  Node *second = first->next;

  while (second != nullptr)
  {
    Node *temp = second->next;
    second->next = first;
    first = second;
    second = temp;
  }

  this->head->next = nullptr;
  this->tail = this->head;
  this->head = first;
}
void SinglyLinkedList::displayLinkedList(void)
{
  Node *temp = this->head;

  while (temp != nullptr)
  {
    std::cout << temp->data;
    if (temp->next != nullptr)
      std::cout << " -> ";
    temp = temp->next;
  }
  std::cout << "\n";
}

int main()
{
  SinglyLinkedList sll;

  sll.append("RECIFE");
  sll.append("SALVADOR");
  sll.append("CAMPINA");
  sll.displayLinkedList();

  sll.prepend("ARAXA");
  sll.displayLinkedList();

  sll.insertNode("RIO", 3);
  sll.displayLinkedList();
  sll.insertNode("PATOS", 0);
  sll.displayLinkedList();
  sll.insertNode("AREIAS", 6);
  sll.displayLinkedList();

  sll.deleteNode("RIO");
  sll.deleteNode("AREIAS");
  sll.displayLinkedList();

  sll.search("SALVADOR");
  sll.search("RIO");

  sll.reverse();
  sll.displayLinkedList();

  return 0;
}
