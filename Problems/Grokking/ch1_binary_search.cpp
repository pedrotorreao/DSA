/******************************************************************************
Grokking Algorithms - Chapter 1: Binary Search
*******************************************************************************/
#include <iostream>
#include <vector>

// approach #1: standard approach with no overflow check:
template<typename T>
int binary_search_1(std::vector<T> &vec, T val) {
  if (!vec.size()) return -1;

  int s_pos = 0, e_pos = vec.size()-1;

  while(s_pos <= e_pos){
    // this sum might cause an integer overlow if vec is too large:
    int m_pos = (e_pos + s_pos)/2;

    if(vec.at(m_pos) == val)
      return m_pos;
    else if(val > vec.at(m_pos))
      s_pos = m_pos + 1;
    else 
      e_pos = m_pos - 1;
  }

  return -1;
}

// approach #2: modified approach with overflow avoidance:
template<typename T>
int binary_search_2(std::vector<T> &vec, T val) {
  if (!vec.size()) return -1;

  int s_pos = 0, e_pos = vec.size()-1;

  while(s_pos <= e_pos){
    // prevent overflow by summing the difference:
    int m_pos = s_pos + ((e_pos - s_pos)/2);

    if(vec.at(m_pos) == val)
      return m_pos;
    else if(val > vec.at(m_pos))
      s_pos = m_pos + 1;
    else 
      e_pos = m_pos - 1;
  }

  return -1;
}

int main(){
  std::vector<int> vec{-21, -14, 0, 3, 7, 8, 36, 94, 125};
  int value{94};
  std::cout << "1. Value " << value << " is at index: " << binary_search_1<int>(vec, value) << "\n";
  std::cout << "2. Value " << value << " is at index: " << binary_search_2<int>(vec, value) << "\n";
  std::cout << "\n";

  value = -5;
  std::cout << "1. Value " << value << " is at index: " << binary_search_1<int>(vec, value) << "\n";
  std::cout << "2. Value " << value << " is at index: " << binary_search_2<int>(vec, value) << "\n";
  std::cout << "\n";

  value = -14;
  std::cout << "1. Value " << value << " is at index: " << binary_search_1<int>(vec, value) << "\n";
  std::cout << "2. Value " << value << " is at index: " << binary_search_2<int>(vec, value) << "\n";
  std::cout << "\n";

  value = 125;
  std::cout << "1. Value " << value << " is at index: " << binary_search_1<int>(vec, value) << "\n";
  std::cout << "2. Value " << value << " is at index: " << binary_search_2<int>(vec, value) << "\n";
  std::cout << "\n";

  value = 190;
  std::cout << "1. Value " << value << " is at index: " << binary_search_1<int>(vec, value) << "\n";
  std::cout << "2. Value " << value << " is at index: " << binary_search_2<int>(vec, value) << "\n";
  std::cout << "\n";

  return 0;
}