#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

template <typename T>
void displayVec(const std::vector<T> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}

void countingSortHelper(std::vector<int> &vec, const int &pos);

void radixSort(std::vector<int> &vec)
{
  int max = *std::max_element(vec.begin(), vec.end());

  for (int position{1}; (max / position) > 0; position = position * 10)
  {
    countingSortHelper(vec, position);
  }
}

int main()
{
  std::vector<int> v_1{152, 8, 530, 90, 88, 231, 11, 45, 677, 199};
  radixSort(v_1);
  displayVec<int>(v_1);

  std::vector<int> v_2{1075, 432, 22, 117, 5};
  radixSort(v_2);
  displayVec<int>(v_2);

  return 0;
}

void countingSortHelper(std::vector<int> &vec, const int &pos)
{
  const int k{10};

  std::vector<int> count(k, 0);

  for (int i{0}; i < vec.size(); ++i)
    ++count.at((vec.at(i) / pos) % 10);

  for (int i{1}; i < k; i++)
    count.at(i) = count.at(i) + count.at(i - 1);

  std::vector<int> sortedVec(vec.size(), 0);

  for (int i = vec.size() - 1; i >= 0; --i)
  {
    sortedVec.at(count.at((vec.at(i) / pos) % 10) - 1) = vec.at(i);
    --count.at((vec.at(i) / pos) % 10);
  }

  for (int i{0}; i < vec.size(); i++)
    vec.at(i) = sortedVec.at(i);
}