/******************************************************************************
Problem: Array - Minimum Bribes (HR)
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>

void minimumBribes(std::vector<int> q)
{
  const int bribeLimit = 2;
  int swapCount = 0;
  int bribeCount = 0;
  // optimization - flag to check if any swaps were made:
  // -- if true: it's still unordered, keep the loop running
  // -- if false: it's already sorted, no need to keep checking, break out:
  bool swapped = false;

  // check if there any element which exceeded the  bribe limit:
  // num. of bribes = element currently in the pos.- original holder of that pos.
  for (size_t i{0}; i < q.size(); i++)
  {
    bribeCount = q.at(i) - (i + 1);

    // in case bribe limit was exceeded:
    if (bribeCount > bribeLimit)
    {
      std::cout << "Too chaotic"
                << "\n";
      return;
    }
  }

  // perform a bubble sort and check how many swaps were done by sorting
  // the array and counting how many swaps were needed to sort it:
  for (size_t i{0}; i < q.size(); i++)
  {
    for (size_t j{0}; j < q.size() - i - 1; j++)
    {
      if (q.at(j) > q.at(j + 1))
      {
        int temp = q.at(j);
        q.at(j) = q.at(j + 1);
        q.at(j + 1) = temp;
        swapCount++;
        swapped = true;
      }
    }

    if (swapped == false)
      break;
    swapped = true;
  }
  std::cout << swapCount << "\n";
}

int main()
{
  std::vector<int> q1{2, 1, 5, 3, 4};
  std::vector<int> q2{5, 1, 2, 3, 7, 8, 6, 4};
  std::vector<int> q3{1, 2, 5, 3, 7, 8, 6, 4};

  minimumBribes(q1);
  std::cout << "-----"
            << "\n";
  minimumBribes(q2);
  std::cout << "-----"
            << "\n";
  minimumBribes(q3);

  return 0;
}
