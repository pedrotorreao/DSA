/*********************************************************************************************/
/* Problem: Longest Substring Without Repeating Characters (LC) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Given a string s, find the length of the longest substring without repeating characters.
  > Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.

  > Example 2:
    Input: s = "bbbbb"
    Output: 1
    Explanation: The answer is "b", with the length of 1.

  > Example 3:
    Input: s = "pwwkew"
    Output: 3
    Explanation: The answer is "wke", with the length of 3.
    Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

--Input:
  string: s

--Output:
  int: longest substring without repeating characters

--Constraints:
  0 <= s.length <= 5 * 104
  s consists of English letters, digits, symbols and spaces.

--Time complexity: O(N), where N is the size of the input string.

--Space complexity:
  O(N), in the worst case in which all the characters are unique.

*******************************************************************************/
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int lengthOfLongestSubstring(std::string &s) {
  // initialize variables:
  // -- start: left border of the current window and position of repeated character, if any
  // -- end: right border of the current window and position of the current character
  // -- bestLength: max substring length so far
  // -- currLength: length of the current window (current substring)
  int start{0}, end{0}, bestLength{0}, currLength{0};
  // get string size:
  const int length = s.size();

  // set to keep track of the characters already seen:
  std::unordered_set<char> seen;

  while ((start < length) && (end < length)) {
    // current character of 's':
    char currChar = s.at(end);
    // case #1 - current character hasn't been seen before:
    if (seen.count(currChar) == 0) {
      // mark character as 'seen' and advance window:
      seen.insert(currChar);
      ++end;
      // calculate the current window length, compare it with the max length
      // so far and update 'bestLength' if current window length is greater:
      currLength = end - start;
      bestLength = std::max(bestLength, currLength);
    }
    // case #2 - current character is a repeated character:
    else {
      char firstSeen = s.at(start);
      // advance the left border by one position decreasing the current window size:
      seen.erase(currChar);
      ++start;
    }
  }

  return bestLength;
}

int main() {
  std::string s;

  s = "abcabcbb";
  std::cout << "Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring(s) << "\n";

  s = "bbbbb";
  std::cout << "Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring(s) << "\n";

  s = "pwwkew";
  std::cout << "Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring(s) << "\n";

  s = "dvdf";
  std::cout << "Longest Substring Without Repeating Characters: " << lengthOfLongestSubstring(s) << "\n";

  return 0;
}
/*
s = "pwwkew"    start = end = best = curr = 0

> end=0 -> s[0]=p   seen(p):NO
    seen(p):YES
    end++ -> end=1
    curr=end-start=1-0=1
    best=max(best,curr)=max(0,1)=1
> end=1 -> s[1]=w   seen(w):NO
    seen(w):YES
    end++ -> end=2
    curr=end-start=2-0=2
    best=max(best,curr)=max(1,2)=2
> end=2 -> s[2]=w   seen(w):YES
    first=s[start]=s[0]=p
    seen(first)->seen(p):NO
    start++ -> start=1
> end=2 -> s[2]=w   seen(w):YES
    first=s[start]=s[1]=w
    seen(first)->seen(w):NO
    start++ -> start=2
> end=2 -> s[2]=w   seen(w):NO
    seen(w):YES
    end++ -> end=3
    curr=end-start=3-2=1
    best=max(best,curr)=max(2,1)=2
> end=3 -> s[3]=k   seen(k):NO
    seen(k):YES
    end++ -> end=4
    curr=end-start=4-2=2
    best=max(best,curr)=max(2,2)=2
> end=4 -> s[4]=k   seen(e):NO
    seen(e):YES
    end++ -> end=5
    curr=end-start=5-2=3
    best=max(best,curr)=max(2,3)=3
> end=5 -> s[5]=w   seen(w):YES
    first=s[start]=s[2]=w
    seen(first)->seen(w):NO
    start++ -> start=3
*/
