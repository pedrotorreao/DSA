/****************************************************************/
/*Problem: Merge two sorted linked lists (HR)  ********/
/****************************************************************/
/*
-- Summary:
You’re given the pointer to the head nodes of two sorted linked lists. The data in both lists will be sorted in ascending order. Change the next pointers to obtain a single, merged linked list which also has data in ascending order. Either head pointer given may be null meaning that the corresponding list is empty.
-- Input(s):
You have to complete the SinglyLinkedListNode MergeLists(SinglyLinkedListNode headA, SinglyLinkedListNode headB) method which takes two arguments - the heads of the two sorted linked lists to merge.
-- Expected output(s):
Change the next pointer of individual nodes so that nodes from both lists are merged into a single list. Then return the head of this merged list.
-- Constraints:
*/
// ---- How the LL is set up in the rest of the code ----:
/*
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
function mergeLists(head1, head2) {
  //working solution:
  //check for empty lists:
  if ((head1 === null) || (head2 === null)) {
    if (head1 === null) {
      return head2;
    } else {
      return head1;
    }
  }
  //map LL1 into array map1:
  let length1 = 0, currentNode1 = head1, map1 = [];
  while(currentNode1 !== null) {
    map1.push(currentNode1.data);
    currentNode1 = currentNode1.next;
  }
  //map LL1 into array map2:
  let length2 = 0, currentNode2 = head2, map2 = [];
  while(currentNode2 !== null) {
    map2.push(currentNode2.data);
    currentNode2 = currentNode2.next;
  }

  let llist3 = new SinglyLinkedList();
  let map3 = [], i = 1, j = 1, map1Item = map1[0], map2Item = map2[0];
  while (map1Item || map2Item) {
    if (map2Item == undefined || map1Item < map2Item) {
      llist3.insertNode(map1Item);
      map1Item = map1[i];
      i++;
    } else {
      llist3.insertNode(map2Item);
      map2Item = map2[j];
      j++;
    }
  }
  return llist3.head;
}
// Solution that, for some reason, is not working:
// let llist3 = new SinglyLinkedList();
// let temp1 = head1, temp2 = head2;
// while (temp1 !== null || temp2 !== null) {
//     if (temp1 === null || temp2 === null) {
//         if (temp1 === null) {
//             llist3.insertNode(temp2.data);
//             temp2 = temp2.next;
//         } else {
//             llist3.insertNode(temp1.data);
//             temp1 = temp1.next;
//         }
//     }
//     if (temp1.data < temp2.data) {
//         llist3.insertNode(temp1.data);
//         temp1 = temp1.next;
//     } else {
//         llist3.insertNode(temp2.data);
//         temp2 = temp2.next;
//     }
// }
// return llist3;