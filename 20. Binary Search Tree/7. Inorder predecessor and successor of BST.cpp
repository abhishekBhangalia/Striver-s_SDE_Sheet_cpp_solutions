/*************************************************************

    Following is the Binary Tree node structure
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };

*************************************************************/

// // TC-O(log n), SC-O(log n)
// void get_predecessor(TreeNode* root, int key, int &pred){
//     if(root){
//         if(root->data < key){
//             pred = root->data;
//             get_predecessor(root->right, key, pred);
//         }
//         else  get_predecessor(root->left, key, pred);
//     }
// }

// // TC-O(log n), SC-O(log n)
// void get_successor(TreeNode* root, int key, int& succ){
//     if(root){
//         if(root->data > key){
//             succ = root->data;
//             get_successor(root->left, key, succ);
//         }
//         else    get_successor(root->right, key, succ);
//     }
// }




// // TC-O(log n), SC-O(1)
// int get_predecessor(TreeNode* root, int key){
//     int pred = -1;
//     while(root){
//         if(root->data < key){
//             pred = root->data;
//             root = root->right;
//         }
//         else root = root->left;
//     }
//     return pred;
// }

// // TC-O(log n), SC-O(1)
// int get_successor(TreeNode* root, int key){
//     int succ = -1;
//     while(root){
//         if(root->data > key){
//             succ = root->data;
//             root = root->left;
//         }
//         else    root = root->right;
//     }
//     return succ;
// }

// // TC-O(2 log n), SC-O(log n), is tree is not skewed else O(2n)
// pair<int, int> predecessorSuccessor(TreeNode *root, int key)
// {
//     int succ = get_successor(root, key);
//     int pred = get_predecessor(root, key);
    
//     return {pred, succ};
// }


// TC-O(log n), SC-O(1), is tree is not skewed else O(2n)
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    TreeNode* tmp = root;
    int pred = -1, succ = -1;
    while(tmp){
        if(tmp->data < key){
            pred = tmp->data;
            tmp = tmp->right;
        }
        else if(tmp->data > key){
            succ = tmp->data;
            tmp = tmp->left;
        }
        else{
            TreeNode *tmp2 = tmp;
            tmp = tmp->left;
            tmp2 = tmp2->right;
            while(tmp or tmp2){
                if(tmp){//finding rightmost child of left child for pred
                    pred = tmp->data;
                    tmp = tmp->right;
                }
                if(tmp2){//finding leftmost child of right child for succ
                    succ = tmp2->data;
                    tmp2 = tmp2->left;
                }
            }

            // tmp2 = tmp2->right;
            // while(tmp2){
            //     succ = tmp2->data;
            //     tmp2 = tmp2->right;
            // }

            break;
        }
    }
    return {pred, succ};
}


