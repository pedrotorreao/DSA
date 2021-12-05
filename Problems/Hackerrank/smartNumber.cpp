/*********************************************************************************************/
/* Problem: Smart Number (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:

-- Inputs:

--Outputs:

--Reasoning:

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <vector>
#include <cmath>

bool is_smart_number(int num)
{
  int val = (int)std::sqrt(num);
  if ((num / (double)val == val))
    return true;
  return false;
}

int main()
{
  std::vector<int> test_cases{1, 2, 7, 169};

  for (int i = 0; i < test_cases.size(); i++)
  {
    bool ans = is_smart_number(test_cases.at(i));

    if (ans)
    {
      std::cout << "YES" << std::endl;
    }
    else
      std::cout << "NO" << std::endl;
  }
  return 0;
}
/*
Expected:
  YES
  NO
  NO
  YES
*/