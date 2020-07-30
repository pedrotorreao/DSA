/****************************************************************/
/*Problem: Find Merge Point of Two Lists (HR)  ********/
/****************************************************************/
/*
-- Summary:
Given pointers to the head nodes of  linked lists that merge together at some point, find the Node where the two lists merge. It is guaranteed that the two head Nodes will be different, and neither will be NULL.
-- Input(s):
The findMergeNode(SinglyLinkedListNode,SinglyLinkedListNode) method has two parameters, head1 and head2, which are the non-null head Nodes of two separate linked lists that are guaranteed to converge.
-- Expected output(s):
Complete the int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) method so that it finds and returns the data value of the Node where the two lists merge.
-- Constraints:
*/
function findMergeNode(headA, headB) {
  let currentNodeA = headA;
  let currentNodeB = headB;

  while (currentNodeA !== currentNodeB) {
      if (currentNodeA.next === null) {
          currentNodeA = headB;
      } else {
          currentNodeA = currentNodeA.next;
      }

      if (currentNodeB.next === null) {
          currentNodeB = headA;
      } else {
          currentNodeB = currentNodeB.next;
      }
  }
  return currentNodeB.data;
}
/*
-- Explanation:
Say listA is x long and merges at j. And the other listB is y long and merges at k.
One iterator will take j steps to hit the merge point in listA, then (x-j) steps to hit the end of listA, then it will go to the listB and take k steps to hit its merge point. Total1 = j + (x-j) + k.
The other iterator will take k steps to hit the merge point of listB and (y-k) to hit the end of listB, then will go to the listA and take j steps to hit its merge point. Total2 = k + (y-k) + j.
Since the second part of both lists is the same sequence, (x-j) is the same as (y-k). Call that number q. Plugging that into both totals gives (j + q + k) for the first and (k + q + j) for the second. Which are obviously equal. So both iterators travel the same amount of steps in other to get to the merge points in both lists. Example:
llA: 1-->2-->7-->3-->11-->NULL
llB: 6-->10-->11-->NULL
merge:
1--2--7--3
          \
          11--NULL
          /
    6--10  
Iterator 1: 1--2--7--3--11--(NULL)--6--10--11
Iterator 2: 6--10--11--(NULL)--1--2--7--3--11

Both iterators got to the merge point (11) in both lists in the same number of steps (9, counting NULL):
Total1 = j + (x-j) + k = 5 + (6-5) + 3 = 9
Total2 = k + (y-k) + j = 3 + (4-3) + 5 = 9
*/