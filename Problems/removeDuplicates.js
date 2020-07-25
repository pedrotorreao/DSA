/****************************************************************/
/*Problem: Delete duplicate-value nodes from a sorted linked list  ********/
/****************************************************************/
/*
-- Summary:
You're given the pointer to the head node of a sorted linked list, where the data in the nodes is in ascending order. Delete as few nodes as possible so that the list does not contain any value more than once.
-- Input(s):
You have to complete the SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) method which takes one argument - the head of the sorted linked list.
-- Expected output(s):
Delete as few nodes as possible to ensure that no two nodes have the same data. Adjust the next pointers to ensure that the remaining nodes form a single sorted linked list. Then return the head of the sorted updated linked list.
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
function removeDuplicates(head) {
  if (head === null) { return null; }

  let currentNode = head;
  let map = {};
  let lldata = [];

  while(currentNode !== null) {
      if (!map[currentNode.data]) {
          lldata.push(currentNode.data);
          map[currentNode.data] = true;
      }
      currentNode = currentNode.next;
  }

  let ll = new SinglyLinkedList();
  for (let i = 0; i < lldata.length; i++) {
    ll.insertNode(lldata[i]);
  }
  return ll.head;
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