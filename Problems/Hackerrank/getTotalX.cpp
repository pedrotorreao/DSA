/*********************************************************************************************/
/* Problem: Between Two Sets (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  There will be two arrays of integers. Determine all integers that satisfy the following two
  conditions:
    1. The elements of the first array are all factors of the integer being considered
    2. The integer being considered is a factor of all elements of the second array
  These numbers are referred to as being between the two arrays. Determine how many such numbers
  exist.

  > Example:
    a = [2,6]
    b = [24,36]
      There are two numbers between the arrays: 6 and 12.
        6%2=0, 6%6=0, 12%2=0 and 12%6=0
        24%6=0, 36%6=0, 24%12=0, 36%12=0
  > Input - int a[n]: an array of integers

  > Output - int: the number of integers that are between the sets

  > Constraints:
      1<=n,m<=10
      1<=a[i],b[j]<=100

--Reasoning:
  First, we'll sort both arrays. After that, through the problem statement we know that, to satisfy
  both conditions, (1) the number must be divided evenly by all of the first array' elements, i.e.
  "number % a[i] == 0", and (2) the same number must divide evenly all the elements in the second array,
  so "b[i] % number == 0". The minimum condition needed to satisfy (1) is that the number must be greater
  than or equal to the largest number in the first array, 'a[]', 'max_a'. And, in order to at least
  qualify to to analyzed for requirement (2), this number must be less or equal to the smallest number
  in the second array, 'b[]', 'min_b'. Hence the need to begin by sorting the arrays. Since the number
  must be divisible by the largest element in 'a[]', we can use this value as the 'step' for the
  increments in the iteration, as an increment less than it will make the new number not evenly
  divisible by 'max_a'. Then, we iterate checking all the numbers from 'max_a' to 'min_b', if current
  number satisfy (1), it'll be mapped as '1', otherwise it'll be mapped as '-1'. The same goes for (2).
  In the end, we iterate over 'map' counting all the values mapped as '1', which we'll, then, return.

--Time complexity:
  O(N*A) or O(N*B), depending on which is the largest value between A and B, worst case in which max_a
  has the max. amount of elements and all of them are equal to 1 and max_b also has max. length
  with all elements being 100.

--Space complexity: O(A + B) for the hashmap.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

int getTotalX(std::vector<int> a, std::vector<int> b)
{
  std::unordered_map<int, int> map;
  int count{0};

  // sort arrays:
  std::sort(a.begin(), a.end());
  std::sort(b.begin(), b.end());

  int step = a.at(a.size() - 1);

  for (int inbtwn = step; inbtwn <= b.at(0); inbtwn += step)
  {
    for (int ia = 0; ((ia < a.size()) && (step % a.at(ia) == 0)); ia++)
    {
      if (((inbtwn % a.at(ia)) == 0) && (map[inbtwn] != -1))
      {
        map[inbtwn] = 1;
      }
      else
      {
        map[inbtwn] = -1;
      }
    }
    for (int ib = 0; ((ib < b.size()) && (b.at(ib) % step == 0)); ib++)
    {
      if (((b.at(ib) % inbtwn) == 0) && (map[inbtwn] != -1))
      {
        map[inbtwn] = 1;
      }
      else
      {
        map[inbtwn] = -1;
      }
    }
  }

  auto it = map.begin();

  while (it != map.end())
  {
    if (it->second == 1)
    {
      count++;
    }
    ++it;
  }

  return count;
}

int main()
{
  std::vector<int> vec_a{2, 4};
  std::vector<int> vec_b{16, 24, 32};

  std::cout << "Elements between two sets: " << getTotalX(vec_a, vec_b) << "\n";

  return 0;
}