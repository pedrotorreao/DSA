/****************************************************************/
/* Algorithm: Binary Search   ********/
/****************************************************************/
/*
>> Definition: 
  Search algorithm that finds the position of a target value within a sorted array by repeatedly 
  dividing the search interval in half. 
>> Steps:
    1 - Binary search compares the target value to the middle element of the array. 
    2 - If they are not equal, the half in which the target cannot lie is eliminated and the search 
    continues on the remaining half, again taking the middle element to compare to the target value, 
    and repeating this until the target value is found. 
    3 - If the search ends with the remaining half being empty, the target is not in the array. 
  Binary search runs in logarithmic time in the worst case, making O(log n) comparisons, where n is 
  the number of elements in the array. Binary search is faster than linear search except for small 
  arrays. However, the array must be SORTED first to be able to apply binary search.
>> Time complexity:O(log n)
>> Space complexity: O(1)
*/

#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int target, int startPos, int endPos)
{
  while (startPos <= endPos)
  {
    if (arr.at(startPos) == target)
      return startPos;
    if (arr.at(endPos) == target)
      return endPos;

    int midPos = (startPos + endPos) / 2;

    if (target > arr.at(midPos))
    {
      startPos = midPos + 1;
    }
    else
    {
      endPos = midPos;
    }
  }
  return -1;
}

int main()
{
  std::vector<int> arr{11, 23, 30, 45, 51, 62, 70, 89, 95, 100, 110};

  // TEST CASES:
  // case 1 - START = END and TARGET is on the array:
  std::cout << "Pos. of 45: " << binarySearch(arr, 45, 0, arr.size() - 1) << "\n";

  // case 2 - START = END and TARGET is NOT on the array:
  std::cout << "Pos. of 12: " << binarySearch(arr, 12, 0, 0) << "\n";

  // case 3.1 - START = 1st position and END = last position. Short search, mid value is target:
  std::cout << "Pos. of 62: " << binarySearch(arr, 62, 0, arr.size() - 1) << "\n";

  // case 3.2 - START = 1st position and END = last position. Longest search, target is 1st or last elements:
  std::cout << "Pos. of 11: " << binarySearch(arr, 11, 0, arr.size() - 1) << "\n";
  std::cout << "Pos. of 110: " << binarySearch(arr, 110, 0, arr.size() - 1) << "\n";

  // case 4 - START > END: Not a valid search:
  std::cout << "Pos. of 89: " << binarySearch(arr, 89, 3, 1) << "\n";
}