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