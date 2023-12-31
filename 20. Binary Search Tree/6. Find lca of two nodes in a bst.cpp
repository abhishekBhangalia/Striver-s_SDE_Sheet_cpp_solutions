/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if (((p->val <= root->val) and (q->val >= root->val)) or (p->val >= root->val and q->val <= root->val))
        //     return root;
        // if (p->val < root->val){
        //     return lowestCommonAncestor(root->left,p,q);
        // }
        // else {
        //     return lowestCommonAncestor(root->right,p,q);
        // }

        if (root == NULL || root == p || root == q){
            return root;
        }
        root->left = lowestCommonAncestor(root->left, p, q);
        root->right = lowestCommonAncestor(root->right, p, q);
        if (root->left == NULL)return root->right;
        if (root->right == NULL)return root->left;
        return root;
    }


};
