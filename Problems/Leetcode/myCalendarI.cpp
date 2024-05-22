/***
Problem: LC 729. My Calendar I
(https://leetcode.com/problems/my-calendar-i/description/)

--Problem statement:
  You are implementing a program to use as your calendar. We can add a new event if adding the event will not
  cause a double booking. A double booking happens when two events have some non-empty intersection (i.e.,
  some moment is common to both events.).

  The event can be represented as a pair of integers start and end that represents a booking on the half-open
  interval [start, end), the range of real numbers x such that start <= x < end.

  Implement the MyCalendar class:
    - MyCalendar(): Initializes the calendar object.
    - boolean book(int start, int end): Returns true if the event can be added to the calendar successfully without
    causing a double booking. Otherwise, return false and do not add the event to the calendar.

  > Example 1:
      Input: ["MyCalendar", "book", "book", "book"] -> [[], [10, 20], [15, 25], [20, 30]]
      Output: [null, true, false, true]
      Explanation:
        MyCalendar myCalendar = new MyCalendar();
        myCalendar.book(10, 20);
          // return True
        myCalendar.book(15, 25);
          // return False, It can not be booked because time 15 is already booked by another event.
        myCalendar.book(20, 30);
          // return True, The event can be booked, as the first event takes every time less than 20, but not including 20.

--Inputs:
  int: two integers representing the star and end of the possible booking.

--Output:
  boolean: whether the new booking can be added to the calendar or not.

--Constraints:
    :: 0 <= start < end <= 109
    :: At most 1000 calls will be made to book.

--Time complexity:
    O(log(N)), where is the size of the input array, since searching and inserting in the ordered set have an average
    time complexity of O(log n).

--Space complexity:
    O(N), due to the space allocated for the ordered set in the worst case that all bookings are possible.

*/
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

class MyCalendar {
  // events are ordered by starting time:
  std::set<std::pair<int, int>> bookings;

public:
  MyCalendar() {}

  bool book(int start, int end) {
    // get the closest event imediate after to the one being added, by starting time (equal or greater):
    auto adjacentBookingItr = bookings.lower_bound({start, end});

    // overlap with next booking:
    if (adjacentBookingItr != bookings.end() && adjacentBookingItr->first < end) {
      return false;
    }

    // overlap with previous booking:
    if (adjacentBookingItr != bookings.begin() && (--adjacentBookingItr)->second > start) {
      return false;
    }

    // no overlap, book new event:
    bookings.insert({start, end});
    return true;
  }
};

int main() {
  std::cout << std::boolalpha;

  MyCalendar calendar;

  bool isTimeAvailable = false;

  isTimeAvailable = calendar.book(10, 20);
  std::cout << "-- ADDED (10, 20): " << isTimeAvailable << "\n";

  isTimeAvailable = calendar.book(15, 25);
  std::cout << "-- ADDED (15, 25): " << isTimeAvailable << "\n";

  isTimeAvailable = calendar.book(20, 30);
  std::cout << "-- ADDED (20, 30): " << isTimeAvailable << "\n";

  return 0;
}