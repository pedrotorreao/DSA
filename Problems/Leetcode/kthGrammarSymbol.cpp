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
  It is possible to visualize this problem as a binary tree. If a node is 0, its left child is 0
  and its right child is 1. Similarly, if a node is 1, its left child is 1 and its right child is 0.
  To know if the node at the Kth position is a left child or right child, we check the parity if K
  dividing it by 2. If K is even, current node at the Kth position is a right child, and its parent
  is the (K/2)th node in previous row. Otherwise, if K is odd, current node is left child and its
  parent is the ((K+1)/2)th node in previous row. Until now we know whether the value at the Kth
  position is a left or right child, now its value will depend on whether its parent node is 0 or 1.
  Without this information, we are not able to determine whether the value at the Kth position is.
  In order to find this out, we use recursion to keep going up the previous rows (binary tree), to
  find the parent node until we reach the first row.

--Time complexity: O(log(K)), since at every step K is halved until it reaches 1.

--Space complexity: O(log(K)), due to the stack frames required for the recursive calls.

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