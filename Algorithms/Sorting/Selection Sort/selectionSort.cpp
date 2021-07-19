/****************************************************************/
/* Algorithm: Selection Sort  ********/
/****************************************************************/
/*
The selection sort algorithm sorts an array by repeatedly finding the minimum element (considering ascending order) 
from unsorted part and putting it at the beginning. The algorithm maintains two subarrays in a given array.
1) The subarray which is already sorted.
2) Remaining subarray which is unsorted.
In every iteration of selection sort, the minimum element (considering ascending order) from the unsorted subarray 
is picked and moved to the sorted subarray. 

Time complexity: O(n^2)
Space complexity: O(1)
*/

#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &arr)
{
  for (size_t i{0}; i < arr.size(); i++)
  {
    int min = i;
    for (size_t j{i + 1}; j < arr.size(); j++)
    {
      if (arr.at(j) < arr.at(min))
      {
        min = j;
      }
    }
    int temp = arr.at(min);
    arr.at(min) = arr.at(i);
    arr.at(i) = temp;
  }
}

int main()
{
  //TEST CASES:
  //1-:
  std::vector<int> testArray1{9, 85, -5, 10, 0, -17, 123, 3, 67};
  selectionSort(testArray1);
  for (auto i : testArray1)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";

  //2-:
  std::vector<int> testArray2{593, 12, 0, -45, 1, 45, 23, -435, -1};
  selectionSort(testArray2);
  for (auto i : testArray2)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";

  //3-:
  std::vector<int> testArray3{722, 345, 299, 122, 119, 90, 88, 51, 23, 1, 0, -1, -24, -121, -987};
  selectionSort(testArray3);
  for (auto i : testArray3)
  {
    std::cout << i << " ";
  }
  std::cout << "\n";

  return 0;
}