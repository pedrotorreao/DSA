/*********************************************************************************************/
/* Problem: Road Repair ********/
/*********************************************************************************************/
/*
--Problem statement:
  Suppose that your job is to repair a road. The road is represented by a string 'roadStr'
  consisting of 'N' characters in which each character represents a stretch of road. Each character
  can be either '.' or 'x', where '.' represents a good stretch of road and 'x' a bad one. For
  example:
    roadStr = "...xxx..x":
        the road starts with a 3 good patches, followed by 3 bad ones, followed by 2 good ones
        and ending with 1 bad one.
  You can select any number of consecutive bad streches and repair all of them. The cost of
  repairing M consecutive bad spots is M+1. So, for the previous example, repairing the first 2
  bad streches would cost 3. If you have a budget 'totalBudget', how many repairs can you perform
  with the given budget?
    > Example - roadStr = "..xxxxx" and totalBudget = 4:
        There a few different approaches, one is to repair the 3 bad spots in the end. The result is 3 repairs.

--Input:
  string: 'roadStr' of size N
  int: 'totalBudget'

--Output:
  int: the number of maximum possible repairs that can be made without exceding the budget.

--Assumptions:
  - 1 <= N <= 100000
  - 0 <= 'totalBudget' <= 200000
  - roadStr[i] is either 'x' or '.'

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <string>
#include <vector>

int maxNumberOfRepairs(std::string &roadStr, int totalBudget) {

  // ..
}

int main() {
  // test cases:
  std::string road{"...xxx..x....xxx"};
  int budget{7};
  int res = maxNumberOfRepairs(road, budget);
  int expect = 5;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");

  std::string road{"..xxxxx"};
  int budget{4};
  int res = maxNumberOfRepairs(road, budget);
  int expect = 3;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");

  std::string road{"x.x.xxx...x"};
  int budget{14};
  int res = maxNumberOfRepairs(road, budget);
  int expect = 6;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");

  std::string road{".."};
  int budget{5};
  int res = maxNumberOfRepairs(road, budget);
  int expect = 0;
  std::cout << "Max. number of repairs possible: " << res << "\t" << (res == expect ? "--PASSED\n" : "--FAILED\n");

  return 0;
}
