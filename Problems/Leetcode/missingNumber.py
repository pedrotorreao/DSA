"""
We are given an array containing n distinct numbers taken from the range 0 to n. Since the 
array has only n numbers out of the total n+1 numbers, find the missing number.

Example 1:
  Input: [4, 0, 3, 1]
  Output: 2

Example 2:
  Input: [8, 3, 5, 2, 4, 6, 0, 1]
  Output: 7

"""


def missing_number(nums):
    N, i, missing = len(nums), 0, -1

    # cyclic sort:
    while i < N:
        right_idx = nums[i]
        if (right_idx < N) and (nums[i] != nums[right_idx]):
            nums[i], nums[right_idx] = nums[right_idx], nums[i]
            continue
        i += 1

    # find the missing value:
    for i in range(0, N):
        if nums[i] != i:
            missing = i
            break

    return missing


nums = [4, 0, 3, 1]
print(f"--> missing number in {nums}: {missing_number(nums)}")

nums = [8, 3, 5, 2, 4, 6, 0, 1]
print(f"--> missing number in {nums}: {missing_number(nums)}")
