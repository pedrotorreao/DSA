/****************************************************************/
/*Problem: Cycle Detection (HR) ********/
/****************************************************************/
/*
-- Summary:
A linked list is said to contain a cycle if any node is visited more than once while traversing the list. Complete the function provided for you in your editor. It has one parameter: a pointer to a Node object named head that points to the head of a linked list. Your function must return a boolean denoting whether or not there is a cycle in the list. If there is a cycle, return true; otherwise, return false.
-- Input(s):
HR default.
-- Expected output(s):
If the list contains a cycle, your function must return true. If the list does not contain a cycle, it must return false. 
-- Constraints:
*/
//C++ solution found based on Floyd's Cycle Detection Algorithm. Essentialy, one of the pointers (currentNodeFast) moves 2 steps at a time while the other pointer (currentNodeSlow) moves one step at a time, e.g., currentNodeFast moves with twice the speed of currentNodeSlow. If there is a cycle, the pointers will meet each other at some point along the traversal.

bool has_cycle(SinglyLinkedListNode* head) {
    if (head == nullptr) {
        return 0;
    }

    SinglyLinkedListNode* currentNodeFast = head;
    SinglyLinkedListNode* currentNodeSlow = head;
    
    while (currentNodeFast != nullptr && currentNodeFast->next != nullptr) {
        currentNodeSlow = currentNodeSlow->next;
        currentNodeFast = currentNodeFast->next->next;

        if (currentNodeSlow == currentNodeFast) {
            return 1;
        }
    }
    return 0;
}

// JS solution to be validated later since the HR Node code is broken:
/*
function hasCycle(head) {
  //if (head.next === null) {return 0;}
  let map = {};
  let currentNode = head;
  while(currentNode !== null && currentNode.next !== null) {
      if (map[currentNode] === currentNode.next) {
          return 1;
      }
      map[currentNode] = currentNode.next;
      currentNode = currentNode.next;
  }
  return 0;

}
*/

/* Other approaches:
* 1- Hashing: Traverse the list one by one and keep putting the node addresses in a Hash Table. At any point, if NULL is reached then * return false and if next of current node points to any of the previously stored nodes in Hash then return true.
* 2- Flagging: Have a visited flag with each node. Traverse the linked list and keep marking visited nodes. If you see a visited node * again then there is a loop. This solution works in O(n) but requires additional information with each node.
*/