/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

static const auto speed=[]{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root)    q.push(root);

        while(not q.empty()){
            int size = q.size();
            while(size--){
                Node* tmp = q.front();
                q.pop();
                tmp->next = size==0 ? NULL : q.front();
                if(tmp->left)   q.push(tmp->left);
                if(tmp->right)  q.push(tmp->right);
            }
        }
        return root;
    }


    // Node* connect(Node* root) {
    //     if(root==NULL){
    //         return NULL;
    //     }
    //     if(root->left!=NULL){
    //         root->left->next= root->right;
    //     }
    //     if(root->next!=NULL && root->right!=NULL){
    //         root->right->next= root->next->left;
    //     }
    //     connect(root->left);
    //     connect(root->right);
    //     return root;
    // }
};
