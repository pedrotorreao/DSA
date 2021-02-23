/************************************************************/
/*Problem: Rotate Array (HR)  ********/
/************************************************************/
/*
-- Summary:
  A left rotation operation on an array shifts each of the array's elements 1 unit to the left. 
  For example, if 2 left rotations are performed on array [1,2,3,4,5], then the array would 
  become [3,4,5,1,2]. Note that the lowest index item moves to the highest index in a rotation. 
  This is called a circular array. Given an array 'a' of integers and a number, d, perform d left 
  rotations on the array. Return the updated array to be printed as a single line of space-separated 
  integers.
-- Input(s): 
    a: array containing n integers
    d: the number of rotations 
-- Expected output(s):
    a': rotated array  
-- Constraints:
    (1 ≤ n ≤ 10^6), (1 ≤ d ≤ n), (1 ≤ a[i] ≤ 10^6)
*/

#include <iostream>
#include <vector>
#include <algorithm>

void rotLeft(std::vector<int> a, int d)
{
    if (a.size() == d)
    {
        return;
    }

    std::rotate(a.begin(), a.begin() + d, a.end());

    for (auto i : a)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> a1{1, 2, 3, 4, 5};
    std::vector<int> a2{0, 0, 0, 0, 1};
    int d1{4};
    int d2{3};

    rotLeft(a1, d1);
    rotLeft(a2, d2);

    return 0;
}