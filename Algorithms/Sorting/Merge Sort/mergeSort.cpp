/****************************************************************/
/* Algorithm: Merge Sort  ********/
/****************************************************************/
/*
>> Definition:
    Merge sort use a Divide and Conquer strategy in which it repeatedly breaks down a list 
    into several sublists until each sublist consists of a single element and merging those 
    sublists in a manner that results into a sorted list.
>> Steps:
    1. Divide the unsorted list into n sublists, each containing one element (a list of one 
    element is considered sorted).
    2. Repeatedly merge sublists to produce new sorted sublists until there is only one 
    sublist remaining. This will be the sorted list.
>> Time complexity - O(n*log n)
>> Space complexity - O(n)
*/

#include <iostream>
#include <vector>
#include <cmath>

// function to create subarray:
std::vector<int> getSubArray(std::vector<int> origArr, int start, int end)
{
  if (start == end)
  {
    return origArr;
  }

  std::vector<int> subArray;

  for (int i = start; i < end; i++)
  {
    subArray.push_back(origArr.at(i));
  }

  return subArray;
}

std::vector<int> mergeArrays(std::vector<int> left, std::vector<int> right)
{
  int indexLeft = 0;
  int indexRight = 0;
  std::vector<int> mergedArray;

  //loop through all elements comparing each left and right pair:
  for (int count{0}; count < (left.size() + right.size()); count++)
  {
    //if left hasn't reached its end yet AND its value is less than right,
    //OR if right has reached its end, add left to mergedArray and incr. indexLeft:
    if (((indexLeft < left.size()) && (left[indexLeft] < right[indexRight])) || (indexRight >= right.size()))
    {
      mergedArray.push_back(left.at(indexLeft));
      indexLeft++;
    }
    //right is less than left OR left has reached its end, add right to
    //mergedArray and incr. indexRight:
    else if (indexRight < right.size())
    {
      mergedArray.push_back(right.at(indexRight));
      indexRight++;
    }
  }
  return mergedArray;
}

std::vector<int> mergeSort(std::vector<int> arr)
{
  //base case - we have reached the 1 element array, return it:
  if (arr.size() == 1)
  {
    return arr;
  }
  //position where the array is divided:
  int mid = (int)(std::round((float)arr.size() / 2.0));
  //left half goes from position 0 to mid-1:
  std::vector<int> left = getSubArray(arr, 0, mid);
  //right half goes from position mid to length-1:
  std::vector<int> right = getSubArray(arr, mid, arr.size());

  //recursively call mergeSort() to divide the array until it reaches
  //the base case from where it begins to compare and merge the elements
  //into the resulting array:
  return mergeArrays(mergeSort(left), mergeSort(right));
}

void displayArray(const std::vector<int> &arr)
{
  for (auto i{0}; i < arr.size(); i++)
  {
    std::cout << arr.at(i) << " ";
  }
  std::cout << "\n";
}

int main()
{
  std::vector<int> unsorted1{30, 20, 40, 10, 80, 50, 15};

  std::vector<int> sorted1 = mergeSort(unsorted1);
  displayArray(sorted1);

  std::vector<int> unsorted2{1, 35, 11, 0, -5, 98, 5};

  std::vector<int> sorted2 = mergeSort(unsorted2);
  displayArray(sorted2);

  return 0;
}