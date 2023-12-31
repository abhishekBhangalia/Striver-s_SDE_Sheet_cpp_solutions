
/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    
    //TC-O(n), SC-O(h)
    void mirror(Node* node) {
        // code here
        stack<Node*> st;
        if(node)    st.push(node);
        
        while(not st.empty()){
            Node* tmp = st.top();
            st.pop();
            swap(tmp->left, tmp->right);
            if(tmp->right){
                st.push(tmp->right);
            }
            if(tmp->left){
                st.push(tmp->left);
            }
        }
    }
};
