/*********************************************************************************************/
/* Problem: Hackerland Radio Transmitters (HR) ********/
/*********************************************************************************************/
/*
--Problem statement:
  Hackerland is a one-dimensional city with houses aligned at integral locations along a road.
  The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter
  has a fixed range meaning it can transmit a signal to all houses within that number of units
  distance away.

  Given a map of Hackerland and the transmission range, determine the minimum number of
  transmitters so that every house is within range of at least one transmitter. Each transmitter
  must be installed on top of an existing house.
    > Example:
        Input: x=[1,2,3,5,9]  k=1
        Output: 3
        Explanation: 3 antennas at houses 2, 5 and 9 provide complete coverage.

    > Example:
        Input: x=[7,2,4,6,5,9,12,11]  k=2
        Output: 3
        Explanation: We can cover the entire city with 3 transmitters on houses 4, 9 and 12.

--Inputs:
  -int x[n]: the locations of houses
  -int k: the effective range of a transmitter

--Output:
  -int: the minimum number of transmitters to install

--Constraints:
    1 <= n,k <= 10^5
    1 <= x[i] <= 10^5

--Reasoning: see comments below.

--Time complexity: O(n*log(n)), due to the ordered set, where 'n' is the size of the array 'x'.

--Space complexity: O(n), due to space allocated for the ordered set, where 'n' is the size of the array 'x'.

*/

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int hackerlandRadioTransmitters(std::vector<int> x, int k) {
  std::set<int> hs;
  // add all the houses to an ordered set to make sure that
  // the they are in order:
  for (const auto &i : x)
    hs.insert(i);

  auto itr = hs.begin();
  int numOftransmitters{0};

  while (itr != hs.end()) {
    ++numOftransmitters;
    // furthest possible location that the current transmitter covers:
    int range = *itr + k;
    // previous coverable limit, it holds the last coverable
    // position for the current transmitter:
    int prevTransmitter = *itr;
    // go as far as possible to the right inside the coverable range and
    // find the middle position for which (middle-left <= k):
    while (itr != hs.end() && *itr <= range) {
      // update the last coverable position:
      prevTransmitter = *itr;
      // advance:
      ++itr;
    }
    // at this point, all houses to the left of 'prevTransmitter' are inside
    // the 'range' of the current transmitter. Now, update the 'range' so we
    // can take into account also all the houses to the right that are coverable:
    range = prevTransmitter + k;
    // go as far as the rightmost coverable position (right-middle<=k):
    while (itr != hs.end() && *itr <= range) {
      ++itr;
    }
  }

  return numOftransmitters;
}

int main() {
  std::vector<int> vec{7, 2, 4, 6, 5, 9, 12, 11};
  int k{2};
  std::cout << "Min. # of transmitters: " << hackerlandRadioTransmitters(vec, k) << "\n"; // 3

  vec = {1, 2, 3, 4, 5};
  k = 1;
  std::cout << "Min. # of transmitters: " << hackerlandRadioTransmitters(vec, k) << "\n"; // 2

  vec = {1, 3, 5, 6, 9, 11};
  k = 1;
  std::cout << "Min. # of transmitters: " << hackerlandRadioTransmitters(vec, k) << "\n"; // 5

  vec = {7, 2, 4, 6, 5, 9, 12, 11};
  k = 3;
  std::cout << "Min. # of transmitters: " << hackerlandRadioTransmitters(vec, k) << "\n"; // 2

  return 0;
}