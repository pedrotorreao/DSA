/*********************************************************************************************/
/* Problem: Happy Number ********/
/*********************************************************************************************/
/*
--Problem statement:
  Write an algorithm to determine if a number n is happy.
  A happy number is a number defined by the following process:
    - Starting with any positive integer, replace the number by the sum of the squares of its
    digits.
    - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly
    in a cycle which does not include 1.
    - Those numbers for which this process ends in 1 are happy.
  Return true if n is a happy number, and false if not.

--Input:
  int: n

--Output:
  bool: indicates whether n is a happy number or not.

--Constraints:
  - 1 <= n <= 231 - 1

--Reasoning: See comments below.

--Time complexity: O(LogN), since at each step we divide the original number by 10?

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iomanip>
#include <iostream>
#include <unordered_set>

bool isHappy(int n) {
  // Hash set to keep track of the already seen sums. In case the same sum appears
  // again, it means we have no solution since the same calculations will keep
  // being repeated and we'll never have a sum which equals to 1:
  std::unordered_set<int> hs;
  // Iterate while no solution is found or until a loop relationship is identified:
  while (n != 1) {
    int new_n{0};

    while (n > 0) {
      // get the least significant digit, i.e. the rightmost:
      int currDigit = n % 10;
      // update the sum:
      new_n += currDigit * currDigit;
      // remove the already considered number:
      n /= 10;
    }

    // sum has been seen before, therefore there's a loop
    // and a solution is not possible:
    if (hs.count(new_n) > 0)
      return false;
    else
      hs.insert(new_n);

    n = new_n;
  }

  return true;
}

int main() {
  std::cout << std::boolalpha;

  int num{19};
  std::cout << num << " is a happy number: " << isHappy(num) << "\n";

  num = 2;
  std::cout << num << " is a happy number: " << isHappy(num) << "\n";

  num = 16;
  std::cout << num << " is a happy number: " << isHappy(num) << "\n";

  return 0;
}