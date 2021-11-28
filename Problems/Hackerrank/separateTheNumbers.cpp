/*********************************************************************************************/
/* Problem: Separate the numbers (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  A numeric string, s, is beautiful if it can be split into a sequence of two or more positive
  integers, a[1],a[2],...,a[n], satisfying the following conditions:
    1. "a[i] - a[i-1] = 1" for any 1<i<=n (i.e., each element in the sequence is 1 more than
    the previous element).
    2. No a[i] contains a leading zero. For example, we can split "s = 10203" into the sequence
    {1,02,03}, but it is not beautiful because 02 and 03 have leading zeroes.
    3. The contents of the sequence cannot be rearranged. For example, we can split "s = 312"
    into the sequence {3,1,2}, but it is not beautiful because it breaks our first constraint
    (i.e., "1-3 != 1").

  > Examples of beautiful strings:
    a. "1234"     b. "91011"    c. "99100"

  > Input - s: an integer value represented as a string

  > Output: if "s" is beautiful, print "YES x", where "x" is the first number of the increasing
  sequence. If there are multiple such values of "x", choose the smallest. Otherwise, print NO.

--Reasoning:
  We begin by extracting the first number on the string, 'firstNum', and using this number to
  build a new string, i.e. the beautiful string that would begin with this number, by concatenating
  its subsequent numbers. Once we are done, i.e. the new string is the same size as 's', we compare
  the newly built string with the input string. If they match, 's' is a beautifull string, print
  "YES firstNum", otherwise print "NO" and repeat the processes by building a new string, now using
  the first couple numbers as 'firstNum'. This allows us to check all possible cases for 's'.

--Time complexity:
  O(N*N), where N is the length of the input string, for the worst case in which there's no solution.

--Space complexity:
  O(N), since we build new strings of size N.
*/

#include <iostream>
#include <string>

void separateNumbers(std::string s)
{
  std::string firstNum, beautifulStr;

  for (int l = 1; (l <= s.size() / 2) && (s != beautifulStr); l++)
  {
    firstNum = beautifulStr = s.substr(0, l);
    for (int i = 1; beautifulStr.size() < s.size(); i++)
    {
      beautifulStr += std::to_string(stoll(firstNum) + i);
    }
  }
  std::cout << (s == beautifulStr ? ("YES " + firstNum + "\n") : "NO\n");
}

int main()
{
  std::string num{"1234"};
  separateNumbers(num); // Expects "YES"

  num = {"91011"};
  separateNumbers(num); // Expects "YES"

  num = {"99100"};
  separateNumbers(num); // Expects "YES"

  num = {"312"};
  separateNumbers(num); // Expects "NO"

  num = {"10203"};
  separateNumbers(num); // Expects "NO"

  num = {"100101"};
  separateNumbers(num); // Expects "YES"

  return 0;
}
