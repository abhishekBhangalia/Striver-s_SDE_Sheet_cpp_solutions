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
    
    // Inorder Traversal

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        if(root==nullptr) return in;

        TreeNode* cur = root;
        
        while(cur!=nullptr){
            if(cur->left == nullptr){
                in.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* tmp = cur->left;
                while(tmp->right and tmp->right!=cur){
                    tmp = tmp->right;
                }
                if(tmp->right == cur){
                    tmp->right = nullptr;
                    in.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    tmp->right = cur;
                    cur = cur->left;
                }
            }
        }
        return in;
    }
};
