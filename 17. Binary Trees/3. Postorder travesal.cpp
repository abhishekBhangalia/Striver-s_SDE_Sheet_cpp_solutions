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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans; 
        stack<TreeNode*> st;

        while(root or !st.empty()){
            while(root){
                st.push(root);
                root = root->left;
            }
            
            root = st.top()->right;
            if(!root ){
                ans.push_back(st.top()->val);
                root = st.top();
                st.pop();
                while(!st.empty() && root == st.top()->right){
                    ans.push_back(st.top()->val);
                    root = st.top(); 
                    st.pop();
                }
                root = nullptr;

            }
        }
        return ans;
    }
};
