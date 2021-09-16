/****************************************************************/
/*Problem: Compare two linked lists (HR) ********/
/****************************************************************/
/*
-- Summary:
You’re given the pointer to the head nodes of two linked lists. Compare the data in the nodes of the linked lists to check if they are equal. The lists are equal only if they have the same number of nodes and corresponding nodes contain the same data. 
-- Input(s):
You have to complete the int CompareLists(Node* headA, Node* headB) method which takes two arguments - the heads of the two linked lists to compare.
-- Expected output(s):
Compare the two linked lists and return 1 if the lists are equal. Otherwise, return 0. 
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
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode next;
 * }
 *
 */
//Solution accepted:
function CompareLists(llist1, llist2) {
  let mapL1 = [], mapL2 = [];
  let currentNode = llist1;

  while (currentNode !== null) {
    mapL1.push(currentNode.data);
    currentNode = currentNode.next;
  }

  currentNode = llist2;
  while (currentNode !== null) {
    mapL2.push(currentNode.data);
    currentNode = currentNode.next;
  }

  if (mapL1.length !== mapL2.length) {return 0;}

  for (let i = 0; i < mapL1.length; i++) {
      if (mapL1[i] !== mapL2[i]) {return 0;}
  }
  return 1;
}

//Better solution IMO:
// function CompareLists(llist1, llist2) {
//   let map = {};
//   let currentNode = llist1.head;
//   while (currentNode !== null) {
//     map[currentNode.data] = true;
//   }
//   currentNode = llist2.head;
//   while (currentNode !== null) {
//     if (!map[currentNode.data]) {
//       return 0;
//     }
//   }
//   return 1;
// }