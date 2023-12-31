/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        findSmallNodes(root,k,st);
        while(!st.empty()){
            int t = k-st.top()->val;
        
            if(find(root,t,st.top())){
                return true;
            }
            st.pop();
        }
        return false;
    }
    
    void findSmallNodes(TreeNode* root, int k, stack<TreeNode*>& st){
        
        if (root == nullptr )   return;
        //if(root->val>=k){
           // findSmallNodes(root->left,k,st);
       // }
       // else {
            st.push(root);
            findSmallNodes(root->left,k,st);
            findSmallNodes(root->right,k,st);
       // }
        
    }
    
    bool find(TreeNode* root, int v,TreeNode* n1){
    
        while(root){
            if(root->val == v and root != n1){
                return true;
            }
            else if(root->val > v){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        return false;
    }
};
