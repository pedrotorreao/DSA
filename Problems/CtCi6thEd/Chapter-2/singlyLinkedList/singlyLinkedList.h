#pragma once

class Node
{
public:
  int data;
  Node *next;

  Node(int d);
  ~Node();
};

class SinglyLinkedList
{
private:
  Node *head;
  Node *tail;
  int length;

public:
  void append(int d);
  void appendNode(Node *new_node);
  void prepend(int d);
  void display(void);
  void incLength(void);
  void decLength(void);
  void clearList(void);

  void feedList(int numOfNodes, int min, int max);
  Node *getH(void) const;
  int getLength(void);

  SinglyLinkedList();
  ~SinglyLinkedList();
};
