/****************************************************************/
/* Algorithm: Heap Sort - Increasing order (Min heap)  ********/
/****************************************************************/

#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

template <typename T>
std::vector<T> heapSort(const std::vector<T> &arr)
{
  std::priority_queue<T, std::vector<T>, std::greater<T>> minHeap(arr.begin(), arr.end());

  std::vector<T> res;
  while (!minHeap.empty())
  {
    res.push_back(minHeap.top());

    minHeap.pop();
  }

  return res;
}

template <typename T>
void displayVec(const std::vector<T> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}

int main()
{
  std::vector<int> v_1{32, 5, 73, 9, -3, 28, 0};
  displayVec<int>(heapSort<int>(v_1));

  std::vector<double> v_2{32.5, 45.1, 9.21, 32.3, 8.33, 0.76};
  displayVec<double>(heapSort<double>(v_2));

  std::vector<char> v_3{'g', 'q', 'z', 'l', 'a', 'x'};
  displayVec<char>(heapSort<char>(v_3));

  std::vector<std::string> v_4{"Zanzibar", "Brazil", "Paraguai", "Nicaragua", "Australia"};
  displayVec<std::string>(heapSort<std::string>(v_4));

  return 0;
}
