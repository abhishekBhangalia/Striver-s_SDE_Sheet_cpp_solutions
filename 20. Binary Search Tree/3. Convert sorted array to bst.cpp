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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = int(nums.size())/2;
        int n=nums.size()-1;
        return getNode(nums,0,n);
    }

    TreeNode* getNode(vector<int>& nums,int l,int h){
        
        if(l<=h){
            int mid = (l+h)/2;
            // TreeNode* root = new TreeNode(nums[mid]);
            // root->left = getNode(nums,l,mid-1);
            // root->right = getNode(nums,mid+1,h);
            // return root;
            
            return new TreeNode(nums[mid],getNode(nums,l,mid-1),getNode(nums,mid+1,h));
        }
        else return nullptr;
    }
};
