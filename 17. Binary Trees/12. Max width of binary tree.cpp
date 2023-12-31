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

static const auto speed=[]{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {
public:
    // int widthOfBinaryTree(TreeNode* root) {
    //     if(!root)   return 1;
    //     if(root->left == nullptr and root->right == nullptr)    return 1;

    //     int maxWid = INT_MIN;
    //     deque<TreeNode*> q;
    //     q.push_back(root);
    //     TreeNode* tmp;
    //     // vector<int> v;

    //     while(!q.empty()){
    //         int size = q.size();
    //         deque<TreeNode*> q2;
    //         tmp = q.front();
    //         // q.pop_front();
            
    //         while(!q.empty() and !tmp ){
    //             q.pop_front();
    //             tmp = q.front();
    //             size--;
    //         }
            
    //         // q.push_front(tmp);
    //         // size++;

    //         tmp = q.back();
    //         // q.pop_back();

    //         while(!q.empty() and !tmp){
    //             q.pop_back();
    //             tmp = q.back();
    //             size--;
    //         }

    //         // q.push_back(tmp);
    //         // size++;

    //         while(!q.empty()){
    //             tmp=q.back();
    //             q.pop_back();
    //             if(tmp){
    //                 q2.push_front(tmp->right);
    //                 q2.push_front(tmp->left);
    //             }
    //             else{
    //                 q2.push_front(nullptr);
    //                 q2.push_front(nullptr);
    //             }
    //         }
    //         q=q2;
    //         // v.push_back(size);
    //         maxWid = max(maxWid,size);
    //     }
    //     return maxWid;
    // }

    // int widthOfBinaryTree(TreeNode* root) {
    //     if(!root)    return 0;

    //     int maxWid = INT_MIN;
    //     vector<TreeNode*> v;
    //     v.push_back(root);
    //     vector<long long> col;
    //     col.push_back(0);

    //     TreeNode* tmp;

    //     while(v.size()){
    //         int size = v.size();
    //         int min = col[0];
            
    //         maxWid = max(maxWid,(int)(col.back()-col.front()+1));
    //         for(int i=0; i<size; i++){
    //             tmp = v[i];
    //             if(tmp->left){
    //                 v.push_back(tmp->left);
    //                 col.push_back(2*(col[i]-min)+1);
    //             }
    //             if(tmp->right){
    //                 v.push_back(tmp->right);
    //                 col.push_back(2*(col[i]-min)+2);
    //             }
    //         }
    //         v.erase(v.begin(),v.begin()+size);
    //         col.erase(col.begin(),col.begin()+size);
    //     }

    //     return maxWid;
    // }


    //beats 100%
    //TC-O(n), SC-O(2*max_width)
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long max_width = 1;

        queue<pair<TreeNode*, unsigned long long >> q;
        if(root)    q.push({root, 1});
        
        while(not q.empty()){
            int size = q.size();
            max_width = max(max_width, q.back().second - q.front().second + 1);

            while(size--){
                if(q.front().first->left){
                    q.push({q.front().first->left, 2*q.front().second});
                }
                if(q.front().first->right){
                    q.push({q.front().first->right, 2*q.front().second+1});
                }
                q.pop();
            }
        }

        return max_width;
    }


    //TC-O(n), SC-O(2*max_width)
    // int widthOfBinaryTree(TreeNode* root) {
    //     long max_width = 1;

    //     queue<pair<TreeNode*, long>> q;
    //     if(root)    q.push({root, 0});
        
    //     while(not q.empty()){
    //         int size = q.size();
    //         int min = q.front().second;
    //         max_width = max(max_width, q.back().second - q.front().second + 1);

    //         while(size--){
    //             if(q.front().first->left){
    //                 q.push({q.front().first->left, 2*q.front().second-min});
    //             }
    //             if(q.front().first->right){
    //                 q.push({q.front().first->right, 2*q.front().second+1-min});
    //             }
    //             q.pop();
    //         }
    //     }

    //     return max_width;
    // }

};

