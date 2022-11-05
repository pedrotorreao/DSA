/******************************************************************************
Problem: Encode and Decode Strings
*******************************************************************************/
/*
--Problem statement:
  Design an algorithm to encode a list of strings to a string. The encoded string
  is then sent over the network and is decoded back to the original list of strings.
  Please implement "encode" and "decode".

  > Example 1:
    Input: ["lint","code","love","you"]
    Output: ["lint","code","love","you"]
    Explanation: One possible encode method is: "lint:;code:;love:;you"

   > Example 2:
    Input: ["we", "say", ":", "yes"]
    Output: ["we", "say", ":", "yes"]
    Explanation: One possible encode method is: "we:;say:;:::;yes"

--Inputs:
  encode:
    string[]: array of string
  decode:
    string: encoded string

--Output:
  encode:
    string: encoded string
  decode:
    string[]: decoded string

--Reasoning:
      ::encode(): iterate over the input array concatenating the strings with '#'
    and adding them together.
      ::decode(): iterate over the encoded string splitting it up at the '#'
    delimiters.

--Time complexity: O(N), where N is the sum of all the string lengths.

--Space complexity: O(N),where N is a sum of all the string lengths.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
void display1D(const std::vector<T> &arr);

std::string encode(std::vector<std::string> &strs) {
  std::string encoded_str{};
  const int SIZE = strs.size();

  for (int i{0}; i < SIZE; ++i) {
    encoded_str += (strs.at(i) + '#');
  }

  return encoded_str;
}

std::vector<std::string> decode(std::string &str) {
  std::vector<std::string> decoded_str{};
  std::string tk{};
  std::stringstream ss(str);

  while (std::getline(ss, tk, '#'))
    decoded_str.push_back(tk);

  return decoded_str;
}

int main() {
  std::vector<std::string> strs{}, d_str{};
  std::string e_str{};

  strs = {"what", "a", "nice", "message"};
  display1D(strs);
  e_str = encode(strs);
  std::cout << "Encoded string: " << e_str << "\n";
  d_str = decode(e_str);
  std::cout << "Decoded string: ";
  display1D(d_str);

  strs = {"my", "name", "is", "Bond"};
  display1D(strs);
  e_str = encode(strs);
  std::cout << "Encoded string: " << e_str << "\n";
  d_str = decode(e_str);
  std::cout << "Decoded string: ";
  display1D(d_str);

  return 0;
}

template <typename T>
void display1D(const std::vector<T> &arr) {
  std::cout << "[ ";
  for (const auto &a : arr)
    std::cout << a << " ";

  std::cout << "]\n\n";
}