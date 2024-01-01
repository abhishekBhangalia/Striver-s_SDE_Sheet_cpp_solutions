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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findMaxPath(root,maxi);
        return maxi;
    }

    int findMaxPath(TreeNode* root, int& maxi){
        if(!root){
            return 0;
        }
        int lh = findMaxPath(root->left,maxi);
        if(lh<0)     lh=0;
        int rh = findMaxPath(root->right,maxi);
        if(rh<0)    rh=0;
        
        maxi = max(maxi,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
};
