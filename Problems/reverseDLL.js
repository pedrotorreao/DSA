/****************************************************************/
/*Problem: Reverse a doubly linked list (HR)  ********/
/****************************************************************/
/*
-- Summary:
You’re given the pointer to the head node of a doubly linked list. Reverse the order of the nodes in the list. The head node might be NULL to indicate that the list is empty. Change the next and prev pointers of all the nodes so that the direction of the list is reversed. Return a reference to the head node of the reversed list.
-- Input(s):
reverse has the following parameter(s):
head: a reference to the head of a DoublyLinkedList
-- Expected output(s):
Return a reference to the head of your reversed list. 
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
function reverseDLL(head) {
  if (!head.next) {
    return head;
  }
  let first = head;
  let second = first.next;
  let temp2 = null;

  while(second) {
    const temp1 = second.next;

    temp2 = first;
    second.next = first;
    second.prev = temp1;
  
    first = second;
    second = temp1;
  }
  head.next = null;
  head.prev = temp2;
  head = first;

  return head;
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