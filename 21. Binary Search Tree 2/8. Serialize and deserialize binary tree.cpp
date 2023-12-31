/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        code(root,s);
        cout<<s<<endl;
        return s;
    }

    void code(TreeNode* root, string& s){
        if(root == nullptr){
            s+='N';
            return;
        }
        s+=to_string(root->val)+',';
        code(root->left,s);
        code(root->right,s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return decode(data,start);
    }

    TreeNode* decode(string& data, int& i){
        // cout<<i<<endl;
        if (data[i]=='N')   {
            // i--;
            return nullptr;
        }

        int x=i;
        while(data[x]!=','){
            x++;
        }
        int val = stoi(data.substr(i,x));
        i=x;
        TreeNode* node = new TreeNode(val);
        cout<<node->val<<endl;
        i++;
        node->left = decode(data,i);
        i++;
        node->right = decode(data,i);
        return node;  
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
