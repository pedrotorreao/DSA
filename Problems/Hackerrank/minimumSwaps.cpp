/******************************************************************************
Problem: Minimum Swaps 2 (HR)
*******************************************************************************/
/* 
-- Problem statement:
You are given an unordered array of consecutive integers, i.e. [1,2,3,4,..] 
containing no duplicates. Considering that you can swap any two elements, what
is the minimum number of swaps needed to get the original array ordered in 
ascending order?
-- Inputs: array of consecutive integers.
-- Outputs: min. num. of swaps needed to order array.
-- Constraints: 1 ≤ n ≤ 10^5, 1 ≤ array[i] ≤ n.
*/

#include <iostream>
#include <vector>

int minimumSwaps(std::vector<int> arr)
{
  int swapCount = 0;

  for (size_t i{0}; i < arr.size(); i++)
  { // Example for vec1 and i=0:
    if (arr.at(i) != i + 1)
    {                               // arr[0] != 1
      int temp = arr.at(i);         // temp = 7
      arr.at(i) = arr.at(temp - 1); // arr[0] = arr[7-1] = arr[6] = 6
      arr.at(temp - 1) = temp;      // arr[7-1] = arr[6] = 7

      swapCount++;
      i--;
    }
  }

  return swapCount;
}

int main()
{
  std::vector<int> vec1{7, 1, 3, 2, 4, 5, 6};
  std::cout << "\nMinimum Swaps for vec1: " << minimumSwaps(vec1);

  std::vector<int> vec2{4, 3, 1, 2};
  std::cout << "\nMinimum Swaps for vec1: " << minimumSwaps(vec2);

  return 0;
}

/*
-- Solution explanation:
In order to determine the number of swaps needed, we iterate through the array
and for each position we check if the element currently at the position we are
visiting is the correct one (if array[i]=i+1), remember that (1 ≤ array[i] ≤ n) 
while (0 ≤ i ≤ n-1). In case it is, we keep iterating and checking other positions 
until i=n-1. However, if the element occupying position array[i] is not the 
correct one (if array[i]!=i+1), we put the element currently at array[i] in its 
correct position (current=array[i]-1, array[current-1]=current) and put whatever 
element was occupying position array[current-1] back at array[i]. Then, we check 
againg for array[i] if q[i]=i+1 and if it's not, we repeat the swapping process 
until it is and we can the procceed to the next position.
*/