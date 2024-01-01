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
    bool isSymmetric(TreeNode* root) {
        if(!root) {
            cout<<"1";
            return false;
        }
        

        TreeNode* l = root->left;
        TreeNode* r = root->right;
        
        if(l==nullptr and r == nullptr){
            cout<<"2";
            return true;
        }
            
        if(l==nullptr or r == nullptr){
            cout<<"3";
            return false;

        }
            

        queue<TreeNode*> lq;
        stack<TreeNode*> rs;
        
        lq.push(l);
        rs.push(r);

        while(!lq.empty() or !rs.empty()){
            if(lq.size() != rs.size()){
                cout<<"4";
                return false;
            }  
                

            int size = lq.size();
            int size2 = size;
            vector<TreeNode*> tmp;
            while(size--){
                
                TreeNode* t1 = lq.front(); 
                lq.pop();
                TreeNode* t2 = rs.top();
                rs.pop();
                // cout<<t1->val<<" : "<<t2->val<<endl;

                if((t1->val != t2->val)){
                    
                    cout<<t1->val<<" : "<<t2->val;
                    
                    return false;
                }
                    
                
                if((t1->left==nullptr and t2->right!=nullptr)){
                    cout<<"6";
                    return false;
                }
                    
                
                if((t1->right==nullptr and t2->left!=nullptr)){
                    cout<<"7";
                    return false;
                }

                if((t2->left==nullptr and t1->right!=nullptr)){
                    cout<<"6";
                    return false;
                }
                    
                
                if((t2->right==nullptr and t1->left!=nullptr)){
                    cout<<"7";
                    return false;
                }
               
                    

                if(t1->left!=nullptr and t2->right!=nullptr){
                    // cout<<"\no";
                    lq.push(t1->left);
                    tmp.push_back(t2->right);
                    // rs.push(t2->left);
                }
                if(t1->right!=nullptr and t2->left!=nullptr){
                    // cout<<"\np";
                    lq.push(t1->right);
                    tmp.push_back(t2->left);
                    // rs.push(t2->right);
                }
            }
            for(int i=tmp.size()-1;i>=0;i--){
                cout<<tmp[i]->val<<",";
                rs.push(tmp[i]);
            }
            // tmp.clear();
        }

        return true;
    }
};
