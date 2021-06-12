/******************************************************************************
Problem: Array - Swap Count (HR)
*******************************************************************************/
#include <iostream>
#include <vector>
#include <cmath>

void minimumBribes(std::vector<int> q)
{
  int swapCount = 0;
  int bribeCount = 0;

  for (size_t i{0}; i < q.size(); i++)
  {
    // check if there any element which exceeded the  bribe limit:
    //      num. of bribes = element currently in the pos.- original holder of that pos.
    bribeCount = q.at(i) - (i + 1);

    if (bribeCount > 2)
    {
      std::cout << "Too chaotic"
                << "\n";
      return;
    }

    // since elements can only bribe their way towards the front of the queue and each element
    // can only bribe the 2 elements in front of it, for the given elements A and B,
    // if B is imediately behind A in the queue, the most B can get in front of A without exceeding
    // the bribe limit is the original position of A minus 1, q[A]-1:
    // q = [ ..., Z, C, A, B, ...] -> [ ..., Z, C, B, A, ...] -> [ ..., Z, B, C, A, ...]
    // With this in mind and taking into account that (1 ≤ q[i] ≤ n) while (0 ≤ i ≤ n-1), for an
    // element originally at q[i], to discover how many times it was bribed we just need to count
    // the number of elements greater than it from its (original position - 1) to its current position:
    // -- from q[i]-1 (original position minus 1) - 1 (i is zero-based, while q[i] starts at 1): q[i]-2
    // -- to i: non-inclusive
    for (size_t j = fmax(q.at(i) - 2, 0); j < i; j++)
    {
      if (q.at(j) > q.at(i))
      {
        swapCount++;
      }
    }
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
