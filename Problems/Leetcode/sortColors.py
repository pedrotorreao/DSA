"""
Given an array containing 0s, 1s and 2s, sort the array in-place. You should treat numbers of the array as objects, hence, we can’t count 0s, 1s, and 2s to recreate the array.

The flag of the Netherlands consists of three colors: red, white and blue; and since our input array also consists of three different numbers that is why it is called Dutch National Flag problem.

Example 1:
  Input: [1, 0, 2, 1, 0]
  Output: [0 0 1 1 2]

Example 2:
  Input: [2, 2, 0, 1, 2, 0]
  Output: [0 0 1 2 2 2 ]

"""


def sortColors(colors):
    l_ptr = 0
    m_ptr = 0
    r_ptr = len(colors) - 1

    while m_ptr <= r_ptr:
        curr_color = colors[m_ptr]
        match curr_color:
            case 0:  # RED
                colors[l_ptr], colors[m_ptr] = colors[m_ptr], colors[l_ptr]
                l_ptr += 1
                m_ptr += 1
            case 2:  # BLUE
                colors[r_ptr], colors[m_ptr] = colors[m_ptr], colors[r_ptr]
                r_ptr -= 1
            case _:  # WHITE
                m_ptr += 1

    return colors


colors = [1, 0, 2, 1, 0]
print(f"colors {colors} sorted: {sortColors(colors)}")

colors = [2, 2, 0, 1, 2, 0]
print(f"colors {colors} sorted: {sortColors(colors)}")
