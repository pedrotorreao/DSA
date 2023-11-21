"""
Given an array of sorted numbers, move all non-duplicate number instances at the beginning of the array in-place. The relative order of the elements should be kept the same and you should not use any extra space so that the solution has constant space complexity i.e., O(1).

Move all the unique number instances at the beginning of the array and after moving return the length of the subarray that has no duplicate in it.
"""


def removeDuplicates(arr):
    if len(arr) == 0:
        return 0

    l_ptr = 0
    r_ptr = 0
    uniq_cnt = 1

    while r_ptr < len(arr):
        if arr[l_ptr] == arr[r_ptr]:
            r_ptr += 1
        else:
            uniq_cnt += 1
            l_ptr = r_ptr

    return uniq_cnt


arr = [2, 3, 3, 3, 6, 9, 9]
print(f"- unique values in {arr}: {removeDuplicates(arr)}")

arr = [2, 2, 2, 11]
print(f"- unique values in {arr}: {removeDuplicates(arr)}")

arr = [1, 3, 5, 7, 7, 9]
print(f"- unique values in {arr}: {removeDuplicates(arr)}")
