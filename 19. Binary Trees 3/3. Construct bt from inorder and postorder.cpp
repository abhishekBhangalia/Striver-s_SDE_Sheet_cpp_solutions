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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> in_map;
        for(int i=0; i<inorder.size(); i++){
            in_map[inorder[i]] = i;
        }
        int top = postorder.size()-1; //use postorder as stack
        return makeTree(inorder,0,top,postorder,top,in_map); 
    }

    TreeNode* makeTree(vector<int>& inorder,int in_start, int in_end, vector<int>& postorder,int& post_top, unordered_map<int,int>& in_map){
        if(in_start > in_end )
            return nullptr;
        
        int x = postorder[post_top];
        post_top--;
        
        TreeNode* node = new TreeNode(x);
        int pos = in_map[x];
        
        node->right = makeTree(inorder,pos+1,in_end,postorder,post_top,in_map);
        node->left = makeTree(inorder,in_start,pos-1,postorder,post_top,in_map);
        return node; 
    }

};
