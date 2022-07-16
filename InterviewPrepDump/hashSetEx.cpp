#include <iostream>
#include <list>
#include <string>
#include <utility>

class HashSet {
private:
  // pointer to an array of lists made of strings
  std::list<std::string> *hs;
  int total_buckets; // number of buckets in the table

public:
  /**
   * @brief Construct a new HashSet object with the size provided.
   *
   * @param num_of_buckets
   */
  HashSet(int num_of_buckets) {
    this->total_buckets = num_of_buckets;
    this->hs = new std::list<std::string>[this->total_buckets];
  }
  /**
   * @brief Destroy the HashSet object.
   *
   */
  ~HashSet() {
    delete[] hs;
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
   * @brief Insert a new [key] to the hashset.
   *
   * @param key
   */
  void insert(const std::string &key) {
    int bucket_id{0};

    get_hash(key, bucket_id);

    this->hs[bucket_id].push_back(key);
  }

  /**
   * @brief Checks whether a given key is in the hash set.
   *
   * @param key
   * @return true
   * @return false
   */
  bool contains(const std::string &key) {
    bool has_key{false};
    int bucket_id{0};

    get_hash(key, bucket_id);

    auto iter_list_start = this->hs[bucket_id].begin();
    auto iter_list_end = this->hs[bucket_id].end();

    while (iter_list_start != iter_list_end) {
      if (*iter_list_start == key) {
        has_key = true;
        break;
      }

      ++iter_list_start;
    }

    return has_key;
  }

  /**
   * @brief Remove a given from the hash set.
   *
   * @param key
   */
  void remove(const std::string &key) {
    int bucket_id{0};

    get_hash(key, bucket_id);

    auto iter_list_start = this->hs[bucket_id].begin();
    auto iter_list_end = this->hs[bucket_id].end();

    while (iter_list_start != iter_list_end) {
      if (*iter_list_start == key)
        break;

      ++iter_list_start;
    }

    if (iter_list_start != iter_list_end) {
      this->hs[bucket_id].erase(iter_list_start);
      std::cout << "*** \"" << key << "\" has been removed ***\n";
      return;
    }

    std::cout << "*** Key \"" << key << "\" does not exist ***";
  }

  /**
   * @brief Checks whether the hash set is empty.
   *
   * @return true
   * @return false
   */
  bool is_empty(void) {
    bool empty{true};

    for (int i{0}; i < this->total_buckets; i++) {
      if (this->hs[i].size()) {
        empty = false;
        break;
      }
    }
    return empty;
  }

  /**
   * @brief Display hash set elements.
   *
   */
  void displayHashSet(void) {
    if (this->is_empty()) {
      std::cout << "** Table is empty **\n";
      return;
    }

    for (int i{0}; i < this->total_buckets; i++) {
      auto it_start = this->hs[i].begin();
      auto it_end = this->hs[i].end();

      while (it_start != it_end) {
        std::cout << "[" << *it_start << "]";

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

  HashSet hs(5);

  hs.displayHashSet();                                      // Empty --> error message
  std::cout << "Table is empty: " << hs.is_empty() << "\n"; // true

  hs.insert("Karl");
  hs.insert("Mike");
  hs.displayHashSet();
  std::cout << "Table is empty: " << hs.is_empty() << "\n"; // false

  hs.insert("Luna");
  hs.insert("Paul");
  hs.displayHashSet();

  hs.insert("Nicholas");
  hs.insert("Georgia");
  hs.displayHashSet();

  std::cout << "\"Luna\" is in the hashset: " << hs.contains("Luna") << "\n\n";

  hs.remove("Karl");
  hs.displayHashSet();

  std::cout << "\"Liam\" is in the hashset: " << hs.contains("Liam") << "\n\n";

  return 0;
}