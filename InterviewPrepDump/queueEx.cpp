#include <iostream>
#include <string>
#include <vector>

template <typename T>
class QueueItem {
public:
  T data;
  QueueItem<T> *next;

  QueueItem(T value) : data{value}, next{nullptr} {}
  ~QueueItem() = default;
};

template <typename T>
class Queue {
private:
  QueueItem<T> *front;
  QueueItem<T> *back;
  int length;

public:
  /**
   * @brief Construct a new Queue object
   *
   */
  Queue() : front{nullptr}, back{nullptr}, length{0} {}
  /**
   * @brief Destroy the Queue object
   *
   */
  ~Queue() = default;

  /**
   * @brief Add a new element to the back of the queue.
   *
   * @param value
   */
  void enqueue(T value) {
    QueueItem<T> *new_element = new QueueItem<T>(value);

    if (this->front == nullptr) {
      this->front = new_element;
      this->back = this->front;
    } else {
      this->back->next = new_element;
      this->back = this->back->next;
    }

    ++this->length;
  }

  /**
   * @brief Remove front element from the queue.
   *
   */
  void dequeue(void) {
    if (this->front == nullptr || this->length == 0) {
      std::cout << "** Queue is empty **\n";
      return;
    }

    this->front = this->front->next;
    --this->length;
  }

  /**
   * @brief Get the front element of the queue.
   *
   * @return T
   */
  T get_front(void) {
    if (this->front == nullptr || this->length == 0) {
      T err{};
      std::cout << "** Queue is empty **\n";
      return err;
    }

    return (this->front->data);
  }

  /**
   * @brief Get the length of the queue.
   *
   * @return int
   */
  int get_length(void) {
    return this->length;
  }

  /**
   * @brief Checks whether the queue is empty.
   *
   * @return true
   * @return false
   */
  bool is_empty(void) {
    return (this->length == 0);
  }
};

int main() {
  std::cout << std::boolalpha;

  Queue<std::string> q;

  q.get_front();
  std::cout << "\n";

  q.enqueue("James");
  q.enqueue("Naima");
  q.enqueue("Victor");

  std::cout << "Front: " << q.get_front() << "\n";
  std::cout << "Length: " << q.get_length() << "\n";
  std::cout << "\n";

  q.dequeue();

  std::cout << "Front: " << q.get_front() << "\n";
  std::cout << "Length: " << q.get_length() << "\n";
  std::cout << "\n";

  q.dequeue();
  q.dequeue();

  std::cout << "Front: " << q.get_front() << "\n";
  std::cout << "Length: " << q.get_length() << "\n";
  std::cout << "\n";

  q.dequeue();
  std::cout << "Length: " << q.get_length() << "\n";
  std::cout << "\n";

  return 0;
}
