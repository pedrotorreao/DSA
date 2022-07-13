#include <cassert>
#include <iostream>
#include <string>

template <typename T>
class Node {
public:
  T data;
  Node<T> *next;
  Node<T> *prev;

  Node(T value) : data{value}, next{nullptr}, prev{nullptr} {}
  ~Node() = default;
};

template <typename T>
class DLL {
private:
  Node<T> *head;
  Node<T> *tail;
  int length;

public:
  /**
   * @brief Construct a new Singly Linked List object
   *
   */
  DLL() : head{nullptr}, tail{head}, length{0} {}
  /**
   * @brief Destroy the Singly Linked List object
   *
   */
  ~DLL() = default;

  /**
   * @brief Add a new node to the back of the list.
   *
   * @param value
   */
  void append(T value) {
    Node<T> *new_node = new Node<T>(value);

    if (this->head == nullptr) {
      this->head = new_node;
      this->tail = new_node;
    } else {
      this->tail->next = new_node;
      new_node->prev = this->tail;

      this->tail = new_node;
    }

    ++this->length;
  }
  /**
   * @brief Add a new node to the front of the list.
   *
   * @param value
   */
  void prepend(T value) {
    Node<T> *new_node = new Node<T>(value);

    if (this->head == nullptr) {
      this->head = new_node;
      this->tail = this->head;
    } else {
      new_node->next = this->head;
      this->head->prev = new_node;

      this->head = new_node;
    }

    ++this->length;
  }
  /**
   * @brief Add a new node at a given position.
   *
   * @param value
   * @param position
   */
  void insert(T value, int position) {
    if (this->head == nullptr || position <= 1) {
      this->prepend(value);
      return;
    }

    if (position >= this->length) {
      this->append(value);
      return;
    }

    Node<T> *new_node = new Node<T>(value);
    Node<T> *cur_node = this->head;
    int cur_position{1};

    while (cur_position < position - 1) {
      cur_node = cur_node->next;
      ++cur_position;
    }

    new_node->next = cur_node->next;
    new_node->prev = cur_node;

    cur_node->next = new_node;

    ++this->length;
  }
  /**
   * @brief Remove the 1st occurence of a node which has the given value.
   *
   * @param value
   */
  void remove_by_val(T value) {
    if (this->head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }

    if (this->head->data == value) {
      this->head = this->head->next;
      this->head->prev = nullptr;
      --this->length;

      return;
    }

    Node<T> *cur_node = this->head;

    while (cur_node->next != nullptr) {
      if (cur_node->next->data == value) {
        if (cur_node->next->next != nullptr) {
          cur_node->next->next->prev = nullptr;
          cur_node->next = cur_node->next->next;
        } else {
          cur_node->next = nullptr;
          this->tail = cur_node;
          break;
        }
      }
      cur_node = cur_node->next;
    }

    --this->length;
  }
  /**
   * @brief Remove node at given position.
   *
   * @param position
   */
  void remove_by_pos(int position) {
    if (this->head == nullptr) {
      std::cout << "List is empty\n";
      return;
    }

    if (position > this->length) {
      std::cout << "List only has " << this->get_length() << " nodes\n";
      return;
    }

    if (position <= 1) {
      std::cout << "Removing first node ...\n";

      this->head = this->head->next;
      this->head->prev = nullptr;
      --this->length;

      return;
    }

    Node<T> *cur_node = this->head;
    int cur_position{1};

    while (cur_position < position - 1) {
      cur_node = cur_node->next;
      ++cur_position;
    }

    if (cur_node->next->next)
      cur_node->next->next->prev = nullptr;
    cur_node->next = cur_node->next->next;

    if (cur_node->next == nullptr)
      this->tail = cur_node;

    --this->length;
  }

  /**
   * @brief Reverse SLL iteratively.
   *
   */

  void reverse_ite(void) {
    if (this->head == nullptr || this->head->next == nullptr)
      return;

    Node<T> *first = this->head;
    Node<T> *second = this->head->next;

    while (second) {
      Node<T> *temp = second->next;

      second->next = first;
      second->prev = temp;

      first = second;
      second = temp;
    }

    this->head->next = nullptr;
    this->tail = this->head;
    this->head = first;
  }
  /**
   * @brief Reverse SLL recursively.
   *
   */
  void reverse_rec(void) {
    this->head = reverse_rec_helper(this->head);
  }
  Node<T> *reverse_rec_helper(Node<T> *cur_head) {
    if (cur_head == nullptr || cur_head->next == nullptr)
      return cur_head;

    Node<T> *temp = reverse_rec_helper(cur_head->next);

    cur_head->next->next = cur_head;
    cur_head->prev = cur_head->next;
    cur_head->next = nullptr;

    this->tail = cur_head;

    return temp;
  }

  /**
   * @brief Get value stored in the first of the list.
   *
   * @return T
   */
  T front(void) {
    assert(this->head != nullptr);

    return this->head->data;
  }

  /**
   * @brief Get value stored in the back of the list.
   *
   * @return T
   */
  T back(void) {
    assert(this->head != nullptr);

    return this->tail->data;
  }
  /**
   * @brief Get the 1st occurence of a node which has the given value.
   *
   * @param value
   * @return Node*
   */
  Node<T> *get_node(T value) {
    if (this->head == nullptr) {
      std::cout << "List is empty\n";
      return nullptr;
    }

    Node<T> *cur_node = this->head;

    while (cur_node != nullptr) {
      if (cur_node->data == value) {
        return cur_node;
      }

      cur_node = cur_node->next;
    }

    return nullptr;
  }

  /**
   * @brief Get the number of occurences for a given value.
   *
   * @param value
   * @return int
   */
  int get_freq(T value) {
    if (this->head == nullptr) {
      return 0;
    }

    Node<T> *cur_node = this->head;
    int freq{0};

    while (cur_node != nullptr) {
      if (cur_node->data == value)
        ++freq;

      cur_node = cur_node->next;
    }

    return freq;
  }

  /**
   * @brief Return whether the list is empty or not.
   *
   * @param value
   * @return true
   * @return false
   */
  bool isEmpty() {
    return (this->head == nullptr);
  }

  /**
   * @brief Check if a given node value is present.
   *
   * @param value
   * @return true
   * @return false
   */
  bool hasNode(T value) {
    return (this->get_node(value) != nullptr);
  }

  /**
   * @brief Get the length of the list.
   *
   * @return int
   */
  int get_length(void) {
    return this->length;
  }

  /**
   * @brief Display the list elements.
   *
   */
  void displayList(void) {
    Node<T> *cur_node = this->head;

    while (cur_node != nullptr) {
      std::cout << cur_node->data;

      if (cur_node->next != nullptr)
        std::cout << "   ";

      cur_node = cur_node->next;
    }
    std::cout << "\n";
  }
};

int main() {
  std::cout << std::boolalpha;

  DLL<std::string> dll;

  dll.append("Brazil");   // Brazil
  dll.append("Marrocos"); // Brazil -> Marrocos
  dll.displayList();
  std::cout << "\n";

  dll.prepend("Ukraine"); // Ukraine -> Brazil -> Marrocos
  dll.append("Japan");    // Ukraine -> Brazil -> Marrocos -> Japan
  dll.displayList();
  std::cout << "\n";

  dll.insert("Ireland", 0); // Ireland -> Ukraine -> Brazil -> Marrocos -> Japan
  dll.insert("Turkey", 7);  // Ireland -> Ukraine -> Brazil -> Marrocos -> Japan -> Turkey
  dll.insert("Norway", 3);  // Ireland -> Ukraine -> Norway -> Brazil -> Marrocos -> Japan -> Turkey
  dll.displayList();
  std::cout << "\n";

  std::cout << "List length: " << dll.get_length() << "\n"; // 7
  std::cout << "\n";

  dll.remove_by_val("Brazil"); // Ireland -> Ukraine -> Norway -> Marrocos -> Japan -> Turkey
  dll.displayList();
  std::cout << "List length: " << dll.get_length() << "\n"; // 6
  std::cout << "\n";

  dll.remove_by_val("Ireland"); // Ukraine -> Norway -> Marrocos -> Japan -> Turkey
  dll.displayList();
  std::cout << "List length: " << dll.get_length() << "\n"; // 5
  dll.remove_by_val("Turkey");                              // Ukraine -> Norway -> Marrocos -> Japan
  dll.displayList();
  std::cout << "List length: " << dll.get_length() << "\n"; // 4
  std::cout << "\n";

  // quebrou aqui
  dll.remove_by_pos(5); // error message
  dll.remove_by_pos(4); // Ukraine -> Norway -> Marrocos
  dll.displayList();
  std::cout << "List length: " << dll.get_length() << "\n"; // 3
  dll.remove_by_pos(2);                                     // Ukraine -> Marrocos
  dll.displayList();
  std::cout << "List length: " << dll.get_length() << "\n"; // 2
  dll.remove_by_pos(0);                                     // Marrocos
  dll.displayList();
  std::cout << "List length: " << dll.get_length() << "\n"; // 1
  std::cout << "\n";

  dll.append("Sweden"); // Marrocos -> Sweden
  dll.append("Chile");  // Marrocos -> Sweden -> Chile
  dll.append("Panama"); // Marrocos -> Sweden -> Chile -> Panama
  dll.prepend("Laos");  // Laos -> Marrocos -> Sweden -> Chile -> Panama
  dll.displayList();
  std::cout << "List length: " << dll.get_length() << "\n"; // 5
  std::cout << "\n";

  dll.reverse_ite(); // Panama -> Chile -> Sweden -> Marrocos -> Laos
  dll.displayList();
  std::cout << "\n";

  dll.reverse_rec();
  dll.displayList(); // Laos -> Marrocos -> Sweden -> Chile -> Panama
  std::cout << "\n";

  Node<std::string> *node = dll.get_node("Chile");
  std::cout << "Found it? " << (node != nullptr) << "\n"; // TRUE
  node = dll.get_node("Colombia");
  std::cout << "Found it? " << (node != nullptr) << "\n"; // FALSE
  std::cout << "\n";

  std::cout << "Count: " << dll.get_freq("Brazil") << "\n"; // 0
  std::cout << "Count: " << dll.get_freq("Sweden") << "\n"; // 1
  dll.insert("Brazil", 3);
  std::cout << "Count: " << dll.get_freq("Brazil") << "\n"; // 1
  dll.prepend("Chile");
  std::cout << "Count: " << dll.get_freq("Chile") << "\n"; // 2
  dll.displayList();                                       // Chile -> Laos -> Marrocos -> Brazil -> Sweden -> Chile -> Panama
  std::cout << "\n";

  std::cout << "Front: " << dll.front() << "\n";
  std::cout << "Back: " << dll.back() << "\n";
  std::cout << "\n";

  std::cout << "List is empty? " << dll.isEmpty() << "\n";
  std::cout << "\"Denmark\" is present? " << dll.hasNode("Denmark") << "\n";

  return 0;
}