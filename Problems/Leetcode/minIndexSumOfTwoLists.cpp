/*********************************************************************************************/
/* Problem: Minimum Index Sum of Two Lists ********/
/*********************************************************************************************/
/*
--Problem statement:
  Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of
  favorite restaurants represented by strings. You need to help them find out their common
  interest with the least list index sum. If there is a choice tie between answers, output all
  of them with no order requirement. You could assume there always exists an answer.
  > Example 1:
    Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"],
           list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
    Output: ["Shogun"]
    Explanation: The only restaurant they both like is "Shogun".

--Input:
  std::vector<std::string>: 2 lists of restaurant names

--Output:
  std::vector<std::string>: common restaurants with least index sum

--Constraints:
  1 <= list1.length, list2.length <= 1000
  1 <= list1[i].length, list2[i].length <= 30
  list1[i] and list2[i] consist of spaces ' ' and English letters.
  All the stings of list1 are unique.
  All the stings of list2 are unique.

--Reasoning: See comments below.

--Time complexity: O(n), where n is the size of the largest list

--Space complexity: O(n'), where n' is the size of the list 1

*/

#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::string> findRestaurant(std::vector<std::string> &list1, std::vector<std::string> &list2) {
  // hash map for mapping the restaurants to their positions:
  std::unordered_map<std::string, int> hm;
  // variable to keep track of the smallest sum found:
  int minSum = std::numeric_limits<int>::max();
  // Map all the strings in the first list to their indexes:
  for (int i{0}; i < list1.size(); ++i) {
    hm[list1.at(i)] = i;
  }
  // output restaurant list, i.e. common restaurants with least index sum:
  std::vector<std::string> common;
  // Iterate through the second list looking for matches. Whenever we find one, we calculate the sum of the
  // indexes and check if this sum is less than or equal to the recorded min sum so far, 'minSum'. If it is
  // less, we update 'minSum', clear the result list and add the current min. sum restaurant to it. In case
  // the current id sum matches 'minSum', we just append the current restaurant to the output list:
  for (int i{0}; i < list2.size(); ++i) {
    if (hm.find(list2.at(i)) != hm.end()) {
      if (hm[list2.at(i)] + i < minSum) {
        minSum = hm[list2.at(i)] + i;
        common.clear();
        common.push_back(list2.at(i));
      } else if (hm[list2.at(i)] + i == minSum) {
        common.push_back(list2.at(i));
      }
    }
  }

  return common;
}

void displayResult(std::vector<std::string> &l) {
  for (const auto &res : l) {
    std::cout << res << "   ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<std::string> l_1, l_2, l_common;

  l_1 = {"Shogun", "Tapioca Express", "Burger King", "KFC"};
  l_2 = {"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
  l_common = findRestaurant(l_1, l_2);
  displayResult(l_common);

  l_1 = {"Faaca", "Mr Hoppy", "johnny gastrobar", "Don Ferreiro", "Seu Tito", "McDonalds", "Tamassa"};
  l_2 = {"Camaroes", "Tamassa", "Fluppy", "Faaca"};
  l_common = findRestaurant(l_1, l_2);
  displayResult(l_common);

  return 0;
}
