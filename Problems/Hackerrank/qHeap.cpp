/*********************************************************************************************/
/* Problem: QHeap (HR)  ********/
/*********************************************************************************************/
/*
--Problem statement:
  This question is designed to help you get a better understanding of basic heap operations.
  There are 3 types of query:
    - 1 v:  Add an element 'v' to the heap.
    - 2 v: Delete the element 'v' from the heap.
    - 3: Print the minimum of all the elements in the heap.
  NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any
  instant, only distinct elements will be in the heap.
  > Example 1:
      STDIN       Function
      -----       --------
      5           Q = 5
      1 4         insert 4
      1 9         insert 9
      3           print minimum
      2 4         delete 4
      3           print minimum

--Inputs:
  The first line contains the number of queries, 'Q'. Each of the next 'Q' lines contains one of the
  types of query.

--Output:
  For each query of type 3, print the minimum value on a single line.

--Constraints:
  1<=Q<=10^5
  -10^9<=v<=10^9

--Reasoning:
  Since for each query of type 3, we want to print the minimum element on the heap, we need a min heap.
  For that, we'll use the C++ built-in std::priority_queue<T> class adapted for min heaps, as it is
  by default suited for max heaps. After that, we'll process each type of query in the following way:
    - type 1: just push the new value 'v' to the min heap;
    - type 2: since we only have access to the top element in the min heap, we'd need to compare the top
    element with the value to be removed 'v' and while there's not a match, we'd pop the top element, add it
    to a temporaty storage just so we don't lose the data and push it back to the heap once the correct element
    is found and removed from the heap. In the worst case, this could mean iterating through the whole dataset
    twice, one for finding the element 'v' and another to push the elements popped back into the heap. Instead
    of going through this whole ordeal, we simply add the element removed to a hash set that contains removed
    elements, and then whenever we need the minimum element (query type 3), we just check if it's between the
    removed elements before printing it.
    - type 3: check if the top element in the heap is not among the removed elements; if it is, pop it and check
    the next; if it is not, print it.

--Time complexity: O(log n)

--Space complexity: O(n), where n is the number of elements added to the heap;

*/

#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int numOfQueries;

  std::cin >> numOfQueries;

  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  std::unordered_set<int> removed;

  for (int i{0}; i < numOfQueries; i++) {
    int query{0}, value{0};

    std::cin >> query;

    switch (query) {
    // add 'value' to the heap:
    case 1: {
      std::cin >> value;
      pq.push(value);
      break;
    }
    // remove 'value' from the heap:
    case 2: {
      std::cin >> value;
      removed.insert(value);
      break;
    }
    // print min value from the heap:
    case 3: {
      int min;
      while (true) {
        min = pq.top();
        // checks if top elements is not among the removed elements:
        if (removed.count(min) == 0)
          break;
        pq.pop();
      }
      std::cout << min << "\n";
      break;
    }
    }
  }
  return 0;
}