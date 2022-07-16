#include <iostream>
#include <list>
#include <string>
#include <utility>

template <typename T>
class HashTable {
private:
  // pointer to an array of lists made of [key,value] pairs
  std::list<std::pair<std::string, T>> *ht;
  int total_buckets; // number of buckets in the table

public:
  /**
   * @brief Construct a new Hash Table object with the size provided.
   *
   * @param num_of_buckets
   */
  HashTable(int num_of_buckets) {
    this->total_buckets = num_of_buckets;
    this->ht = new std::list<std::pair<std::string, T>>[this->total_buckets];
  }
  /**
   * @brief Destroy the Hash Table object.
   *
   */
  ~HashTable() {
    delete[] ht;
  }

  /**
   * @brief Get the hashcode related to the passed key.
   *
   * @param key
   * @param hashcode
   */
  void get_hash(const std::string &key, int &hashcode) {
    int N = key.size();

    for (int i{0}; i < N; ++i) {
      hashcode += (int(key.at(i)) * (i + 1));
    }

    hashcode %= this->total_buckets;
  }

  /**
   * @brief Insert a new [key:value] pair to the table.
   *
   * @param key
   * @param value
   */
  void set(const std::string &key, T value) {
    int bucket_id{0};

    get_hash(key, bucket_id);

    this->ht[bucket_id].push_back(std::make_pair(key, value));
  }

  /**
   * @brief Get the value related to a given key.
   *
   * @param key
   * @return T
   */
  T get(const std::string &key) {
    int bucket_id{0};

    get_hash(key, bucket_id);

    auto iter_list_start = this->ht[bucket_id].begin();
    auto iter_list_end = this->ht[bucket_id].end();

    while (iter_list_start != iter_list_end) {
      if (iter_list_start->first == key)
        break;

      ++iter_list_start;
    }

    if (iter_list_start != iter_list_end)
      return (iter_list_start->second);

    std::cout << "*** Key \"" << key << "\" does not exist ***";

    T err{};
    return err;
  }

  /**
   * @brief Remove an element based on the given key.
   *
   * @param key
   */
  void remove(const std::string &key) {
    int bucket_id{0};

    get_hash(key, bucket_id);

    auto iter_list_start = this->ht[bucket_id].begin();
    auto iter_list_end = this->ht[bucket_id].end();

    while (iter_list_start != iter_list_end) {
      if (iter_list_start->first == key)
        break;

      ++iter_list_start;
    }

    if (iter_list_start != iter_list_end) {
      this->ht[bucket_id].erase(iter_list_start);
      std::cout << "*** \"" << key << "\" has been removed ***\n";
      return;
    }

    std::cout << "*** Key \"" << key << "\" does not exist ***";
  }

  /**
   * @brief Checks whether the table is empty.
   *
   * @return true
   * @return false
   */
  bool is_empty(void) {
    bool empty{true};

    for (int i{0}; i < this->total_buckets; i++) {
      if (this->ht[i].size()) {
        empty = false;
        break;
      }
    }
    return empty;
  }

  /**
   * @brief Display hash table elements.
   *
   */
  void displayHashTable(void) {
    if (this->is_empty()) {
      std::cout << "** Table is empty **\n";
      return;
    }

    for (int i{0}; i < this->total_buckets; i++) {
      auto it_start = this->ht[i].begin();
      auto it_end = this->ht[i].end();

      while (it_start != it_end) {
        std::cout << "[" << it_start->first << ":" << it_start->second << "]";

        ++it_start;

        if (it_start != it_end)
          std::cout << " --> ";
      }
      std::cout << "\n";
    }
  }
};

int main() {
  std::cout << std::boolalpha;

  HashTable<std::string> ht(5);

  ht.displayHashTable();                                    // Empty --> error message
  std::cout << "Table is empty: " << ht.is_empty() << "\n"; // true

  ht.set("Karl", "Engineer");
  ht.set("Mike", "Doctor");
  ht.displayHashTable();
  std::cout << "Table is empty: " << ht.is_empty() << "\n"; // false

  ht.set("Luna", "Actress");
  ht.set("Paul", "Dentist");
  ht.displayHashTable();

  ht.set("Nicholas", "Student");
  ht.set("Georgia", "Mechanic");
  ht.displayHashTable();

  std::cout << "Value assigned to \"Luna\": " << ht.get("Luna") << "\n\n";

  ht.remove("Karl");
  ht.displayHashTable();

  std::cout << "Value assigned to \"Liam\": " << ht.get("Liam") << "\n\n";

  return 0;
}