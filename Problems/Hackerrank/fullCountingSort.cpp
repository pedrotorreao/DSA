/*********************************************************************************************/
/* Problem: Full Counting Sort (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Use the counting sort to order a list of strings associated with integers. If two strings are
  associated with the same integer, they must be printed in their original order, i.e. your sorting
  algorithm should be stable. There is one other twist: strings in the first half of the original
  array are to be replaced with the character "-" (dash, ascii 45 decimal).

  > Example:
      arr = {{"0", "a"}, {"1", "b"}, {"0", "c"}, {"1", "d"}}
        -> dashed: {{"0", "-"}, {"1", "-"}, {"0", "c"}, {"1", "d"}}
        -> sorted: {{"0", "-"}, {"0", "c"}, {"1", "-"}, {"1", "d"}}
      result: - c - d

-- Inputs:
  - string arr[][]: each arr[i] is comprised of two strings, x = arr[i][0] and s = arr[i][1].
  Note: The first element of each arr[i], x , must be cast as an integer to perform the sort.

--Outputs:
  Print the strings in their correct order, space-separated on one line.

--Reasoning:
  First we clean the first half of the original array, replacing all the strings by the dash, "-",
  character. After that, we use a slightly modified counting sort to sort the arrays based on the
  value of "x". Then, we just have to print the strings.


--Time complexity: O(n+k), due to the counting sort algorithm.

--Space complexity: O(n+k), due to the counting sort algorithm.


*/

#include <iostream>
#include <string>
#include <vector>

void displayArr(const std::vector<std::vector<std::string>> &arr);
void replaceByDash(std::vector<std::vector<std::string>> &arr);
void countingSort2DHelper(std::vector<std::vector<std::string>> &res, const std::vector<std::vector<std::string>> &arr);

void countSort(std::vector<std::vector<std::string>> arr)
{
  // array to store the elements of 'arr' after they are processed:
  std::vector<std::vector<std::string>> cleanArr{arr};

  // replace strings in the first half by dash character:
  replaceByDash(cleanArr);

  // result array to store the sorted sequence:
  std::vector<std::vector<std::string>> sorted(cleanArr.size(), {"-", "-"});

  // perform counting sort:
  countingSort2DHelper(sorted, cleanArr);

  // display result:
  displayArr(sorted);
}

int main()
{
  //--test cases:
  // 1 - Expected output: "- c - d"
  std::vector<std::vector<std::string>> arr{{"0", "a"}, {"1", "b"}, {"0", "c"}, {"1", "d"}};
  countSort(arr);

  // 2 - Expected output: "- - - - - to be or not to be - that is the question - - - -"
  arr = {{"0", "ab"}, {"6", "cd"}, {"0", "ef"}, {"6", "gh"}, {"4", "ij"}, {"0", "ab"}, {"6", "cd"}, {"0", "ef"}, {"6", "gh"}, {"0", "ij"}, {"4", "that"}, {"3", "be"}, {"0", "to"}, {"1", "be"}, {"5", "question"}, {"1", "or"}, {"2", "not"}, {"4", "is"}, {"2", "to"}, {"4", "the"}

  };
  countSort(arr);

  return 0;
}

/**
 * @brief Print strings space-separated on one line.
 *
 * @param arr Target array
 */
void displayArr(const std::vector<std::vector<std::string>> &arr)
{
  for (size_t i{0}; i < arr.size(); ++i)
  {
    std::cout << arr.at(i).at(1) << " ";
  }
  std::cout << "\n";
}

/**
 * @brief Replaces strings in the first half of the array with the character '-' (dash, ascii 45 decimal).
 *
 * @param arr Target array
 */
void replaceByDash(std::vector<std::vector<std::string>> &arr)
{
  for (uint i{0}; i < (arr.size() / 2); i++)
  {
    arr.at(i).at(1) = "-";
  }
}

/**
 * @brief Sorts the 2D array based on its element id (arr[i][0]) using the Counting Sort algorithm.
 *
 * @param res Sorted array
 * @param arr Target array
 */
void countingSort2DHelper(std::vector<std::vector<std::string>> &res, const std::vector<std::vector<std::string>> &arr)
{
  int k{0};

  for (uint i{0}; i < arr.size(); i++)
  {
    int currId = stoi(arr.at(i).at(0));
    if (currId > k)
    {
      k = currId;
    }
  }

  std::vector<int> countElements(k + 1, 0);

  for (uint i{0}; i < arr.size(); i++)
  {
    int currId = stoi(arr.at(i).at(0));

    ++countElements.at(currId);
  }

  for (int i{1}; i <= k; ++i)
  {
    countElements.at(i) += countElements.at(i - 1);
  }

  for (int i = (arr.size() - 1); i >= 0; --i)
  {
    int currId = stoi(arr.at(i).at(0));

    res.at(countElements.at(currId) - 1) = arr.at(i);

    --countElements.at(currId);
  }
}