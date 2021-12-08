/****************************************************************/
/* Algorithm: Counting Sort  ********/
/****************************************************************/

#include <iostream>
#include <vector>

void displayVec(const std::vector<int> &vec);

std::vector<int> countingSort(const std::vector<int> &vec)
{
  // max. value in vec, range for vec[i]:
  int k{0};

  for (const auto &v : vec)
  {
    if (v > k)
      k = v;
  }

  // vector to store the freq. at which vec[i] appears in vec:
  std::vector<int> countElements(k + 1, 0);

  for (const auto &v : vec)
  {
    ++countElements.at(v);
  }

  // update 'countElements' so that each 'countElements[i]' account for the num. of elements less than it:
  for (int i{1}; i <= k; ++i)
  {
    countElements.at(i) = countElements.at(i) + countElements.at(i - 1);
  }

  std::vector<int> sortedVec(vec.size(), 0);

  // use 'countElements' to correctly place the elements of 'vec':
  for (int i = vec.size() - 1; i >= 0; --i)
  {
    sortedVec.at(countElements.at(vec.at(i)) - 1) = vec.at(i);
    --countElements.at(vec.at(i));
  }

  return sortedVec;
}

int main()
{
  std::vector<int> origArr{0, 3, 7, 1, 0, 6, 2, 9, 1};
  std::vector<int> sortedArr = countingSort(origArr);
  std::cout << "--Original Aray: ";
  displayVec(origArr);
  std::cout << "--Sorted Aray: ";
  displayVec(sortedArr);
  std::cout << "\n";

  origArr = {2, 1, 1, 0, 2, 5, 4, 0, 2, 8, 7, 7, 9, 2, 0, 1, 9};
  sortedArr = countingSort(origArr);
  std::cout << "--Original Aray: ";
  displayVec(origArr);
  std::cout << "--Sorted Aray: ";
  displayVec(sortedArr);
  std::cout << "\n";

  origArr = {0, 4, 1, 7, 5, 5, 6, 4, 3, 3, 4, 2, 1, 9, 8, 4, 6};
  sortedArr = countingSort(origArr);
  std::cout << "--Original Aray: ";
  displayVec(origArr);
  std::cout << "--Sorted Aray: ";
  displayVec(sortedArr);
  std::cout << "\n";

  origArr = {6, 1, 2, 1, 1, 5, 4, 3, 6, 9, 0, 2, 9, 2, 1, 1, 7};
  sortedArr = countingSort(origArr);
  std::cout << "--Original Aray: ";
  displayVec(origArr);
  std::cout << "--Sorted Aray: ";
  displayVec(sortedArr);
  std::cout << "\n";

  origArr = {0, 11, 1, 3, 2, 5, 5, 0, 3, 3, 1, 6, 9, 2, 7, 9, 3};
  sortedArr = countingSort(origArr);
  std::cout << "--Original Aray: ";
  displayVec(origArr);
  std::cout << "--Sorted Aray: ";
  displayVec(sortedArr);
  std::cout << "\n";

  return 0;
}

void displayVec(const std::vector<int> &vec)
{
  for (const auto &v : vec)
  {
    std::cout << v << "  ";
  }
  std::cout << "\n";
}