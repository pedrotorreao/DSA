/******************************************************************************
DS: Queue using Arrays
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

class Queue
{
private:
  std::string front;
  std::string back;
  std::vector<std::string> queue;

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
  this->front = "";
  this->back = "";
  this->queue = {};
}

Queue::~Queue()
{
}

void Queue::enqueue(std::string s)
{
  if ((s.size() > 0) && (s != " "))
  {
    this->queue.push_back(s);
    this->front = this->queue.at(0);                     // or queue.front()
    this->back = this->queue.at(this->queue.size() - 1); // queue.back()
    return;
  }
  throw std::invalid_argument("invalid argument!");
}

void Queue::dequeue(void)
{
  if (this->queue.size())
  {
    this->queue.erase(this->queue.begin(), this->queue.begin() + 1);

    this->front = this->queue.front(); // or queue.front()
    this->back = this->queue.back();   // queue.back()

    return;
  }

  throw std::length_error("queue is empty!");
}

std::string Queue::peek(void)
{
  if (this->queue.size())
  {
    return this->front;
  }
  throw std::length_error("queue is empty!");
}

bool Queue::isEmpty(void)
{
  return (this->queue.size() == 0);
}

int Queue::getLength(void)
{
  return this->queue.size();
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
  // std::cout << "queue top: " << queue.peek() << "\n"; //should throw exception
  std::cout << "queue size: " << queue.getLength() << "\n";       // should output 0
  std::cout << "The queue is empty: " << queue.isEmpty() << "\n"; // should output true
  std::cout << "---\n";

  // --test 7: enqueue invalid elements:
  // queue.enqueue(""); //should throw exception
  queue.enqueue(" "); //should throw exception

  return 0;
}