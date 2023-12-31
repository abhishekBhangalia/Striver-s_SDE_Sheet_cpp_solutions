struct t_node{// Trie node will store links of size 2. ie one for 0 and one for 1
    t_node* links[2]; 

    t_node* get_link(int bit){
        return links[bit];
    }

    void set_link(int bit, t_node* link){
        links[bit] = link;
    }

    bool has_link(int bit){
        return links[bit] != NULL;
    }
};

class Trie{
    private:
        t_node* root;
        

    public:
        Trie(){
            root = new t_node();
        }
        
        void insert(int x){//insert x bit wise from left to right. ie first 31 bit then, 30, 29,....., 1,0 bit.
            t_node* tmp = root;
            for(int i=31; i>=0; i--){
                int bit = x>>i & 1;
                if(!tmp->has_link(bit)){
                    tmp->set_link(bit, new t_node());
                }
                tmp = tmp->get_link(bit);
            }
        }

        int get_max(int x){
            t_node* tmp = root;
            int maxi = 0;
            for(int i=31; i>=0; i--){
                int bit = x>>i & 1;
                if(tmp->has_link(1 - bit)){//if tmp has opposite bit then set that bit of the maxi
                    maxi = maxi | 1<<i;
                    tmp = tmp->get_link(1-bit);
                }
                else{
                    tmp = tmp->get_link(bit);
                }
            }
            return maxi;
        }
};


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto &x:nums){
            trie.insert(x);
        }
        int max_xor = 0;
        for(auto &x:nums){
            max_xor = max(max_xor, trie.get_max(x));
        }
        return max_xor;
    }
};
