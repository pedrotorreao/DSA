/****************************************************************/
/*Problem: Jumping on the Clouds (HR) ********/
/****************************************************************/
/*
-- Summary: There is a new mobile game that starts with consecutively numbered clouds. 
Some of the clouds are thunderheads and others are cumulus. The player can jump on any 
cumulus cloud having a number that is equal to the number of the current cloud plus 1 or 2. 
The player must avoid the thunderheads. Determine the minimum number of jumps it will 
take to jump from the starting postion to the last cloud. It is always possible to win the 
game. For each game, you will get an array of clouds numbered 0 if they are safe or 1 if 
they must be avoided. 
-- Input(s): a vector of size n containing 0s and 1s
-- Expected output(s): Print the minimum number of jumps needed to win the game.
-- Constraints: (2 ≤ n ≤ 100), c[i] ∈ {0,1}, c[0] = c[n-1] = 0
*/

#include <iostream>
#include <vector>

int jumpingOnClouds(std::vector<int> c)
{
    int count = 0;
    size_t index = 0;

    while (index < c.size() - 1)
    {
        ++count;
        if ((index + 2) < c.size() && c.at(index + 2) == 0)
        {
            index += 2;
        }
        else
        {
            index++;
        }
    }
    return count;
}

int main()
{
    std::vector<int> vec1{0, 0, 0, 0, 1, 0};
    int test1 = jumpingOnClouds(vec1);

    std::vector<int> vec2{0, 0, 1, 0, 0, 1, 0};
    int test2 = jumpingOnClouds(vec2);

    std::vector<int> vec3{0, 1, 0, 1, 0, 1, 0};
    int test3 = jumpingOnClouds(vec3);

    std::cout << "test 1: " << test1 << (test1 == 3 ? " PASSED" : " FAILED") << "\n";
    std::cout << "test 2: " << test2 << (test2 == 4 ? " PASSED" : " FAILED") << "\n";
    std::cout << "test 3: " << test3 << (test3 == 3 ? " PASSED" : " FAILED") << "\n";

    return 0;
}