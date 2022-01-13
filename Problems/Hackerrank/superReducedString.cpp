/*********************************************************************************************/
/* Problem: Super reduced string (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Reduce a string of lowercase characters in range ascii[‘a’..’z’] by doing a series of operations.
  In each operation, select a pair of adjacent letters that match, and delete them.
  Delete as many characters as possible using this method and return the resulting string. If the
  final string is empty, return "Empty String".
  > Example:
    a.) s="aab"   -- return "b"
    b.) s="abba"  -- return "Empty String"

--Inputs:
  -string s: a string to reduce

--Outputs:
  -string: the reduced string or "Empty String"

--Constraints:
  1 <= length of s <= 100

--Reasoning:
  If there is only one character in the string, there is no repeated characters to be removed, so
  we just return it. Otherwise, we iterate over the string and every time we find adjacent repeated
  characters, we remove them and decrement 'i' by 2 to set it back to the position before the removed
  pair in order to be able to account for the case where adjacent repeated characters appear after
  a removal.
  > Example: "yeatbbtaj"
    1. When we get to the second "b", i=5, we see that there is a matching pair "bb", remove it and
        set 'i' back the position before the removed characters:
            --> s="yeattaj"       i=i-2=3
    2. Now, when we keep iterating we'll be able to notice that a new matchin pair has been formed after
        the pair "bb" was removed, "tt" and i=4, we then remove it and set 'i' back:
            --> s="yeaaj"         i=i-2=2
    3. Again, a new matching pair is found, "aa" when i=3, so we remove it and set 'i' back:
            --> s="yej"           i=i-2=1
    4. There is no repeated characters anymore, the string to be returned is "yej".

--Time complexity: O(N), where N is the length of the string.

--Space complexity: O(1), no additional input-dependent space is allocated.

*/

#include <iostream>
#include <string>

std::string superReducedString(std::string s)
{
  if (s.size() == 1)
    return s;

  for (int i{1}; i < s.size(); ++i)
  {
    if (s.at(i) == s.at(i - 1))
    {
      s.erase(i - 1, 2);
      i = (i - 2 < 0) ? 0 : (i - 2);
    }
  }

  if (s.empty())
    return "Empty String";

  return s;
}

int main()
{
  std::string str{"nbfiaaifbng"};

  std::cout << "Reduce version of '" << str << "': " << superReducedString(str) << "\n";

  return 0;
}

/*
-- Alternative solution:
bool repeatedNeighbors(const std::string &str, int &pos){
    for(int i{1}; i < str.size(); i++){
        if(str.at(i) == str.at(i-1)){
            pos = i-1;
            return true;
        }
    }
    return false;
}
string superReducedString(string s) {
    if(s.size() == 1) return s;

    bool done{false};
    int i{1}, pos{-1};

    while (true) {
       if (!repeatedNeighbors(s, pos)) break;

       s.erase(pos,2);
    }

    if(s.empty()) return "Empty String";

    return s;
}
*/