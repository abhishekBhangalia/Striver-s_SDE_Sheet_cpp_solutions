/********************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode {
        public :
        int data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    
********************************************************************/

//TC-O(n), SC-O(n)
void rec(BinaryTreeNode<int>* node, string s, vector<string>& ans){
    s += to_string(node->data)+' ';

    if(node->left){
        rec(node->left, s, ans);
    }
    if(node->right){
        rec(node->right, s, ans);
    }
    if(node->left == NULL and node->right == NULL){
        ans.push_back(s);
    }
}

vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    vector<string> ans;
    if(root)    rec(root, "", ans);
    return ans;
}
