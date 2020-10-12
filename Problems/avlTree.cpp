/* Node is defined as :
typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    int ht;
} node; */

node * newNode(int val)
{
    node * newNode = new node;
    
    newNode->val = val;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->ht = 0;
    
    return newNode;
}
int getHeight(node* root)
{
    if(root == nullptr) {
        return -1;
    } else {
        return root->ht;
    }
}
node* rightRotate(node* root)
{
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;

    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));
    temp->ht = 1 + max(getHeight(temp->left), getHeight(temp->right));

    return temp;
}
node* leftRotate(node* root)
{
    node* temp = root->right;
    root->right = temp->left;
    temp->left = root;

    root->ht = 1 + max(getHeight(root->left), getHeight(root->right));
    temp->ht = 1 + max(getHeight(temp->left), getHeight(temp->right));

    return temp;
}
node * insert(node * root,int val)
{
    if(root == nullptr) {
        root = newNode(val); 
        return root;
    }
    if(val > root->val) {
        root->right = insert(root->right, val);
    }
    else if(val < root->val) {
        root->left = insert(root->left, val);
    }
    //else{ return 0; }
    
    root->ht = 1 + max(getHeight(root->left),getHeight(root->right));
  
    int balance = getHeight(root->left) - getHeight(root->right);
    
    if(root->left != nullptr && balance > 1) {//Left subtree disbalanced
        if(val < root->left->val) { 
            //Left-Left case: perform a right rotation on the disb. node
            return rightRotate(root);
        }
        else {
            //Left-Right case: perfom a left rotation on the disb. node left subtree
            //and a right rotation on the disb. node
            root->left = leftRotate(root->left);
            return rightRotate(root);

        }
    }
    if(root->right != nullptr && balance < -1) {//Right subtree disbalanced
        if(val > root->right->val) { 
            //Right-Right case: perform a left rotation on the disb. node
            return leftRotate(root);
        }
        else {
            //Right-Left case: perfom a right rotation on the disb. node right subtree
            //and a left rotation on the disb. node
            root->right = rightRotate(root->left);
            return leftRotate(root);
        }
    }
    return root;
}