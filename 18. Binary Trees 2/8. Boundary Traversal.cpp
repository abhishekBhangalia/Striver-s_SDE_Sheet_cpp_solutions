/************************************************************

    Following is the Binary Tree node structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
#include <bits/stdc++.h>


//TC-O(left height)+O(n)+O(right height)
vector<int> traverseBoundary(TreeNode<int> *root)
{
	vector<int> ans;

    //left boundary
    TreeNode<int>* tmp = root;
    if(tmp){
        ans.push_back(tmp->data);
        tmp = tmp->left;
    }
    if(tmp){
        while(tmp){
            ans.push_back(tmp->data);
            if(tmp->left){
                tmp = tmp->left;
            }
            else    tmp=tmp->right;
        }
        ans.pop_back();
    }

    //bottom boundary
    stack<TreeNode<int>*> st;
    tmp = root;
    if(tmp) st.push(tmp);
    while(not st.empty()){
        tmp = st.top();
        st.pop();
        if(tmp->left == NULL and tmp->right == NULL){
            ans.push_back(tmp->data);
        }
        if(tmp->right){
            st.push(tmp->right);
        }
        if(tmp->left){
            st.push(tmp->left);
        }
    }

    //right boundary
    vector<int> rt;
    tmp = root;
    if(tmp and tmp->right)  tmp = tmp->right;
    else return ans;

    while(tmp){
        rt.push_back(tmp->data);
        if(tmp->right){
            tmp = tmp->right;
        }
        else tmp = tmp->left;
    }
    rt.pop_back();
    for(int i=rt.size()-1; i>=0; i--){
        ans.push_back(rt[i]);
    }
    return ans;
}

