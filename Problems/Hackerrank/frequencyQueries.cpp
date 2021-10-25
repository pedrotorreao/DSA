/*********************************************************************************************/
/* Problem: Frequency Queries (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  You are given q queries. Each query is of the form two integers described below:
  - 1 x: Insert x in your data structure.
  - 2 y: Delete one occurence of y from your data structure, if present.
  - 3 z: Check if any integer is present whose frequency is exactly. If yes, print 1 else 0.
  The queries are given in the form of a 2-D array queries of size q where queries[i][0]
  contains the operation, and queries[i][1] contains the data element.

  Example
    - queries = [(1,1),(2,2),(3,2),(1,1),(1,1),(2,1),(3,2)]
              Operation   Array       Output
                (1,1)       [1]
                (2,2)       [1]
                (3,2)                   0
                (1,1)       [1,1]
                (1,1)       [1,1,1]
                (2,1)       [1,1]
                (3,2)                   1
      returns an array with the output: [0,1].

  Input:
    - int queries[q][2]: a 2-d array of integers

  Output:
    - int[]: the results of queries of type 3.

  Constraints:
    - 1<=q<=10^5
    - 1<=x,y,z<=10^9
    - all queries[i][0] ∈ {1,2,3}
    - 1<=queries[i][1]<=10^9

--Reasoning:
  Use two maps, one for storing each element and its frequency (element: frequency), and the other for
  storing each frequency and the number of elements with that frequency (frequency: # of elements).
  Also, keep a vector to store the output of each type 3 query.

--Time complexity: O(n), where n is the number of queries.

--Space complexity: O(n), for the worst case in which we have all queries being type 1 for different values.

*/

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> freqQuery(std::vector<std::vector<int>> queries)
{
  // return vector containing the outputs of all type 3 queries:
  std::vector<int> frequency_count;
  // map for the number of elements that exist for a given frequency:
  std::unordered_map<int, int> frequency_map;
  // map for the elements and the frequencies that they appear:
  std::unordered_map<int, int> queries_map;

  auto it = queries.begin();

  while (it != queries.end())
  {
    // get the query type:
    int query = (*it).at(0);
    // get the query value:
    int value = (*it).at(1);

    if (query == 1)
    {
      // store old frequency:
      int old_freq = queries_map[value];
      // increment the frequency of 'value':
      ++queries_map[value];
      // increment the number of elements that appear with this frequency:
      ++frequency_map[queries_map[value]];
      // decrement the number of elements that appear with the old frequency:
      --frequency_map[old_freq];
      // the min. frequency count is zero:
      if (frequency_map[old_freq] < 0)
      {
        frequency_map[old_freq] = 0;
      }
    }
    else if (query == 2)
    {
      // store old frequency:
      int old_freq = queries_map[value];
      // decrement the frequency of 'value':
      --queries_map[value];
      // increment the number of elements that appear with this frequency:
      ++frequency_map[queries_map[value]];
      // decrement the number of elements that appear with the old frequency:
      --frequency_map[old_freq];
      // the min. frequency count is zero:
      if (queries_map[value] < 0)
      {
        queries_map[value] = 0;
      }
      // the min. frequency count is zero:
      if (frequency_map[old_freq] < 0)
      {
        frequency_map[old_freq] = 0;
      }
    }
    else
    {
      // there are elements which appear with this frequency:
      if (frequency_map[value] >= 1)
      {
        frequency_count.push_back(1);
      }
      // there are no elements which appear with this frequency:
      else
      {
        frequency_count.push_back(0);
      }
    }

    ++it;
  }
  return frequency_count;
}

int main()
{
  std::vector<std::vector<int>> q{{1, 1}, {2, 2}, {3, 2}, {1, 1}, {1, 1}, {2, 1}, {3, 2}};
  std::vector<int> freq_count;

  freq_count = freqQuery(q);

  for (auto it = freq_count.begin(); it != freq_count.end(); ++it)
  {
    std::cout << *it << "  ";
  }
  std::cout << std::endl;

  return 0;
}