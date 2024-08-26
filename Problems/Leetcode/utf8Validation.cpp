/***
Problem: LC 393. UTF-8 Validation
(https://leetcode.com/problems/utf-8-validation/description/)

--Problem statement:
Given an integer array 'data' representing the data, return whether it is a valid UTF-8
encoding (i.e. it translates to a sequence of valid UTF-8 encoded characters).

A character in UTF8 can be from 1 to 4 bytes long, subjected to the following rules:
    - For a 1-byte character, the first bit is a 0, followed by its Unicode code.
    - For an n-bytes character, the first n bits are all one's, the n + 1 bit is 0, followed by
    n - 1 bytes with the most significant 2 bits being 10.

This is how the UTF-8 encoding would work:

     Number of Bytes   |        UTF-8 Octet Sequence
                       |              (binary)
   --------------------+-----------------------------------------
            1          |   0xxxxxxx
            2          |   110xxxxx 10xxxxxx
            3          |   1110xxxx 10xxxxxx 10xxxxxx
            4          |   11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

x denotes a bit in the binary form of a byte that may be either 0 or 1.

Note: The input is an array of integers. Only the least significant 8 bits of each integer is used
to store the data. This means each integer represents only 1 byte of data.

  Example 1:
    Input: data = [197,130,1]
    Output: true
    Explanation:
      'data' represents the octet sequence: 11000101 10000010 00000001.
      It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

  Example 2:
    Input: data = [235,140,4]
    Output: false
    Explanation:
      'data' represented the octet sequence: 11101011 10001100 00000100.
      The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.
      The next byte is a continuation byte which starts with 10 and that's correct.
      But the second continuation byte does not start with 10, so it is invalid.

--Inputs:
  int[]: integer array data

--Output:
  bool: boolean indicating whether 'data' represents a valid utf-8 encoding.

--Constraints:
    :: 1 <= data.length <= 2 * 10^4
    :: 0 <= data[i] <= 255

--Reasoning: see comments below.

--Time complexity:
    O(N), where N is the size of the 'data' array.

--Space complexity:
    O(1), since no input dependent space needs to be allocated.

*/

#include <iostream>
#include <vector>

class Solution {
public:
  bool validUtf8(std::vector<int> &data) {
    const int N = data.size();
    int continuationBytesCount = 0, i = 0;

    for (auto &octet : data) {
      // if we are not expecting a continuation byte, check if it satifies
      // the utf-8 rules:
      if (continuationBytesCount == 0) {
        // if current 'octet' starts with a '0', it is a 1-byte character, continue to the next 'octet':
        if ((octet >> 7) == 0)
          continue;

        // if current 'octet' starts with a '110' sequence, it is a 2-byte character, so we expect one
        // continuation character:
        if ((octet >> 5) == 6) {
          continuationBytesCount = 1;
          continue;
        }

        // if current 'octet' starts with a '1110' sequence, it is a 3-byte character, so we expect two
        // continuation characters:
        if ((octet >> 4) == 14) {
          continuationBytesCount = 2;
          continue;
        }

        // if current 'octet' starts with a '11110' sequence, it is a 4-byte character, so we expect three
        // continuation characters:
        if ((octet >> 3) == 30) {
          continuationBytesCount = 3;
          continue;
        }

        // if current 'octet' does not match any valid utf-8 starting byte pattern, return false:
        return false;
      }

      // if we are expecting a continuation byte, i.e. continuationBytesCount > 0, check if it starts
      // with the pattern '10'; if so, continue to the next, otherwise, it is not valid:
      if ((octet >> 6) != 2)
        return false;

      continuationBytesCount--;
    }

    return (continuationBytesCount == 0);
  }
};

/*
-> each data[i] represents 1 byte (so, 0 <= data[i] <= 255)
-> a character in UTF8 can be from 1 to 4 bytes long:
    -> so, if data.length > 4, that indicates other characters? yes
-> data[] is an array of integers and only the 8 LSBs of each integer is used to store the data.
*/

int main() {
  std::cout << std::boolalpha;

  Solution s;
  std::vector<int> data{};
  bool res{false}, expected{false};

  data = {197, 130, 1};
  res = s.validUtf8(data);
  expected = true;
  std::cout << "> data input represents a valid utf-8 encoding: " << res
            << (res == expected ? "\t\tPASSED" : "\t\tFAILED") << "\n";

  data = {235, 140, 4};
  res = s.validUtf8(data);
  expected = false;
  std::cout << "> data input represents a valid utf-8 encoding: " << res
            << (res == expected ? "\t\tPASSED" : "\t\tFAILED") << "\n";
  return 0;
}