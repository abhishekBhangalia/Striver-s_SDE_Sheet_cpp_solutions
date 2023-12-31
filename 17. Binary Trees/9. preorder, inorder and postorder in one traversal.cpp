/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/

//TC-O(3n), SC-O(3n) + O(n)
// vector<vector<int>> getTreeTraversal(TreeNode *root){
//     vector<vector<int>> ans(3);
//     //ans[0] - inorder, ans[1] = preorder, ans[2] = postorder

//     vector<pair<TreeNode*, int>> st;
//     if(root)    st.push_back({root, 1});

//     while(st.size()){
//         if(st.back().second == 1){//Preorder
//             ans[1].push_back(st.back().first->data);
//             st.back().second++;
//             if(st.back().first->left){
//                 st.push_back({st.back().first->left, 1});
//             }
//         }
//         else if(st.back().second == 2){//Inorder
//             ans[0].push_back(st.back().first->data);
//             st.back().second++;
//             if(st.back().first->right){
//                 st.push_back({st.back().first->right, 1});
//             }
//         }
//         else{
//             //Postorder
//             ans[2].push_back(st.back().first->data);
//             st.pop_back();
//         }
//     }
//     return ans;
// }



//TC-O(n), SC-O(3n) + O(n)(aux stack space)
void qns(TreeNode *root, vector<int> &v1, vector<int> &v2, vector<int> &v3) {
    if(root == nullptr) return;
    v2.push_back(root->data);
    qns(root->left, v1, v2, v3);
    v1.push_back(root->data);
    qns(root->right, v1, v2, v3);
    v3.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> v1, v2, v3;
    vector<vector<int>> fans;
    qns(root, v1, v2, v3);
    fans.push_back(v1);
    fans.push_back(v2);
    fans.push_back(v3);
    return fans;
}
