/****************************************************************/
/* Algorithm: Quick Sort  ********/
/****************************************************************/
/*
 >> Definition:
    Quicksort is a divide-and-conquer algorithm and it works by selecting
    a pivot element from the array and partitioning the other elements 
    into two sub-arrays, according to whether they are less than or greater 
    than the pivot. The partitioning is the key and most important step of this
    algorithm, making sure that all elements smaller than the pivot are at its left,
    and all elements greater than the pivot are at its right. The sub-arrays are 
    then sorted recursively. This can be done in-place, requiring small additional 
    amounts of memory to perform the sorting [Wikipedia].
>> Steps: 
    1. Choose an element to be the pivot
    2. Partition the array around the pivot
    3. Recursively apply 1. and 2. to the sub-arrays.
 >> Time complexity:
        - Worst case (rare) - O(n^2): pivot happens to be the largest/smallest
        element in the array.
        - Average - O(n*log n): pivot is an intermediary value.
        - Best - O(n*log n): In the most balanced case, each time we perform a 
        partition we divide the list into two nearly equal pieces. 
 >> Space complexity - Worst case: O(log n)

*/

#include <iostream>
#include <vector>

int partition(std::vector<int> &arr, int p, int q)
{
  int pivot = q; // index of the last element in the array
  int j = p;     // first element in the array
  int i = p - 1; //pivot position after the partitioning

  while (j <= q)
  {
    if (arr.at(j) <= arr.at(pivot))
    {
      ++i;
      int temp = arr.at(i);
      arr.at(i) = arr.at(j);
      arr.at(j) = temp;
    }
    ++j;
  }
  return i;
}

void quickSort(std::vector<int> &arr, int p, int q)
{
  //base case: if we've gone through all the array (or subarray for the recursive
  //calls), i.e., low position (p) have reached the high position (q), we're done.
  if (p < q)
  {
    //partition the array around the pivot (usually last element):
    int r = partition(arr, p, q); // r is the position of the pivot after the partitioning (pivot is put in the correct position)
    //recursively call quickSort() for subarray with elements smaller than pivot:
    quickSort(arr, p, r - 1);
    //recursively call quickSort() for subarray with elements greater than pivot:
    quickSort(arr, r + 1, q);
  }
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
  std::vector<int> arr1{3, 7, 8, 5, 2, 1, 5, 4};
  int p = 0;
  int q = arr1.size() - 1;

  quickSort(arr1, p, q);
  displayArray(arr1);

  std::vector<int> arr2{35, 79, -8, 53, 0, 91, -62, 4, 0};
  p = 0;
  q = arr2.size() - 1;

  quickSort(arr2, p, q);
  displayArray(arr2);

  return 0;
}