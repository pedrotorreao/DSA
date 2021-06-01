/****************************************************************/
/*Problem: Delete a Node  ********/
/****************************************************************/
/*
-- Summary:
You’re given the pointer to the head node of a linked list and the position of a node to delete. Delete the node at the given position and return the head node. A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The list may become empty after you delete the node.
-- Input(s):
The first line of input contains an integer n, denoting the number of elements in the linked list.
The next n lines contain an integer each in a new line, denoting the elements of the linked list in the order.
The last line contains an integer position denoting the position of the node that has to be deleted form the linked list.
-- Expected output(s):
Delete the node at the given position and return the head of the updated linked list. The code in the editor will print the updated linked list in a single line separated by spaces.
-- Constraints:
*/
function deleteNode(head, position) {
  if (position === 0) {
    head = head.next;
  } else {
    let currentNode = head;
    for (let i = 0; i < position-1; i++) {
      currentNode = currentNode.next;
    }
    let node = currentNode.next.next;
    currentNode.next = node;
  }
  return head;
}