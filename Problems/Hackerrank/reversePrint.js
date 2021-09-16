/****************************************************************/
/*Problem: Print in Reverse (HR)  ********/
/****************************************************************/
/*
-- Summary:
Given a pointer to the head node of a linked list, and you need to print all its elements in reverse order from tail to head, one element per line. If the head pointer is null (indicating the list is empty), don’t print anything.
-- Input(s):
The first line of input contains n, the number of elements in the linked list. The next n lines contain one element each, which are the elements of the linked list.
-- Expected output(s):
Complete the reversePrint function in the editor below and print the elements of the linked list in the reverse order, each in a new line.
-- Constraints:
*/
/*
-- For your reference:
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

function printSinglyLinkedList(node, sep) {
    while (node != null) {
        process.stdout.write(String(node.data));

        node = node.next;

        if (node != null) {
            process.stdout.write(sep);
        }
    }
}

 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode next;
 * }

*/
function reversePrint(head) {
  let currentNode = head;
  let arr = [];
  if (head === null) {
    return;
  }
  while (currentNode !== null) {
    arr.push(currentNode.data);
    currentNode = currentNode.next;
  }
  for (let i = arr.length - 1; i >= 0; i--) {
    console.log(arr[i]);
  }
}