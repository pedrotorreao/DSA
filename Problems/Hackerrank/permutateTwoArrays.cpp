/*********************************************************************************************/
/* Problem: Flipping Matrix (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  There are two n-element arrays of integers, A and B. Permute them into some A' and B' such
  that the relation (A'[i] + B'[i] >= k) holds for all i where 0 <= i < n. There will be queries
  consisting of A, B, and k. For each query, return YES if some permutation A', B' satisfying
  the relation exists. Otherwise, return NO.
  > Example:
    A = [0,1]     B = [0,2]     k = 1
    A valid A', B' is A' = [1,0] and B' = [0,2]. Return 'YES'.

  > Input: two arrays of integers, A[] and B[].

  > Output: string either YES or NO

  > Constraints:
      1 <= n <= 1000
      0 <= matrix[i][j] <= 4096, where 0 <= i,j < 2*n

--Reasoning:
  Sort one of the input arrays in ascending order and the other in descending order. After that,
  iterate over the sorted arrays combining A[i] and B[i] and comparing with k. If all A[i]+B[i] >= k,
  the arrays satisfy the permutation' conditions, return 'YES'; otherwise, return 'NO'.

--Time complexity: O(n*log(n)) due to the sortings, where n is the size of the arrays.

--Space complexity: O(1), no additional space dependent on the input size is needed.

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string twoArrays(int k, std::vector<int> A, std::vector<int> B)
{
  // get arrays size (n):
  int n = A.size();
  // sort array A in ascending order:
  std::sort(A.begin(), A.end());
  // sort array B in descending order:
  std::sort(B.begin(), B.end(), std::greater<int>());
  // iterate over the input arrays summing their values at each position
  // and comparing with k:
  for (int i{0}; i < n; i++)
  {
    if ((A.at(i) + B.at(i)) < k)
    {
      return "NO";
    }
  }
  return "YES";
}

int main()
{
  std::vector<int> vec_A{2, 1, 3};
  std::vector<int> vec_B{7, 8, 9};
  int k{10};

  std::cout << "Permutation' conditions satisfied: " << twoArrays(k, vec_A, vec_B) << "\n"; // Expected: 'YES'

  vec_A = {1, 2, 2, 1};
  vec_B = {3, 3, 3, 4};
  k = 5;

  std::cout << "Permutation' conditions satisfied: " << twoArrays(k, vec_A, vec_B) << "\n"; // Expected: 'NO'

  vec_A = {0, 1};
  vec_B = {0, 2};
  k = 1;

  std::cout << "Permutation' conditions satisfied: " << twoArrays(k, vec_A, vec_B) << "\n"; // Expected: 'YES'

  return 0;
}