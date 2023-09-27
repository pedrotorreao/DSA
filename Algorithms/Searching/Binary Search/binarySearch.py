def binarySearch(arr, val):
    l_ptr = 0
    r_ptr = len(arr) - 1

    while l_ptr <= r_ptr:
        m_ptr = (r_ptr + l_ptr) // 2

        m_val = arr[m_ptr]

        if m_val < val:
            l_ptr = m_ptr + 1
        elif m_val > val:
            r_ptr = m_ptr - 1
        else:
            print(f"-- value {val} found at position arr[{m_ptr}]\n")
            return m_ptr

    print(f"-- value {val} NOT FOUND\n")
    return -1


numbers_1 = [-2345, -1523, -634, -3, 23, 65, 8976, 20459]
numbers_2 = [-1345, -123, -32, -15, 0, 4]

search_res_1 = binarySearch(numbers_1, 8976)
search_res_1 = binarySearch(numbers_1, -3)
search_res_1 = binarySearch(numbers_1, 0)

search_res_2 = binarySearch(numbers_2, -15)
search_res_2 = binarySearch(numbers_2, 8)
search_res_2 = binarySearch(numbers_2, -1345)
