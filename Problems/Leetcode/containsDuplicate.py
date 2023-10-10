"""
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
"""


def contains_duplicate(arr):
    hs = set(arr)

    if len(hs) != len(arr):
        return True

    return False


nums = [1, 2, 3, 4]
hasDuplicate = contains_duplicate(nums)
print(f"{nums} has duplicate: {hasDuplicate}")

nums = [1, 2, 3, 1]
hasDuplicate = contains_duplicate(nums)
print(f"{nums} has duplicate: {hasDuplicate}")
