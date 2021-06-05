## Activity Selection Problem

Check out the code for the solution [here](/Algorithms/Greedy/Activity%20Selection/activitySelection.js).

### Problem Statement

Given a set of `N` activities each marked by a start time (`si`) and finish time (`fi`), the problem is to select the maximum number of activities that can be performed by a single person or machine, assuming that a person can only work on a single activity at a time. So, if we have two activities `i` and `j`, they are considered to be non-conflicting if `si ≥ fj` (activity `i` only starts once activity `j` is finished) or `sj ≥ fi` (activity `j` only starts once activity `i` is finished). The activity selection problem consists in finding the largest solution set of non-conflicting activities.

### Example

Given the activities below and their corresponding start and finish times, determine the maximum number of non-overlapping activities that can be performed.

| activity |  A  |  B  |  C  |  D  |  E  |  F  |
| :------: | :-: | :-: | :-: | :-: | :-: | :-: |
|  start   |  0  |  5  |  1  |  3  |  8  |  5  |
|  finish  |  6  |  9  |  2  |  4  |  9  |  7  |

A brute force approach would require us to try out all the possible combinations of activities in order to find the best solution. A better alternative would be to use a greedy approach. This approach consists of the following steps:

1.  Sort all activities according to their finishing time in non-descending order. Structuring the activities' set above in an array in which each element is of the form `[activity, start, finish]`, we would have the following:

    > original: `[[A,0,6], [B,5,9], [C,1,2], [D,3,4], [E,8,9], [F,5,7]]`
    >
    > sorted: `[[C,1,2], [D,3,4], [A,0,6], [F,5,7], [E,8,9], [B,5,9]]`

2.  Select the the activity with the earliest finishing time. The reason for this is that this choice leaves us with as much time as possible to fit othere activities, that is, the greedy choice is the one that maximizes the amount of unscheduled time remaining.
    > first activity: `[C,1,2]`
3.  For the remaining activities, iterate over the sorted array and check if the finishing time of the current activity being looked at is greater than or equal to the starting time of the previous activity, if so, add it to the solution.

### Pseudocode

```
activitySelection(activities):
    > sort activities based on their finishing time:
        sorted_activities = sort(activities)
    > select the activity w/ the earliest finishing time:
        first_activity = sorted_activities[0]
    > add it to the solution:
        solution.push(first_activity)
    > keep track of the last activity added to the solution:
        previous = first_activity
    > iterate over the sorted_activities array:
        for i = 1 to i = n-1:
            if start time of current activity > finish time of previous:
                solution.push(current activity)
                previous = current activity
            endif
        endfor
end function
```

### Time Complexity

- O(n\*log(n)) - considering that the activities array is not sorted and an algorithm like quick sort was used to sort it.

### Space Complexity

- O(n) - due to the sorted array, if we don't want to modify the input.

### [Data Structures & Algorithms - Index](../../../README.md)
