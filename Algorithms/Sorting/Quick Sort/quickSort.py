"""
Algorithm: Quick Sort
"""


def quicksort(array):
    if len(array) < 2:
        return array

    pivot = array[0]
    smaller = [num for num in array[1:] if num <= pivot]
    greater = [num for num in array[1:] if num > pivot]

    return quicksort(smaller) + [pivot] + quicksort(greater)


def main():
    array = [-9, 1, 8, -2, 87, 1, 0, 3, -2, 1]
    print(f"-original: {array}\n-sorted: {quicksort(array)}\n")

    array = [2, 1, 3, 4, 2, 1, 6, 4, 8, 1]
    print(f"-original: {array}\n-sorted: {quicksort(array)}\n")


main()
