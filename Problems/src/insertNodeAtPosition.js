/****************************************************************/
/*Problem: Insert a node at a specific position in a LL (HR)  ***/
/****************************************************************/
/*
-- Summary:
You’re given the pointer to the head node of a linked list, an integer to add to the list and the position at which the integer must be inserted. Create a new node with the given integer, insert this node at the desired position and return the head node. A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The head pointer given may be null meaning that the initial list is empty.
-- Input(s):
head: a SinglyLinkedListNode pointer to the head of the list
data: an integer value to insert as data in your new node
position: an integer position to insert the new node, zero based indexing
-- Expected output(s):
Return a reference to the list head.
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
function insertNodeAtPosition(head, data, position) {
  let node = new SinglyLinkedListNode(data);
    if (head === null) {
        head = node;
    } else {
        let currentNode = head;
        for (let i = 0; i < position-1; i++) {
            currentNode = currentNode.next;
        }
        node.next = currentNode.next;
        currentNode.next = node;
    }
    return head;
}