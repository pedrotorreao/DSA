/****************************************************************/
/*Problem: Get Node Value (HR)  ********/
/****************************************************************/
/*
-- Summary:
You’re given the pointer to the head node of a linked list and a specific position. Counting backwards from the tail node of the linked list, get the value of the node at the given position. A position of 0 corresponds to the tail, 1 corresponds to the node before the tail and so on.
-- Input(s):
You have to complete the int getNode(SinglyLinkedListNode* head, int positionFromTail) method which takes two arguments - the head of the linked list and the position of the node from the tail. positionFromTail will be at least 0 and less than the number of nodes in the list.
-- Expected output(s):
Find the node at the given position counting backwards from the tail. Then return the data contained in this node.
-- Constraints:
*/
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode next;
 * }
 *
 */
function getNode(head, positionFromTail) {
  if (head === null) {
    return null;
  }
  let currentNode = head;
  let listData = [];
  while (currentNode !== null) {
    listData.push(currentNode.data);
    currentNode = currentNode.next;
  }
  listData = listData.reverse();

  for (let i = listData.length - 1; i >= 0; i--) {
    if (i === positionFromTail) {
      return listData[i];
    }
  }
}
// ---- How the LL is set up in the rest of the code ----:
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