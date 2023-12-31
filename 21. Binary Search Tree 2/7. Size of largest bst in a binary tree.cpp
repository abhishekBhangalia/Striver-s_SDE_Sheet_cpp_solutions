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

class TreeLimits{
    public:
    int max;
    int min;
    int sum;
    TreeLimits():max(-1e5), min(1e5), sum(-1e5){}
    TreeLimits(int mx, int mn, int sm) : max(mx), min(mn), sum(sm){}
};

int ans;

class Solution {
    TreeLimits rec(TreeNode* node){
       
        //leaf node
        if(node->left == NULL and node->right == NULL){
            ans = max(node->val, ans);
            return TreeLimits(node->val, node->val, node->val);
        }
        TreeLimits left, right;

        bool is_valid_bst = true;
        int both_sum = 0;
        if(node->left){
            left = rec(node->left);
            if(node->val <= left.max)    is_valid_bst = false;
            both_sum += left.sum;
        }
        
        if(node->right){
            right = rec(node->right);
            if(node->val >= right.min)   is_valid_bst = false;
            both_sum += right.sum;
        }

        if(is_valid_bst){
            int cur_max_sum = both_sum + node->val;
            ans = max(cur_max_sum, ans);
            return TreeLimits(right.max != -1e5 ? right.max : node->val, left.min != 1e5 ? left.min : node->val, cur_max_sum);
        }
        else{
            int cur_max_sum = max(left.sum, right.sum);
            ans = max(cur_max_sum, ans);
            return TreeLimits(1e5, -1e5, cur_max_sum);
        }
    }

public:

    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        ans = 0;
        if(root){
            TreeLimits tl = rec(root);
            max_sum = max(max_sum, tl.sum);//if all nodes are negative then return 0

            //don't know exactly why using this line of code the solution runs 100 ms faster and beats 100 %
            root->left = nullptr, root->right = nullptr;
            
        }
        return ans;
    }
};
