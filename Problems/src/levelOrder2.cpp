/****************************************************************/
/*Problem: Tree - Level order Traversal (HR)  ********/
/****************************************************************/
/*
-- Summary:
You are given a pointer to the root of a binary tree. You need to print the level order traversal of this tree. In level order traversal, we visit the nodes level by level from left to right. 
-- Input(s):
Our hidden tester code passes the root node of a binary tree to your levelOrder function.
-- Expected output(s):
Print the values in a single line separated by a space.
-- Constraints:
1 <= Nodes in the tree <= 500
*/
/* ----------- Rest of the code for context ------------: 
#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	  Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
                }

                return root;
            }
      }
*/
//levelOrder() is a method of the Solution class
//Level order traversal: //1st level --> 2nd level --> 3rd level ...

void levelOrder(Node *root)
{
  vector<Node *> q; // could use a STL queue here, but I don't remember :P

  if (root != nullptr)
  {
    q.push_back(root);
    while (q.size())
    {
      Node *current = q.at(0);           // dequeue
      q.erase(q.begin(), q.begin() + 1); //get rid of vec(0)

      std::cout << current->data << " ";

      if (current->left)
        q.push_back(current->left);
      if (current->right)
        q.push_back(current->right);
    }
  }
}

//}; //End of Solution

/* ----------- main() function ------------: 
int main() {
Solution myTree;
Node* root = NULL;

int t;
int data;

std::cin >> t;

while(t-- > 0) {
std::cin >> data;
root = myTree.insert(root, data);
}

myTree.levelOrder(root);
return 0;
}
*/