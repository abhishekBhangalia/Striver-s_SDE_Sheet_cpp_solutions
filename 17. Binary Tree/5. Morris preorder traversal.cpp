#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

void morrisPreOrderTraversal(TreeNode* root, vector<int>& ans){
    if(root == NULL)    return;

    
    //if left child is null then call for right child
    if(root->left == NULL)    {
        ans.push_back(root->data);
        return morrisPreOrderTraversal(root->right,ans);
    }

    //check if thread is already there or not
    TreeNode* right_most_child = root->left;

    while(right_most_child->right != NULL and right_most_child->right != root){
        right_most_child = right_most_child->right;
    }
    
    if(right_most_child->right == root){// if thread is already there, then disconnect it and call for right child
        right_most_child->right = NULL;
        morrisPreOrderTraversal(root->right, ans);
    }
    else{//if thread is not there, then connect thread from rightmost child of root to root. and then print root's data and then call for left child
        right_most_child->right = root;
        ans.push_back(root->data);
        morrisPreOrderTraversal(root->left, ans);
    }
}


vector<int> getPreOrderTraversal(TreeNode *root)
{
    vector<int> ans;
    morrisPreOrderTraversal(root, ans);
    return ans;
}

