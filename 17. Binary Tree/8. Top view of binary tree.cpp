/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <bits/stdc++.h>

// void rec(TreeNode<int>* node, int dis, map<int, int>& m){
//     if(node){
//         m[dis] = node->data;
//         rec(node->left, dis-1, m);
//         rec(node->right, dis+1, m);
//     }
// }

//TC-O(n)+O(top nodes), SC-O(3n)
vector<int> getTopView(TreeNode<int> *root)
{
    map<int, int> m;
    // rec(root, 0, m);
    queue<pair<TreeNode<int>*, int>> q;
    if(root)    q.push({root, 0});
    while(not q.empty()){
        if(m.find(q.front().second) == m.end())  m[q.front().second] = q.front().first->data;
        if(q.front().first->left){
            q.push({q.front().first->left, q.front().second - 1});
        }
        if(q.front().first->right){
            q.push({q.front().first->right, q.front().second + 1});
        }
        q.pop();
    } 
    vector<int> ans;
    for(auto i:m){
        // cout<<i.first;
        ans.push_back(i.second);
    }
    return ans;    
}




