/***
Problem: LC 2363. Merge Similar Items
(https://leetcode.com/problems/merge-similar-items/description/)

--Problem statement:
You are given two 2D integer arrays, 'items1' and 'items2', representing two sets of items. Each array 
items has the following properties:
    - items[i] = [valuei, weighti] where 'valuei' represents the value and 'weighti' represents the 
    weight of the ith item.
    - The value of each item in 'items' is unique.

Return a 2D integer array ret where ret[i] = [valuei, weighti], with 'weighti' being the sum of weights 
of all items with value 'valuei'.

Note: 'ret' should be returned in ascending order by value.

  > Example 1:
      Input: items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]]
      Output: [[1,6],[3,9],[4,5]]
      Explanation: 
        The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 5, total weight = 1 + 5 = 6.
        The item with value = 3 occurs in items1 with weight = 8 and in items2 with weight = 1, total weight = 8 + 1 = 9.
        The item with value = 4 occurs in items1 with weight = 5, total weight = 5.  
        Therefore, we return [[1,6],[3,9],[4,5]].

  > Example 2:
      Input: items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]]
      Output: [[1,4],[2,4],[3,4]]
      Explanation: 
        The item with value = 1 occurs in items1 with weight = 1 and in items2 with weight = 3, total weight = 1 + 3 = 4.
        The item with value = 2 occurs in items1 with weight = 3 and in items2 with weight = 1, total weight = 3 + 1 = 4.
        The item with value = 3 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4.
        Therefore, we return [[1,4],[2,4],[3,4]].

  > Example 3:
      Input: items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]]
      Output: [[1,7],[2,4],[7,1]]
      Explanation:
        The item with value = 1 occurs in items1 with weight = 3 and in items2 with weight = 4, total weight = 3 + 4 = 7. 
        The item with value = 2 occurs in items1 with weight = 2 and in items2 with weight = 2, total weight = 2 + 2 = 4. 
        The item with value = 7 occurs in items2 with weight = 1, total weight = 1.
        Therefore, we return [[1,7],[2,4],[7,1]].

--Inputs:
    int[][]: two 2D integer arrays, 'items1' and 'items2', representing two sets of items.

--Output:
    int[][]: 2D integer array ret where ret[i] = [valuei, weighti], with 'weighti' being the sum of weights 
    of all items with value 'valuei'.

--Constraints:
    :: 1 <= items1.length, items2.length <= 1000
    :: items1[i].length == items2[i].length == 2
    :: 1 <= valuei, weighti <= 1000
    :: Each valuei in items1 is unique.
    :: Each valuei in items2 is unique.

--Reasoning: Use a map to keep keys ordered by value and combine the matching key' values. See comments below.

--Time complexity:
    O((n * log(n)) + (m * log(m))), where n and m are the number of items in 'items1' and 'items2', respectively.
      for n = m: O((n * log(n)) + (m * log(m))) --> O(2 * n * log(n) ≈ O(n * log(n))

--Space complexity: 
    O(n+m), where n and m are the number of items in 'items1' and 'items2', respectively, in the worst case that
    there are only distinct keys between the two arrays.

*/
#include <iostream>
#include <map>
#include <vector>

void display2D(const std::vector<std::vector<int>> &arr);

class Solution {
public:
    std::vector<std::vector<int>> mergeSimilarItems(std::vector<std::vector<int>>& items1, std::vector<std::vector<int>>& items2) {
        // Using a map to keep items sorted by key and store sums of values:
        std::map<int, int> mergedItems;

        // Process items from the first vector - O(n * log(n)):
        for (auto& item : items1) {
            mergedItems[item[0]] += item[1];
        }

        // Process items from the second vector - O(m * log(m)):
        for (auto& item : items2) {
            mergedItems[item[0]] += item[1];
        }

        // Convert map entries to a vector of vectors - O(n+m):
        std::vector<std::vector<int>> result;
        for (auto& entry : mergedItems) {
            result.push_back({entry.first, entry.second});
        }

        return result;
    }
};

int main() {
  Solution sol;

  std::vector<std::vector<int>> items1{}, items2{}, res{};

  items1 = {{1,1}, {4,5}, {3,8}};
  items2 = {{3,1}, {1,5}};
  res = sol.mergeSimilarItems(items1, items2);
  std::cout << ">> Merged similar items: ";
  display2D(res);

  items1 = {{1,1},{3,2},{2,3}};
  items2 = {{2,1},{3,2},{1,3}};
  res = sol.mergeSimilarItems(items1, items2);
  std::cout << ">> Merged similar items: ";
  display2D(res);

  items1 = {{1,3},{2,2}};
  items2 = {{7,1},{2,2},{1,4}};
  res = sol.mergeSimilarItems(items1, items2);
  std::cout << ">> Merged similar items: ";
  display2D(res);

  return 0;
}

void display2D(const std::vector<std::vector<int>> &arr) {
  std::cout << "[ ";
  for (const auto &item : arr) {
    std::cout << "[ ";
    std::cout << item.at(0) << ", " << item.at(1) << " ] ";
  }
  std::cout << "]\n\n";
}