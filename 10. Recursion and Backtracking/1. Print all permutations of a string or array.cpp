class Solution {
public:

    //Approach 1

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> tmp;
    //     findPerm(nums,ans,tmp);
    //     return ans;
    // }

    // void findPerm(vector<int> nums,vector<vector<int>>& ans, vector<int>& tmp){
    //     if(nums.size()==0){
    //         ans.push_back(tmp);
    //         return;
    //     }
    //     for(int i=0; i<nums.size(); i++){
    //         int x = nums[i];
    //         tmp.push_back(x);
    //         nums.erase(nums.begin()+i);
    //         findPerm(nums,ans,tmp);
    //         tmp.pop_back();
    //         nums.insert(nums.begin()+i,x);
    //     }
    // }


    //Approach 2

    // vector<vector<int>> permute(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> tmp;
    //     unordered_map<int,int> m;
    //     findPerm(nums,ans,tmp,m);
    //     return ans;
    // }

    // void findPerm(vector<int>& nums,vector<vector<int>>& ans, vector<int>& tmp,unordered_map<int,int>& m){
    //     if(tmp.size()==nums.size()){
    //         ans.push_back(tmp);
    //         return;
    //     }
    //     for(int i=0; i<nums.size(); i++){
    //         if(!m[nums[i]]){
    //             m[nums[i]] = 1;
    //             int x = nums[i];
    //             tmp.push_back(x);
    //             findPerm(nums,ans,tmp,m);
    //             tmp.pop_back();
    //             m[nums[i]] = 0;
    //         }
    //     }
    // }

    //Approach 3

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        findPerm(0,nums,ans);
        return ans;
    }

    void findPerm(int k,vector<int>& nums, vector<vector<int>>& ans){
        if(k==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=k; i<nums.size(); i++){
           
            swap(nums[i],nums[k]);
            findPerm(k+1,nums,ans);
            swap(nums[i],nums[k]);
            
        }
    }
};
