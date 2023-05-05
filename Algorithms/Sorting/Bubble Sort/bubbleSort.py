def bubble_sort(nums):
    n = len(nums)
    swapping = True

    while swapping:
        swapping = False
        for i in range(1, n):
            # swap elements if they are out of order:
            if nums[i - 1] > nums[i]:
                nums[i], nums[i - 1] = nums[i - 1], nums[i]
                swapping = True

    return nums


def main():
    nums = [3, 19, 2, 0, -12, 56, 21, 43, 1]
    print(f"original array: {nums}\n")
    bubble_sort(nums)
    print(f"sorted array: {nums}\n\n")


main()
