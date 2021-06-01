/****************************************************************/
/*Problem: Inserting a Node Into a Sorted Doubly Linked List (HR)  ********/
/****************************************************************/
/*
-- Summary:
Given a reference to the head of a doubly-linked list and an integer, data, create a new DoublyLinkedListNode object having data value data and insert it into a sorted linked list while maintaining the sort.
-- Input(s):
The function sortedInsert has two parameters:
head: A reference to the head of a doubly-linked list of DoublyLinkedListNode objects.
data: An integer denoting the value of the data field for the DoublyLinkedListNode you must insert into the list.
Note: Recall that an empty list (i.e., where head = null) and a list with one element are sorted lists.
-- Expected output(s):
Your method must return a reference to the head of the same list that was passed to it as a parameter.
-- Constraints:
*/
/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode next;
 *     DoublyLinkedListNode prev;
 * }
 *
 */
function sortedInsert(head, data) {
  let node = new DoublyLinkedListNode(data);
  if (head === null) { 
      head = node;
      return head;
  }
  if (data <= head.data) {
      node.next = head;
      node.prev = null;
      head = node;
      return head;
  }

  let currentNode = head;
  while (currentNode !== null && data >= currentNode.data) {
      if (currentNode.next === null) {
          node.prev = currentNode;
          node.next = null;
          currentNode.next = node;
          return head;
      }
      if (data < currentNode.next.data) {
          node.prev = currentNode;
          node.next = currentNode.next;
          currentNode.next = node;
          return head;
      }
      currentNode = currentNode.next;
  }
}
// ---- How the LL is set up in the rest of the code ----:
/*
const DoublyLinkedListNode = class {
    constructor(nodeData) {
        this.data = nodeData;
        this.next = null;
        this.prev = null;
    }
};

const DoublyLinkedList = class {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    insertNode(nodeData) {
        let node = new DoublyLinkedListNode(nodeData);

        if (this.head == null) {
            this.head = node;
        } else {
            this.tail.next = node;
            node.prev = this.tail;
        }

        this.tail = node;
    }
};

function printDoublyLinkedList(node, sep, ws) {
    while (node != null) {
        ws.write(String(node.data));

        node = node.next;

        if (node != null) {
            ws.write(sep);
        }
    }
}
*/