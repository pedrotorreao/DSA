/****************************************************************/
/*Problem: Reverse a Linked List (HR) ********/
/****************************************************************/
/*
-- Summary:
You’re given the pointer to the head node of a linked list. Change the next pointers of the nodes so that their order is reversed. The head pointer given may be null meaning that the initial list is empty. You have to complete the SinglyLinkedListNode reverse(SinglyLinkedListNode head) method which takes one argument.
-- Input(s):
head: a SinglyLinkedListNode pointer to the head of the list
-- Expected output(s):
Change the next pointers of the nodes that their order is reversed and return the head of the reversed linked list. 
-- Constraints:
*/
/*
const SinglyLinkedListNode = class {
  constructor(nodeData) {
      this.data = nodeData;
      this.next = null;
  }
};

const SinglyLinkedList = class {
  constructor() {
      this.head = null;
      this.tail = null;
  }

  insertNode(nodeData) {
      const node = new SinglyLinkedListNode(nodeData);

      if (this.head == null) {
          this.head = node;
      } else {
          this.tail.next = node;
      }

      this.tail = node;
  }
};

function printSinglyLinkedList(node, sep, ws) {
  while (node != null) {
      ws.write(String(node.data));

      node = node.next;

      if (node != null) {
          ws.write(sep);
      }
  }
}
*/
// Complete the insertNodeAtPosition function below.

/*
* For your reference:
*
* SinglyLinkedListNode {
*     int data;
*     SinglyLinkedListNode next;
* }
*
*/
function reverse(head) {
  if (!head.next) {
      return head;
  }
  let first = head;
  let second = first.next;
  while(second) {
      const temp = second.next;
      second.next = first;
      first = second;
      second = temp;
  }
  head.next = null;
  head = first;
  return head;
 
 }