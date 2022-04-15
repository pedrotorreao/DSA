/*********************************************************************************************/
/* Problem: Chief Hopper (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Chief's bot is playing an old DOS based game. There is a row of buildings of different heights
  arranged at each index along a number line. The bot starts at building 0 and at a height of 0.
  You must determine the minimum energy his bot needs at the start so that he can jump to the
  top of each building without his energy going below zero.
  Units of height relate directly to units of energy. The bot's energy level is calculated as
  follows:
    - If the bot's 'botEnergy' is less than the height of the building, his 'newEnergy' is
      calculated in the following way:
          newEnergy = botEnergy - (height - botEnergy)
    - If the bot's 'botEnergy' is greater than the height of the building, 'newEnergy' is
      calculated in the following way:
          newEnergy = botEnergy + (botEnergy - height)

    > Example:
      arr=[2,3,4,3,2]
      Starting with botEnergy=4, we get the following table:
          botEnergy   height  delta
              4         2       +2
              6         3       +3
              9         4       +5
              14        3       +11
              25        2       +23
              48
      That allows the bot to complete the course, but may not be the minimum starting value. The
      minimum starting in this case is 3.

  > Example:
    Input: arr=[3, 4, 3, 2, 4]
    Output: 4
    If initial energy is 4, after step 1 energy is 5, after step 2 it's 6, after step 3 it's 9 and
    after step 4 it's 16, finally at step 5 it's 28. You can verify for lower initial energy bot
    will have negative energy in the end.

  > Example:
    Input: arr=[4, 4, 4]
    Output: 4
    In the second test case if bot has energy 4, it's energy is changed by (4 - 4 = 0) at every
    step and remains 4.

--Inputs:
  -int arr[n]: building heights

--Output:
  -int: the minimum starting 'botEnergy'

--Constraints:
  1<=n<=10^5
  1<=arr[i]<<10^5 where 1<=i<=n

--Reasoning:
  In the best scenario, we'd pick a minimum starting energy that would result in a final energy
  equal to zero. That'd be the best outcome since no energy left at the end means no energy wasted.
  So, instead of iterating from the start to the end of the array of heights, we'll begin from the
  end and assume that the final bot energy is 0. This'll ensure that we pick the minimum energy at
  the beginning.

  Based on the energy update equations given by the problem statement:
    botEnergy < height[i]:
      newEnergy = botEnergy - (height - botEnergy) = 2*botEnergy - height
        -> botEnergy = (newEnergy + height)/2, for any height, height[i].
    botEnergy > height[i]:
      newEnergy = botEnergy + (botEnergy - height) = 2*botEnergy - height
        -> botEnergy = (newEnergy + height)/2, for any height, height[i].

  To make sure that we do not lose information due to the divisions, we perform a float division
  and round the result up:
      -> botEnergy = ceil(botEnergy + height)/2.0, for any height, height[i].

  We then calculate the energy for each building and when we reach the 1st building, the value stored
  'botEnergy' will be the minimum starting energy required.

--Time complexity: O(N), where N is the number of buildings.

--Space complexity: O(1), no additional input dependent space is needed.

*/

#include <cmath>
#include <iostream>
#include <vector>

void testSuite(void);

int chiefHopper(const std::vector<int> &arr) {
  // initialize the 'botEnergy' to zero, since that's the desired state at the end:
  int botEnergy{0};

  // iterate over the buildings' array from the end and update the energy for each one:
  for (int i = arr.size() - 1; i >= 0; --i) {
    botEnergy = ceil((botEnergy + arr.at(i)) / 2.0);
  }

  return botEnergy;
}

int main() {
  testSuite();

  return 0;
}

void testSuite(void) {
  std::vector<std::vector<int>> testVec{{2, 3, 4, 3, 2}, {3, 4, 3, 2, 4}, {4, 4, 4}, {1, 6, 4}, {4, 4}, {4}, {5}};
  std::vector<int> expected{3, 4, 4, 3, 3, 2, 3};

  std::cout << "...Running tests\n\n";

  for (size_t i{0}; i < testVec.size(); ++i) {
    std::cout << "--TC #" << i << ": ";
    if (chiefHopper(testVec.at(i)) == expected.at(i))
      std::cout << "PASSED\n";
    else
      std::cout << "FAILED\n";
  }

  std::cout << "\n...Tests finished\n";
}