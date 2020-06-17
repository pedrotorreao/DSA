/****************************************************************/
/*Problem: Print the Elements of a Linked List (HR) ********/
/****************************************************************/
/*
-- Summary:
Given a pointer to the head node of a linked list, print its elements in order, one element per line. If the head pointer is null (indicating the list is empty), don’t print anything.
-- Input(s):
The first line of input contains n, the number of elements in the linked list. The next n lines contain one element each, which are the elements of the linked list.
-- Expected output(s):
Print the integer data for each element of the linked list to stdout/console (e.g.: using printf, cout, etc.). There should be one element per line.
-- Constraints:
*/

// Complete the printLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode next;
 * }
 *
 */
function printLinkedList(head) {
    
  let currentNode = head;
  while (currentNode !== null) {
      console.log(currentNode.data);
      currentNode = currentNode.next;
  }
}