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


    //Approach 1
    //TC - O(log n) + k*O(log n)
    // int kthSmallest(TreeNode* root, int k) {
    //     int kth_s;
    //     TreeNode* tmp = root;
    //     while(tmp->left){
    //         tmp = tmp->left;
    //     }
    //     kth_s = tmp->val;
    //     k--;
    //     while(k--){
    //         kth_s = ceil(root,kth_s);
    //     }
    //     return kth_s;
    // }

    // int ceil(TreeNode* root, int x){
    //     int c = -1;
    //     while(root){
    //         if(root->val > x){
    //             c = root->val;
    //             root = root->left;
    //         }
    //         else{
    //             root = root->right;
    //         }
    //     }
    //     return c;
    // }

    //Approach 2 

    int kth_s = -1;
    int n;
    
    int kthSmallest(TreeNode* root, int k) {
        n=k;
        inorder(root);
        
        return kth_s;
    }

    void inorder(TreeNode* root){
        if(!root || n==0){
            return;
        }
        else{
            inorder(root->left);
            n--;
            if(n==0){
                kth_s=root->val;
                return;
            }
            inorder(root->right);
        }
    }

    // int ans = -1;
    // int traverse(TreeNode* root, int k ){
    //     if(!root) return 0 ;
    //     int nl = 0, nr = 0;
    //     if( root->left ) nl = traverse(root->left, k);
    //     if( k < nl ); 
    //     else{
    //         if( k == 1 + nl ) ans = root->val;
    //         else{
    //             nr = traverse(root->right, k - 1 - nl);
    //         }
    //     }
    //     return 1 + nl + nr;
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     traverse(root, k);
    //     return ans;
    // }
};
