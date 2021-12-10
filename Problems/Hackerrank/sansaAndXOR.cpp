/*********************************************************************************************/
/* Problem: Sansa and XOR (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Sansa has an array. She wants to find the value obtained by XOR-ing the contiguous subarrays,
  followed by XOR-ing the values thus obtained. Determine this value.

  > Example:
    arr = [3,4,5]
    3^4^5^(3^4)^(4^5)^(3^4^5) = 6

-- Inputs:
  - int arr[n]: an array of integers

--Outputs:
  - int: the result of calculations

--Reasoning:
  See the examples below:
    1. arr = [4,5,7,8]: 4^5^7^8^(4^5)^(5^7)^(7^8)^(4^5^7)^(5^7^8)^(4^5^7^8)
      arr[0]=4: appear 4 times in the calculation
      arr[1]=5: appear 6 times in the calculation
      arr[2]=7: appear 6 times in the calculation
      arr[3]=8: appear 4 times in the calculation

      When the array size is an even value, each element will be "XORed" an even amount of times.
      Perfoming a XOR operation in a given number an even number of times produces 0 as result,
      so for an even sized array, return 0.

    2. arr = [3,4,5]:   3^4^5^(3^4)^(4^5)^(3^4^5) = 6
      arr[0]=3: appear 3 times in the calculation
      arr[1]=4: appear 4 times in the calculation
      arr[2]=5: appear 5 times in the calculation

      When the array size is odd, every element at an even index (i.e. 0,2,4..) occurs an odd number
      of times and every element at an odd index occurs an even number times which, from the previous
      case, we know results in a 0. So the result will be obtained by "XORing" the elements at
      even indexes, i.e., return (arr[0]^arr[2]).


--Time complexity: O(N/2) => O(N), since we ignore constants.

--Space complexity: O(1), no additional space dependent on the input size is used.

*/

#include <iostream>
#include <vector>

int sansaXor(std::vector<int> arr)
{
  // when the number of values is even, return 0, since
  // performing a XOR operation in a number an even number
  // of times produces 0 as result:
  if (arr.size() % 2 == 0)
  {
    return 0;
  }

  // when the number of values is odd, every element at an even
  // index occurs an odd number of times and every element at an
  // odd index occurs an even number times which, from the previous
  // case, we know results in a 0:
  int res = arr.at(0);

  for (int i{2}; i < arr.size(); i += 2)
  {
    res ^= arr.at(i);
  }

  return res;
}

int main()
{
  std::vector<int> arr = {3, 4, 5};
  std::cout << sansaXor(arr) << "\n";

  arr = {4, 5, 7, 6};
  std::cout << sansaXor(arr) << "\n";

  arr = {98, 74, 12};
  std::cout << sansaXor(arr) << "\n";

  arr = {50, 13, 2};
  std::cout << sansaXor(arr) << "\n";

  return 0;
}
