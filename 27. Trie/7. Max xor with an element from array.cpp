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
            // if(tmp->get_link(0) == NULL and tmp->get_link(1) == NULL)   return -1;
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

 bool comp(int* a, int* b){
    return a[1] < b[1];
}


class Solution {
public:
    // vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
    //     int n = queries.size();
    //     vector<int> ans;
    //     for(int i=0; i<n; i++){
    //         int maxi = 0;
    //         Trie trie;
    //         int m = queries[i][1];
    //         int x = queries[i][0];
    //         int flag = 0;
    //         for(int &y:nums){
    //             if(y<=m){
    //                 flag = 1;
    //                 trie.insert(y);
    //             }
    //         }
    //         if(flag == 0)   ans.push_back(-1);
    //         else{
    //             maxi = max(maxi, trie.get_max(x));
    //             ans.push_back(maxi);
    //         }
    //     }
    //     return ans;
    // }

   

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n1 = nums.size();
        int n2 = queries.size();
        vector<int> ans(n2);
        int **a = new int*[n2];
        for(int i=0; i<n2; i++){
            a[i] = new int[3];
            a[i][0] = queries[i][0];
            a[i][1] = queries[i][1];
            a[i][2] = i;
        }

        //O(n1 log n1 + n2 log n2)
        sort(a, a+n2, comp);
        sort(nums.begin(), nums.end());

        Trie trie;
        int i=0;
        
        //O(n2*32 + n1*32)
        for(int j=0; j<n2; j++){
            int m = a[j][1];
            int maxi = -1;
            while(i<n1 and nums[i]<=m){
                trie.insert(nums[i]);
                i++;
            }
            if(i==0)    ans[a[j][2]] = -1;
            else{
                maxi = max(maxi, trie.get_max(a[j][0]));
                ans[a[j][2]] = maxi;
            }
        }
        return ans;

    }
};
