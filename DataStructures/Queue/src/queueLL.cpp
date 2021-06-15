/******************************************************************************
DS: Queue using Singly Linked List (SLL)
*******************************************************************************/

#include <iostream>
#include <string>
#include <stdexcept>

class QueueItem
{
public:
  std::string data;
  QueueItem *next;

  QueueItem(std::string d)
  {
    this->data = d;
    this->next = nullptr;
  }
  ~QueueItem() {}
};

class Queue
{
private:
  QueueItem *front;
  QueueItem *back;
  int length;

public:
  void enqueue(std::string s);
  void dequeue(void);
  std::string peek(void);
  bool isEmpty(void);
  int getLength(void);
  Queue();
  ~Queue();
};

Queue::Queue()
{
  this->front = nullptr;
  this->back = nullptr;
  this->length = 0;
}

Queue::~Queue()
{
}

void Queue::enqueue(std::string s)
{
  if ((s.size() > 0) && (s != " "))
  {
    QueueItem *new_item = new QueueItem(s);

    if (this->front == nullptr)
    {
      this->front = new_item;
      this->back = new_item;
    }
    else
    {
      this->back->next = new_item;
      this->back = new_item;
    }
    ++this->length;
    return;
  }
  throw std::invalid_argument("invalid argument!");
}

void Queue::dequeue(void)
{
  if (this->front != nullptr)
  {
    this->front = this->front->next;

    if (this->front != nullptr)
    {
      this->back = this->front;
    }
    --this->length;
    return;
  }

  throw std::length_error("queue is empty!");
}

std::string Queue::peek(void)
{
  if (this->front != nullptr)
  {
    return this->front->data;
  }
  throw std::length_error("queue is empty!");
}

bool Queue::isEmpty(void)
{
  return (this->front == nullptr);
}

int Queue::getLength(void)
{
  return this->length;
}

int main()
{

  std::cout.setf(std::ios::boolalpha);

  Queue queue;

  // --test 1: try to dequeue from empty queue:
  // queue.dequeue(); //should throw exception

  // add elements:
  queue.enqueue("Pedro");
  queue.enqueue("Carol");
  queue.enqueue("Leticia");
  queue.enqueue("Lucimar");
  queue.enqueue("Carlucio");

  // --test 2: get top element:
  std::cout << "queue top: " << queue.peek() << "\n"; //should output "study session"
  std::cout << "---\n";

  // --test 3: get queue size:
  std::cout << "queue size: " << queue.getLength() << "\n"; // should output 4
  std::cout << "---\n";

  // --test 4: dequeue top element:
  queue.dequeue();
  std::cout << "queue top: " << queue.peek() << "\n";       //should output "shower"
  std::cout << "queue size: " << queue.getLength() << "\n"; // should output 3
  std::cout << "---\n";

  // --test 5: check if queue is empty:
  std::cout << "The queue is empty: " << queue.isEmpty() << "\n"; // should output false
  std::cout << "---\n";

  // --test 6: dequeue all elements:
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  queue.dequeue();
  // std::cout << "queue top: " << queue.peek() << "\n";             //should throw exception
  std::cout << "queue size: " << queue.getLength() << "\n";       // should output 0
  std::cout << "The queue is empty: " << queue.isEmpty() << "\n"; // should output true
  std::cout << "---\n";

  // --test 7: enqueue invalid elements:
  // queue.enqueue("");   //should throw exception
  queue.enqueue(" "); //should throw exception

  return 0;
}