/*********************************************************************************************/
/* Problem: Drawing Book (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
 A teacher asks the class to open their books to a page number. A student can either start
 turning pages from the front of the book or from the back of the book. They always turn pages
 one at a time. When they open the book, page 1 is always on the right side. When they flip page 1,
 they see pages and 2 and 3. Each page except the last page will always be printed on both sides.
 The last page may only be printed on the front, given the length of the book. If the book is n
 pages long, and a student wants to turn to page p, what is the minimum number of pages to turn?
 They can start at the beginning or the end of the book. Given n and p, find and print the minimum
 number of pages that must be turned in order to arrive at page .

  > Example:
    n = 5     p = 3
    min = 1

  > Input - int n: the number of pages in the book

  > Output - int p: the page number to turn to

  > Constraints:
      1 <= n <= 10^5
      1 <= p <= n

--Reasoning:
  First of all, since we always view 2 pages per turn, except for the first page and maybe the last,
  we might divide the number of pages, n, and the target page, p, by 2. After that, if 'p' is in the
  first half of the book, just return the result of its division; otherwise, if 'p' is located on
  the second half of the book, subtract its division from n's division and return it. Basically, the
  return statement will make this comparison, if 'p' is in the first half, we'll perform less turns
  if we go to it from the start:
          p/2 < (p-n)/2 :: count_2 < count_1  --> return count_2
  otherwise, if 'p' is in the second half, it'll be faster to get to from the end:
          p/2 > (p-n)/2 :: count_2 > count_1  --> return count_1

--Time complexity: O(1), there is no dependency on the input size.

--Space complexity: O(1), there is no dependency on the input size.
*/

#include <iostream>
#include <cmath>

int pageCount(int n, int p)
{
  int count_1 = floor(n / 2.0);
  int count_2 = floor(p / 2.0);

  return std::min(count_2, count_1 - count_2);
}

int main()
{
  int n{5};                                                              // total number of pages
  int p{3};                                                              // number of the page we're looking for
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 1

  n = 35;
  p = 34;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 0

  n = 35;
  p = 31;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 2

  n = 35;
  p = 15;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 7

  n = 35;
  p = 20;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 7

  n = 35;
  p = 2;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 1

  n = 6;
  p = 5;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 1

  n = 6;
  p = 2;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 1

  n = 4;
  p = 4;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 0

  n = 6;
  p = 4;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 1

  n = 7;
  p = 3;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 1

  n = 83246;
  p = 78132;
  std::cout << "Min. number of page turns: " << pageCount(n, p) << "\n"; // Expected: 2557

  return 0;
}
