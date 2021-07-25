/******************************************************************************
Algorithm: QuickSort 
*******************************************************************************/
#include <iostream>
#include <vector>

// forward declarations for helper functions: std::vector<int>::iterator
std::vector<int> smallerThanPivot(std::vector<int> &, std::vector<int>::iterator &);
std::vector<int> greaterThanPivot(std::vector<int> &, std::vector<int>::iterator &);
std::vector<int> joinPartitions(std::vector<int>, std::vector<int>::iterator &, std::vector<int>);
void displayVec(std::vector<int> &v);

// quickSort algorithm:
std::vector<int> quickSort(std::vector<int> vec)
{
  // base case:
  // - array w/ 0 or 1 elements are considered ordered, return it:
  if (vec.size() < 2)
  {
    return vec;
  }
  // choose pivot as the first element:
  auto pivot = vec.begin();
  // partitioning:
  // - elements smaller than or equal to pivot:
  std::vector<int> smaller = smallerThanPivot(vec, pivot);
  // - elements greater than pivot:
  std::vector<int> greater = greaterThanPivot(vec, pivot);
  // recursively call quickSort on the partitions and once
  // we get to the base case for each partitions, join them
  // and return:
  return joinPartitions(quickSort(smaller), pivot, quickSort(greater));
}

int main()
{
  std::vector<int> vec{1, 3, 5, 2, 1, 4};
  std::vector<int> sorted = quickSort(vec);
  displayVec(sorted);

  vec = {-9, 1, 8, -2, 87, 1, 0, 3, -2, 1};
  sorted = quickSort(vec);
  displayVec(sorted);

  vec = {2, 1, 3, 4, 2, 1, 6, 4, 8, 1};
  sorted = quickSort(vec);
  displayVec(sorted);

  return 0;
}

// function definitions:
std::vector<int> smallerThanPivot(std::vector<int> &vec, std::vector<int>::iterator &p)
{
  std::vector<int> res{};
  auto elIter = vec.begin();

  while (elIter != vec.end())
  {
    if (*elIter <= *p && elIter != p)
    {
      res.push_back(*elIter);
    }
    ++elIter;
  }
  return res;
}

std::vector<int> greaterThanPivot(std::vector<int> &vec, std::vector<int>::iterator &p)
{
  std::vector<int> res{};
  auto elIter = vec.begin();

  while (elIter != vec.end())
  {
    if (*elIter > *p && elIter != p)
    {
      res.push_back(*elIter);
    }
    ++elIter;
  }
  return res;
}

std::vector<int> joinPartitions(std::vector<int> smaller, std::vector<int>::iterator &pivot, std::vector<int> greater)
{
  std::vector<int> res;

  res.insert(res.begin(), smaller.begin(), smaller.end());
  res.push_back(*pivot);
  res.insert(res.end(), greater.begin(), greater.end());

  return res;
}

void displayVec(std::vector<int> &v)
{
  auto it = v.begin();
  while (it != v.end())
  {
    std::cout << *it << " ";
    ++it;
  }
  std::cout << "\n";
}
