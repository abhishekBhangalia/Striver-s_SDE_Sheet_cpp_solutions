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

    //sol 1
    
    // TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //     if(inorder.size()==0)  return nullptr;

    //     TreeNode* root = new TreeNode(preorder.front());
        
    //     int i=0; 
    //     while(i<inorder.size() and (inorder[i]!=preorder.front())){
    //         i++;
    //     }
    //     preorder.erase(preorder.begin());
    //     vector<int> tmp = inorder;
    //     inorder = {inorder.begin(),inorder.begin()+i};
    //     root->left = buildTree(preorder,inorder);
    //     inorder = tmp;
    //     inorder = {inorder.begin()+i+1,inorder.end()};
    //     root->right = buildTree(preorder,inorder);
    //     return root;
    // }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0; i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        return makeTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
    }

    TreeNode* makeTree(vector<int>& preorder, int ps, int pe, vector<int>& inorder, int is, int ie,unordered_map<int,int>& m){
        if(ps>pe){
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[ps]);
        int pos = m[preorder[ps]];
        int numsLeft = pos-is;
        root->left = makeTree(preorder,ps+1,ps+numsLeft,inorder,is,pos-1,m);
        root->right = makeTree(preorder,ps+1+numsLeft,pe,inorder,pos+1,ie,m);
        return root;
    }
};
