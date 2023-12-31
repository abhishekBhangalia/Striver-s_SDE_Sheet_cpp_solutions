/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/
// TC-O(n), SC-O(h)
bool isParentSum(Node *root){
    // Write your code here.
    if(root){
        if(root->left == NULL and root->right == NULL){
            return true;
        }
        int child_sum = 0;
        if(root->left){
            child_sum += root->left->data;
        }
        if(root->right){
            child_sum += root->right->data;
        }
        if(child_sum != root->data) return false;
        return isParentSum(root->left) and isParentSum(root->right);
    }
    return true;
}
