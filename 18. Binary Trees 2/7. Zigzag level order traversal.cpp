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
 


    // vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    //     vector<TreeNode*> q;
    //     if(root)    q.push_back(root);
    //     vector<vector<int>> ans;
    //     int level = 1;
    //     while(q.size()>0){
    //         int size = q.size();
    //         vector<TreeNode*> tmp;
    //         vector<int> lvl_trav;
           
    //         if(level%2){
    //             for(int i=0; i<size; i++){
    //                 lvl_trav.push_back(q[i]->val);
    //                 if(q[i]->left){
    //                     tmp.push_back(q[i]->left);
    //                 }
    //                 if(q[i]->right){
    //                     tmp.push_back(q[i]->right);
    //                 }
    //             }
                
    //         }
    //         else{
                
    //             for(int i=0; i<size; i++){
    //                 lvl_trav.push_back(q[size-1-i]->val);
                    
    //                 if(q[i]->left){
    //                     tmp.push_back(q[i]->left);
    //                 }
    //                 if(q[i]->right){
    //                     tmp.push_back(q[i]->right);
    //                 }
    //             }
    //         }
    //         ans.push_back(lvl_trav);
    //         q = tmp;
    //         level++;
    //     }
    //     return ans;
    // }

    //TC-O(n), SC-O(width)
    //can use queue also
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<TreeNode*> q;
        if(root)    q.push_back(root);
        vector<vector<int>> ans;
        bool left_to_right = true;
        while(q.size()>0){
            int size = q.size();
            vector<TreeNode*> tmp;
            vector<int> lvl_trav(size);

            for(int i=0; i<size; i++){
                int id = left_to_right ? i : size-1-i;
                lvl_trav[id] = q[i]->val;
                if(q[i]->left){
                    tmp.push_back(q[i]->left);
                }
                if(q[i]->right){
                    tmp.push_back(q[i]->right);
                }
            }
            
            ans.push_back(lvl_trav);
            q = tmp;
            left_to_right = !left_to_right;
        }
        return ans;
    }
};
