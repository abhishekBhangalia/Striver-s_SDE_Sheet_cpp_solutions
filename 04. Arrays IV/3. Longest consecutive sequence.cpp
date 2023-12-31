class Solution {
public:

    // TC- O(n * log n) + O(n), SC - O(1)

    // int longestConsecutive(vector<int>& nums) {
    //     if(nums.size()<=1){
    //         return nums.size();
    //     }
    //     sort(nums.begin(),nums.end());

    //     int last_min = nums[0];
    //     int max_len = 1;
    //     int len = 1;
    //     for(int i=1; i<nums.size(); i++){
    //         if(nums[i] == last_min + 1){
    //             last_min = nums[i];
    //             len++;
    //         }
    //         else{
    //             if(nums[i]!=last_min){
    //                 last_min = nums[i];
    //                 max_len = max(max_len,len);
    //                 len = 1;
    //             }
    //         }
    //     }
    //     return max(max_len,len);
    // }

    // TC-O(3n), SC-O(n)
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        int max_len = 1;
        unordered_set<int> set;
        for(int x:nums){
            set.insert(x);
        }
        for(auto i:set){
            if(set.find(i-1) == set.end()){
                int len = 1;
                while(set.find(i+1) != set.end()){
                    len++;
                    i++;
                }
                max_len = max(len,max_len);
            }
        }
        return max_len;
    }
};
