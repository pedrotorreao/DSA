/*********************************************************************************************/
/* Problem: K-th Symbol in Grammar (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  We build a table of n rows (1-indexed). We start by writing 0 in the 1st row. Now in every
  subsequent row, we look at the previous row and replace each occurrence of 0 with 01, and
  each occurrence of 1 with 10.
  For example, for n = 3, the 1st row is 0, the 2nd row is 01, and the 3rd row is 0110.
  Given two integer n and k, return the kth (1-indexed) symbol in the nth row of a table of n rows.
    > Example:
        Input: n = 1, k = 1
        Output: 0
        Explanation: row 1: 0

    > Example:
        Input: n = 2, k = 1
        Output: 0
        Explanation:
          row 1: 0
          row 2: 01

    > Example:
        Input: n = 2, k = 2
        Output: 1
        Explanation:
          row 1: 0
          row 2: 01

--Inputs:
  -int: two integers, n and k

--Output:
  -int: the kth number in the nth row

--Constraints:
    1 <= n <= 30
    1 <= k <= 2^(n - 1)


--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>

int kthGrammar(int n, int k) {
  // base case:
  if (k == 1)
    return 0;

  // k is even, node is a right child, so if the parent node is 0, its right child is 1:
  if (k % 2 == 0)
    return (kthGrammar(n - 1, k / 2) == 0) ? 1 : 0;
  // k is odd, node is a left child, so if the parent node is 0, its right child is 0:
  return (kthGrammar(n - 1, (k + 1) / 2) == 0) ? 0 : 1;
}

int main() {
  int n{5}, k{7};
  std::cout << "kth value in the nth row: " << kthGrammar(n, k) << "\n"; // 0

  k = 12;
  std::cout << "kth value in the nth row: " << kthGrammar(n, k) << "\n"; // 1

  k = 16;
  std::cout << "kth value in the nth row: " << kthGrammar(n, k) << "\n"; // 0

  return 0;
}