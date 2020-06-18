/****************************************************************/
/*Problem: Insert a node at the head of a linked list  ********/
/****************************************************************/
/*
-- Summary:
Create a new node with the given integer. Insert this node at the head of the linked list and return the new head node of the linked list formed after inserting this new node. The given head pointer may be null, meaning that the initial list is empty.
-- Input(s):
You have to complete the SinglyLinkedListNode insertNodeAtHead(SinglyLinkedListNode head, int data) method. It takes two arguments: the head of the linked list and the integer to insert at tail. The first line contains an integer n, denoting the elements of the linked list. The next n lines contain an integer each, denoting the element that needs to be inserted at tail.
-- Expected output(s):
Insert the new node at the head and just return the head of the updated linked list. 
-- Constraints:
*/
/*
-- Classes & Functions available:
const SinglyLinkedListNode = class {
    constructor(nodeData) {
        this.data = nodeData;
        this.next = null;
    }
};
const SinglyLinkedList = class {
    constructor() {
        this.head = null;
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
-- Main:
function main() {
    const ws = fs.createWriteStream(process.env.OUTPUT_PATH);

    const llistCount = parseInt(readLine(), 10);

    let llist = new SinglyLinkedList();

    for (let i = 0; i < llistCount; i++) {
      const llistItem = parseInt(readLine(), 10);
      const llist_head = insertNodeAtTail(llist.head, llistItem);
      llist.head = llist_head;
    }

    printSinglyLinkedList(llist.head, '\n', ws);
    ws.write('\n');

    ws.end();
}
*/
// Complete the insertNodeAtHead function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode next;
 * }
 *
 */
function insertNodeAtHead(head, data) {
  let node = new SinglyLinkedListNode(data);

  if (head === null) {
      head = node;
  } else {
      node.next = head;
      head = node;
  }

  return head;
}