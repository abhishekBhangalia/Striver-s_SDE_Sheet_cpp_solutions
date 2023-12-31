
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    
    int next() {
        TreeNode* tmp = st.top();
        int val = tmp->val;
        tmp = tmp->right;
        st.pop();

        while(tmp){
            st.push(tmp);
            tmp = tmp->left;
        }
        return val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    stack<TreeNode*> st;
};

