/*********************************************************************************************/
/* Problem: Weighted Uniform Strings (HR) ********/
/* https://www.hackerrank.com/challenges/weighted-uniform-string/problem
/*********************************************************************************************/
/*
--Problem statement:
  A weighted string is a string of lowercase English letters where each letter has a weight.
  Character weights are 1 to 26 from 'a' to 'z' as shown below:
    a:1   b:2   c:3   d:4   e:5   f:6   g:7   ...   q:17    ...   y:25    z:26
  The weight of a string is the sum of the weights of its characters. For example:
    "apple": 1 + 16 + 16 + 12 + 5 = 50  --> not uniform
    "watch": 32 + 1 + 20 + 3 + 8 = 53   --> not uniform
    "aaa": 1 + 1 + 1 = 3   --> uniform
  A uniform string consists of a single character repeated zero or more times. For example, "ccc"
  and "a" are uniform strings, but "bcb" and "cd" are not.

  Given a string, 's', let U be the set of weights for all possible uniform contiguous substrings
  of string 's'. There will be 'n' queries to answer where each query consists of a single integer.
  Create a return array where for each query, the value is "Yes" if query[i] ∈ U. Otherwise,
  append "No".

  > Example:
      inputs: s="abbcccdddd"      queries=[1,7,5,4,15]
        string  weight
          a       1     -->    query[0]: "Yes"
          b       2
          bb      4     -->    query[3]: "Yes"
          c       3
          cc      6
          ccc     9
          d       4
          dd      8
          ddd     12
          dddd    16
      output: ["Yes", "No", "No", "Yes", "No"]

--Input:
  - string s: a string
  - int queries[n]: an array of integers

--Output:
  - string[n]: an array of strings that answer the queries

--Constraints:
  1<=length of s,n <=10^5
  1<=queries[i]<=10^7

--Reasoning: See comments below.

--Time complexity:
  O(N + L), where N is the size of the array and L is the length of the string.

--Space complexity:
  O(N), where N is the size of the array.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
void displayVec(const std::vector<T> &vec) {
  for (const auto &v : vec) {
    std::cout << v << "    ";
  }
  std::cout << "\n";
}

std::vector<std::string> weightedUniformStrings_2(std::string s, std::vector<int> queries) {
  const int L = s.size();       // string 's' length
  const int N = queries.size(); // vector 'queries' size

  // hash map for mapping the queries to either the string "No" or "Yes", depending if they
  // happen or not on "s":
  std::unordered_map<int, std::string> q_map;
  // initialize each query to "No" since we'll still process the string:
  for (const auto &q : queries)
    q_map[q] = "No";

  int curr_substr_weight{}; // current uniform substring weight

  char prev_char{}; // previous character
  for (int i{0}; i < L; ++i) {
    char curr_char = s.at(i);                        // current string character
    int curr_char_weight = int(curr_char) - 'a' + 1; // current string character weight

    // if concatenating the current character does not make the string lose its uniformity,
    // update the substring weight:
    if (curr_char == prev_char) {
      curr_substr_weight += curr_char_weight;
    }
    // otherwise, the current substring consists of only the current character and the
    // current substring weight is the weight of the current character:
    else {
      curr_substr_weight = curr_char_weight;
    }
    // if the current substring weight matches one of the query values, change its value
    // in the hash map to "Yes":
    if (q_map.find(curr_substr_weight) != q_map.end())
      q_map[curr_substr_weight] = "Yes";

    // update the previous character:
    prev_char = curr_char;
  }

  std::vector<std::string> answers; // output vector
  // iterate over the hash map and filling the output vector:
  for (const auto &q : queries) {
    answers.push_back(q_map[q]);
  }

  return answers;
}

int main() {
  std::string s{"abbcccdddd"};
  std::vector<int> queries{1, 7, 5, 4, 15};
  displayVec(weightedUniformStrings_2(s, queries));

  return 0;
}