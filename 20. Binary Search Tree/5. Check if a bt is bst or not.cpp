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
    // bool isValidBST(TreeNode* root) {
    //     if (root==nullptr)  return false;
    //     queue<pair<TreeNode* ,pair<int,int>>> q;
    //     q.push({root,{INT_MIN,INT_MAX}});
    //     map<int,int> v;

    //     while(!q.empty()){
    //         pair<TreeNode* ,pair<int,int>> tmp = q.front();
    //         q.pop();

    //         int val = tmp.first->val;

    //         if((val < tmp.second.first or val > tmp.second.second)){
    //             return false;

    //         }else if((val == tmp.second.first or val == tmp.second.second)){
    //             if(val == INT_MIN or val == INT_MAX ) {
    //                 if(v[val]){
    //                     return false;
    //                 }
    //                 else{
    //                     v[val]=1;
    //                 }
    //             }
    //             else{
    //                 return false;
    //             }
    //         }
            
    //         if(tmp.first->left)
    //             q.push({tmp.first->left,{tmp.second.first,tmp.first->val}});
            
    //         if(tmp.first->right)
    //             q.push({tmp.first->right,{tmp.first->val,tmp.second.second}});
    //     }
    //     return true;
    // }

    bool isValidBST(TreeNode* root) {
        if (root==nullptr)  return false;
        queue<pair<TreeNode* ,pair<long,long>>> q;
        q.push({root,{LONG_MIN,LONG_MAX}});

        while(!q.empty()){
            pair<TreeNode* ,pair<long,long>> tmp = q.front();
            q.pop();

            if((tmp.first->val <= tmp.second.first or tmp.first->val >= tmp.second.second))
                return false;
            
            if(tmp.first->left)
                q.push({tmp.first->left,{tmp.second.first,tmp.first->val}});
            
            if(tmp.first->right)
                q.push({tmp.first->right,{tmp.first->val,tmp.second.second}});
        }
        //why these lines are reducing memory usage ? SHould we use these lines?
        root->left = nullptr;
        root->right = nullptr;
        
        return true;
    }
};
