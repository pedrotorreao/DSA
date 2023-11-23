"""
Given an array, find the length of the smallest subarray in it which when sorted will sort the whole array. (minimum window sort)

Example 1:
  Input: [1, 2, 5, 3, 7, 10, 9, 12]
  Output: 5
  Explanation: We need to sort only the subarray [5, 3, 7, 10, 9] to make the whole array sorted

Example 2:
  Input: [1, 3, 2, 0, -1, 7, 10]
  Output: 5
  Explanation: We need to sort only the subarray [1, 3, 2, 0, -1] to make the whole array sorted
"""
import sys

INTMAX = sys.maxsize
INTMIN = -1 * sys.maxsize


def findUnsortedSubarray(arr):
    low = 0
    high = len(arr) - 1

    while (low < len(arr) - 1) and (arr[low] <= arr[low + 1]):
        low += 1

    if low == len(arr) - 1:
        return 0

    while (high > 0) and (arr[high] >= arr[high - 1]):
        high -= 1

    subArrayMax = INTMIN
    subArrayMin = INTMAX

    for i in range(low, high + 1):
        subArrayMax = max(subArrayMax, arr[i])
        subArrayMin = min(subArrayMin, arr[i])

    while (low > 0) and (arr[low - 1] > subArrayMin):
        low -= 1

    while (high < len(arr) - 1) and (arr[high + 1] < subArrayMax):
        high += 1

    return high - low + 1


arr = [1, 2, 5, 3, 7, 10, 9, 12]
print(f"min. window sort for {arr}: {findUnsortedSubarray(arr)}")

arr = [1, 3, 2, 0, -1, 7, 10]
print(f"min. window sort for {arr}: {findUnsortedSubarray(arr)}")

arr = [1, 2, 3]
print(f"min. window sort for {arr}: {findUnsortedSubarray(arr)}")
