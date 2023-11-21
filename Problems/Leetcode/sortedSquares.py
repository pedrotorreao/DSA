"""
Given a sorted array, create a new array containing squares of all the numbers of the input array in the sorted order.

Example 1:
  Input: [-2, -1, 0, 2, 3]
  Output: [0, 1, 4, 4, 9]

Example 2:
  Input: [-3, -1, 0, 1, 2]
  Output: [0, 1, 1, 4, 9]

"""


def sortedSquares(arr):
    if len(arr) == 0:
        return arr

    l_ptr = 0
    r_ptr = len(arr) - 1
    i = len(arr) - 1

    ans = [None] * len(arr)

    while i >= 0:
        if abs(arr[l_ptr]) > abs(arr[r_ptr]):
            ans[i] = arr[l_ptr] * arr[l_ptr]
            l_ptr += 1
        else:
            ans[i] = arr[r_ptr] * arr[r_ptr]
            r_ptr -= 1
        i -= 1

    return ans


arr = [-2, -1, 0, 2, 3]
print(f"{arr} squared is: {sortedSquares(arr)}")

arr = [-3, -1, 0, 1, 2]
print(f"{arr} squared is: {sortedSquares(arr)}")

arr = [-12, -9, -8, -5, -3, 0, 1, 2]
print(f"{arr} squared is: {sortedSquares(arr)}")
