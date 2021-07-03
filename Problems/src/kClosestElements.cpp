/****************************************************************/
/* Problem: k Closest Elements (LC) ********/
/****************************************************************/
/*
-- Summary:
Given a sorted integer array arr, two integers k and x, return the k closest 
integers to x in the array. The result should also be sorted in ascending order.

An integer a is closer to x than an integer b if:
  |a - x| < |b - x|, or
  |a - x| == |b - x| and a < b

-- Input(s):
arr: sorted array
x: target value
k: number of elements closest to x to be selected
-- Expected output(s):
res: sorted array containing the k closest elements
-- Constraints:
  * 1 <= k <= arr.length
  * 1 <= arr.length <= 104
  * arr is sorted in ascending order.
  * -104 <= arr[i], x <= 104

-- Example:
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]

Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
*/

#include <iostream>
#include <vector>

// this is a standard binary search
int findPosition(std::vector<int> &arr, int target)
{
  int start = 0;
  int end = arr.size() - 1;

  // while the two "pointers" don't meet, keep looking for target:
  while (start <= end)
  {
    int mid = (start + end) / 2;

    // if target is found, return its position:
    if (arr[mid] == target)
    {
      return mid;
    }
    // if value at position mid is higher than our target,
    // look for target in the array part to the left of mid:
    if (arr[mid] > target)
    {
      end = mid - 1;
    }
    // else if value at position mid is less than our target,
    // look for target in the array part to the right of mid:
    else
    {
      start = mid + 1;
    }
  }
  // target value is not present in the array, which means that
  // it is less than the lowest array element (end --> start) or
  // target is higher than the highest array element (start --> end),
  // either way start = end, return it:
  return start;
}

std::vector<int> findClosestKElements(std::vector<int> &arr, int k, int x)
{
  // find the position where x would fit in the sorted array in case we
  // wanted to insert x to arr:
  int pos = findPosition(arr, x); // O(log n)
  std::cout << "pos. to add x: " << pos << "\n";

  int left = pos - 1; // position to the left
  int right = pos;    // position to the right

  std::vector<int> res; // result array

  while (k-- > 0)
  {
    // left < 0:
    //    we've reached the beginning of the array, there are no more elements to the left,
    //    so choose one to the right;
    // right < arr.size():
    //    we've not reached the end of the array, so we're free to keep going to the right;
    // (abs(arr[left] - x) > abs(arr[right] - x)):
    //    rule "an integer a (arr[left]) is closer to x than an integer b (arr[right]) if
    //    |a - x| < |b - x|, or |a - x| == |b - x| and a < b.
    //    so, in this case, if |arr[left] - x| > |arr[right] - x|, add an element to the right.
    if (left < 0 || (right < arr.size() && (abs(arr[left] - x) > abs(arr[right] - x))))
    {
      right++;
    }
    else
    {
      left--;
    }
  }

  left++;
  while (left < right) // right-left = k
  {
    res.push_back(arr[left]);
    left++;
  }

  return res;
}

void displayArray(std::vector<int> &arr)
{
  for (size_t i{0}; i < arr.size(); i++)
  {
    std::cout << arr[i] << " ";
  }

  std::cout << "\n";
}

int main()
{
  std::vector<int> arr1{1, 2, 3, 4, 5};
  int k = 4, x = 3;

  std::vector<int> kClosest = findClosestKElements(arr1, k, x); // expected: 1 2 3 4

  displayArray(kClosest);

  std::vector<int> arr2{10, 12, 15, 17, 18, 20, 25};
  x = 16;
  k = 4;
  kClosest = findClosestKElements(arr2, k, x); // expected: 12 15 17 18

  displayArray(kClosest);

  return 0;
}