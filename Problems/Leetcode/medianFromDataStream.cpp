/**************************************************************************************/
/* Problem: LC 295. Find Median from Data Stream             **************************/
/**************************************************************************************/
/*
--Problem statement:
  The median is the middle value in an ordered integer list. If the size of  the list is
  even, there is no middle value, and the median is the mean of the two middle values.
    For example, for arr = [2,3,4], the median is 3.
    For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.

  Implement the MedianFinder class:
    - MedianFinder() initializes the MedianFinder object.
    - void addNum(int num) adds the integer num from the data stream to the data structure.
    - double findMedian() returns the median of all elements so far. Answers within 10-5 of
    the actual answer will be accepted.

  > Example 1:
  Input:
    ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
    [[], [1], [2], [], [3], []]
  Output
    [null, null, null, 1.5, null, 2.0]
  Explanation
    MedianFinder medianFinder = new MedianFinder();
    medianFinder.addNum(1);    // arr = [1]
    medianFinder.addNum(2);    // arr = [1, 2]
    medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    // arr[1, 2, 3]
    medianFinder.findMedian(); // return 2.0

--Input:
  int: a stream of integers.
--Output:
  double: the median of the data stream.

--Constraints:
    :: -10^5 <= num <= 10^5
    :: There will be at least one element in the data structure before calling 'findMedian'
    :: At most (5 * 10^4) calls will be made to 'addNum' and 'findMedian'.

--Reasoning:
  1. We'll keep the data sorted, this way we are always able to tell where the 'median' is. Since
  the data will be sorted, we know that the 'median' splits the data into two subsets, one containing
  elements smaller than the median, and the other containing elements greater than the median.

  2. If we were to keep the data in an array, "findMedian" would have a O(1) runtime since we'd know
  exactly where to find the 'median' based on the array size at the time "findMedian" is called. However,
  adding new elements would possibly require shifting a good portion of the elements already present
  in the array in order to add the new value in the correct position that'd keep the array sorted, this
  would have a O(N) runtime for every insertion.

  3. To improve this runtime for insertions, we'll keep two lists, each one containing approximately half
  the total number of elements. One of these lists would have all the elements <= to the median and the
  other all the elements >= median. For these lists, we'll use two heaps:
      -> Max Heap "smaller": elements <= median
      -> Min Heap "greater": elements >= median

  4. These heaps will keep the data ordered and the 'median' will be given either by the top element of the
  larger heap (in case of odd total size), or by the mean of the top elements of both heaps.

--Time complexity:
    -> 'addNum': O(log N), inserting/removing elements from a heap is O(log N), where is the
    size of the larger heap.
    -> 'findMedian': O(1), it's just a matter of looking up the top element in the heaps.

--Space complexity: O(N), due to the heaps used to store the data.
*/

#include <iostream>
#include <queue>

class MedianFinder {
private:
  bool isUpToDate;
  double median;
  std::priority_queue<int, std::vector<int>, std::greater<int>> greater; // higher values
  std::priority_queue<int> smaller;                                      // lower values
public:
  MedianFinder() {
    this->isUpToDate = false;
    this->median = 0.0;
  }

  void addNum(int num) {
    // By default, add the first element to the lower heap:
    if (smaller.empty()) {
      smaller.push(num);
      return;
    }

    /*
        Keep the heaps are balanced. Remember: the heaps are balanced if the difference in sizes is no greater than 1.
        If the insertion of 'num' would make the heaps unbalanced, move elements around so the size difference is at most 1.
    */
    if (smaller.size() > greater.size()) {
      /*
          The heap 'smaller' is bigger, check if its max element, 'smaller.top()', is greater than the element being added, 'num'.
          If so, adding 'num' to 'greater' would make the data be unsorted, so we move its max value to the 'greater' heap to make room
          for 'num'. This way, the data remains sorted and the difference in size between the heaps is still 1.
      */
      if (smaller.top() > num) {
        greater.push(smaller.top());
        smaller.pop();
        smaller.push(num);
      }
      /*
          Otherwise, we can safely add 'num' to the heap 'greater'. This way, the data remains sorted and the difference in size
          between the heaps is now 0.
      */
      else
        greater.push(num);
    } else {
      /*
          The heap 'greater' is bigger, check if its min element, 'greater.top()', is smaller than the element being added, 'num'.
          If so, adding 'num' to 'smaller' would make the data be unsorted, so we move its min value to the 'smaller' heap to make room
          for 'num'. This way, the data remains sorted and the difference in size between the heaps is still 1.
      */
      if (greater.top() < num) {
        smaller.push(greater.top());
        greater.pop();
        greater.push(num);
      }
      /*
          Otherwise, we can safely add 'num' to the heap 'smaller'. This way, the data remains sorted and the difference in size
          between the heaps is now 0.
      */
      else
        smaller.push(num);
    }

    isUpToDate = false;
  }

  double findMedian() {
    if (isUpToDate)
      return median;

    /*
        If heaps are of the same size, we have an even total size, so the median will be the average between the two intermediary values,
        which are the max value of 'smaller' and the min value of 'greater'.
    */
    if (smaller.size() == greater.size())
      median = smaller.top() + ((greater.top() - smaller.top()) / 2.0); // Avoid integer overflow in the sum in case values are to high.
    /*
        Otherwise, the median will be the .top() value in the bigger size.
    */
    else if (smaller.size() > greater.size())
      median = smaller.top();
    else
      median = greater.top();

    isUpToDate = true;

    return median;
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
  MedianFinder *obj = new MedianFinder();

  obj->addNum(1);
  obj->addNum(2);
  std::cout << "Median: " << obj->findMedian() << "\n";

  obj->addNum(3);
  std::cout << "Median: " << obj->findMedian() << "\n";

  return 0;
}