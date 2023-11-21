"""
Given an array of numbers and a target sum, find a pair in the array whose sum is equal to the given target. If no such pair exists return [-1, -1].

Write a function to return the indices of the two numbers (i.e. the pair) such that they add up to the given target.
"""


def twoSum(arr, target):
    map = dict()  # map[arr[i]] = i

    for i in range(0, len(arr)):
        # x + y = target --> y = target - x
        y = target - arr[i]
        if y in map:
            return [map[y], i]
        map[arr[i]] = i

    return [-1, -1]


arr = [1, 2, 3, 4, 6]
tgt = 6
print(twoSum(arr, tgt))

arr = [2, 5, 9, 11]
tgt = 11
print(twoSum(arr, tgt))

arr = [13, -8, 5, 1, 7]
tgt = 20
print(twoSum(arr, tgt))

arr = [13, -8, 5, 1, 7]
tgt = -1
print(twoSum(arr, tgt))

arr = [13, -8, 5, 1, 7]
tgt = 0
print(twoSum(arr, tgt))
