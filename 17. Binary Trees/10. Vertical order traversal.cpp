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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> m;
        verTrav(root,m,0);
        vector<vector<int>> v;
        for(auto i:m){
            v.push_back(i.second);
        }
        return v;
    }

    void verTrav(TreeNode* root,map<int,vector<int>>& m, int c ){
        if(root == nullptr){
            return;
        }
        queue<pair<TreeNode*,int>> q;
        pair<TreeNode* ,int> tmp;
        q.push({root,c});

        while(!q.empty()){
            int size = q.size();
            map<int,vector<int>> m2;

            while(size--){
                tmp = q.front();
                q.pop();

                m2[tmp.second].push_back(tmp.first->val);
                sort(m2[tmp.second].begin(),m2[tmp.second].end());

                if(tmp.first->left){
                    q.push({tmp.first->left,tmp.second-1});
                }
                if(tmp.first->right){
                    q.push({tmp.first->right,tmp.second+1});
                }
            }
            for(auto i:m2){
                for(int j=0; j<i.second.size();j++){
                    m[i.first].push_back(i.second[j]);
                }
            }
        }
    }
};
