def bubble_sort_traditional(nums):
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

def bubble_sort_improved(nums):
	n = len(nums)
	while n > 1:
		newn = 0
		for i in range(1, n):
			if nums[i-1] > nums[i]:
				nums[i], nums[i-1] = nums[i-1], nums[i]
				newn = i
		n = newn
	
	return nums

def main():
    nums = [3, 19, 2, 0, -12, 56, 21, 43, 1]
    print(f"original array: {nums}\n")
    bubble_sort_traditional(nums)
    print(f"sorted array: {nums}\n\n")

    nums = [91,23,9,-3,6,-23,12,45]
    print(f"original array: {nums}\n")
    bubble_sort_traditional(nums)
    print(f"sorted array: {nums}\n\n")


main()
