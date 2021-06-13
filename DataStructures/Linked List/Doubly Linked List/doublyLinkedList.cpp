/******************************************************************************
-- DS: Doubly Linked List (DLL)
*******************************************************************************/
#include <iostream>
#include <string>

class Node
{
public:
  std::string data;
  Node *next;
  Node *prev;

  Node(std::string s)
  {
    this->data = s;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class DoublyLinkedList
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
  void getSize(void);
  void displayLinkedList(void);

  DoublyLinkedList()
  {
    this->head = nullptr;
    this->tail = this->head;
    this->length = 0;
  }
  ~DoublyLinkedList() {}
};

void DoublyLinkedList::append(std::string s) // add s to the end
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
    temp->prev = this->tail;
    this->tail = temp;
  }
  ++this->length;
}

void DoublyLinkedList::prepend(std::string s) // add s to the beginning
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
    this->head->prev = temp;
    this->head = temp;
  }
  ++this->length;
}

void DoublyLinkedList::insertNode(std::string s, int position) // insert s at a specific position
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
  new_node->prev = temp;
  temp->next = new_node;
}

void DoublyLinkedList::deleteNode(std::string s) // remove s from the LL
{
  if (this->head->data == s)
  {
    this->head = this->head->next;
    this->head->prev = nullptr;
    return;
  }

  Node *temp = this->head;

  while (temp->next->data != s)
  {
    temp = temp->next;
  }

  if (temp->next == this->tail)
  {
    this->tail = this->tail->prev;
    this->tail->next = nullptr;
    return;
  }

  temp->next = temp->next->next;
  temp->next->prev = temp;
  --this->length;
}

void DoublyLinkedList::search(std::string s) // search for s in the LL
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

void DoublyLinkedList::getSize(void)
{
  std::cout << "Linked List size: " << this->length << "\n";
}

void DoublyLinkedList::reverse(void)
{
  if (!this->head->next)
    return;

  Node *first = this->head;
  Node *second = first->next;

  while (second != nullptr)
  {
    Node *temp = second->next;

    second->next = first;
    second->prev = temp;

    first = second;
    second = temp;
  }

  this->head->next = nullptr;
  this->tail = this->head;
  this->head = first;
}

void DoublyLinkedList::displayLinkedList(void)
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
  DoublyLinkedList dll;

  dll.append("RECIFE");
  dll.append("SALVADOR");
  dll.append("CAMPINA");
  dll.displayLinkedList();

  dll.prepend("ARAXA");
  dll.displayLinkedList();

  dll.insertNode("RIO", 3);
  dll.displayLinkedList();
  dll.insertNode("PATOS", 0);
  dll.displayLinkedList();
  dll.insertNode("AREIAS", 6);
  dll.displayLinkedList();

  dll.deleteNode("RIO");
  dll.deleteNode("AREIAS");
  dll.displayLinkedList();

  dll.search("SALVADOR");
  dll.search("RIO");

  dll.reverse();
  dll.displayLinkedList();

  dll.getSize();

  return 0;
}
