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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> a;
        if(!root) return a;
        
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* t = st.top();
        while(!st.empty()){
            
            if(t){
                st.push(t);
                a.push_back(t->val);
                t = t->left;
            }
            else{
                t = st.top()->right;
                st.pop();
            }
            // if(st.empty())
            //     break;

            // if(t){
            //     a.push_back(t->val);
            //     if(t->left){
            //         t = t->left;
            //         st.push(t);
            //     }
            //     else if(t->right){
            //         t = t->right;
            //         st.push(t);
            //     } 
            // }
            // else {
            //     t = st.top()->right;
            //     st.pop();
            // }

           
        }
        return a;
    }
};
