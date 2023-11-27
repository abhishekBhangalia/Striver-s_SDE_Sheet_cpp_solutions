/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.

//TC-O(2n) n for inserting and n for clear, SC-O(2n)
// vector<int> leftView(Node *root)
// {
//     vector<int> ans;
//     if(root == NULL)    return ans;
    
//     vector<Node*> tmp1, tmp2;
    
//     tmp1.push_back(root);
//     while(tmp1.size()>0 or tmp2.size()>0){
//         if(tmp1.size()>0){
//             ans.push_back(tmp1[0]->data);
//             for(int i = 0; i<tmp1.size(); i++){
//                 if(tmp1[i]->left)   tmp2.push_back(tmp1[i]->left);
//                 if(tmp1[i]->right)  tmp2.push_back(tmp1[i]->right);
//             }
//             tmp1.clear();
//         }
//         else{
//             ans.push_back(tmp2[0]->data);
//             for(int i = 0; i<tmp2.size(); i++){
//                 if(tmp2[i]->left)   tmp1.push_back(tmp2[i]->left);
//                 if(tmp2[i]->right)  tmp1.push_back(tmp2[i]->right);
//             }
//             tmp2.clear();
//         }
//     }
    
//     return ans;
// }


//TC-O(n), SC-O(height) height can be n if tree is skewed
void rec_rlr(int level, Node* node, vector<int>& ans){
    if(node != NULL){
        if(level == ans.size())     ans.push_back(node->data);
        rec_rlr(level+1, node->left, ans);
        rec_rlr(level+1, node->right, ans);
    }
}


vector<int> leftView(Node *root)
{
    vector<int> ans;
    rec_rlr(0,root,ans);
    return ans;
}
