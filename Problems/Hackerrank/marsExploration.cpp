/*********************************************************************************************/
/* Problem: Pangram (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

  > Example:

  > Input:

  > Output:

  > Constraints:


--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <string>

int marsExploration(std::string s)
{
  int numOfMessages = s.size() / 3;
  int changes{0};

  for (size_t i{0}; i < s.size(); i += 3)
  {
    if (s.substr(i, 3) != "SOS")
    {
      if (s.at(i) != 'S')
        changes++;
      if (s.at(i + 1) != 'O')
        changes++;
      if (s.at(i + 2) != 'S')
        changes++;
    }
  }

  return changes;
}

int main()
{
  std::string msg{"SOSTOT"};
  std::cout << "number of changes in '" << msg << "': " << marsExploration(msg) << "\n";

  msg = {"SOSSPSSQSSOR"};
  std::cout << "number of changes in '" << msg << "': " << marsExploration(msg) << "\n";

  msg = {"SOSSOT"};
  std::cout << "number of changes in '" << msg << "': " << marsExploration(msg) << "\n";

  return 0;
}