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

--Time complexity:

--Space complexity:

*/

#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> freqQuery(std::vector<std::vector<int>> queries)
{
  // ...code
}

int main()
{
  // ...
  return 0;
}