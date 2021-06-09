/******************************************************************************
Problem: Array - Running Median (HR)
*******************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<double> runningMedian(vector<int> a)
{
  vector<double> medians;
  // priority_queue:
  // template < class T, class Container = vector<T>,
  //            class Compare = less<typename Container::value_type>
  //          > class priority_queue;
  priority_queue<int, vector<int>, greater<int>> minheap;
  priority_queue<int> maxheap;

  double median = 0;

  for (size_t i{0}; i < a.size(); i++)
  {
    if (a.at(i) <= median)
    {
      // maxheap keeps elements <= median (lower half)
      // maxheap top is the largest element <= median:
      maxheap.push(a.at(i));
    }
    else
    {
      // minheap keeps elements > median (larger half)
      // minheap top is the smallest element > median:
      minheap.push(a.at(i));
    }

    // keep heaps balanced:
    if (minheap.size() > maxheap.size() + 1)
    {
      maxheap.push(minheap.top());
      minheap.pop();
    }
    // keep heaps balanced:
    if (maxheap.size() > minheap.size() + 1)
    {
      minheap.push(maxheap.top());
      maxheap.pop();
    }

    if (minheap.size() == maxheap.size())
    {
      // set contains an even number of elements:
      median = (maxheap.top() + minheap.top()) / 2.0;
    }
    else if (minheap.size() > maxheap.size())
    {
      // set contains an odd number of elements:
      median = (double)minheap.top();
    }
    else if (minheap.size() < maxheap.size())
    {
      // set contains an odd number of elements:
      median = (double)maxheap.top();
    }
    medians.push_back(median);
  }
  return medians;
}

int main()
{
  vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  vector<double> medians;

  medians = runningMedian(a);

  for (auto &i : medians)
    std::cout << i << " ";

  return 0;
}
