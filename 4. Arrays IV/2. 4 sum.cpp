class Solution {
public:


    // // TC-O(n^4)+ O(n/4 x log(n/4))(TLE), SC-O(n) + O(n)

    // vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    //     set<vector<int>> set;
        
    //     for(int i=0; i<nums.size()-3; i++){
    //         for(int j=i+1; j<nums.size()-2;j++){
    //             for(int k=j+1; k<nums.size()-1; k++){
    //                 for(int l=k+1; l<nums.size(); l++){
    //                     long sum = nums[i]+nums[j];
    //                     sum+=nums[k]+nums[l];   
    //                     if(sum == target){
    //                         vector<int> quad = {nums[i],nums[j],nums[k],nums[l]};
    //                         sort(quad.begin(),quad.end());
    //                         set.insert(quad);
    //                     }
    //                 }
    //             }
    //         }
    //     }

    //     vector<vector<int>> ans(set.begin(),set.end());
    //     return ans;
    // }


// // TC-O(n^3)+ O(n/4 x log(n/4)) (TLE), SC-O(n) + O(n) + O(n)
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
//         set<vector<int>> set;
        
//         for(int i=0; i<nums.size()-3; i++){
//             for(int j=i+1; j<nums.size()-2;j++){
//                 unordered_set<int> is_present;
//                 for(int k=j+1; k<nums.size(); k++){
//                     int four = target - (nums[i]);
//                     four -= (nums[j]+nums[k]);
//                     if(is_present.find(four) != is_present.end()){
//                         vector<int> quad = {nums[i],nums[j],nums[k],four};
//                         sort(quad.begin(),quad.end());
//                         set.insert(quad);
//                     }
//                     is_present.insert(nums[k]);
//                 }
//             }
//         }

//         vector<vector<int>> ans(set.begin(),set.end());
//         return ans;
//     }


    //TC - O(n^3)+O(n x log n), SC-O(n) for ans
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        for(int i=0; i<n-3; i++){
            if(i>0 and nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1; j<n-2;j++){
                if(j!=i+1 and nums[j] == nums[j-1]){
                    continue;
                }

                int k = j+1;
                int l = n-1;

                while(k<l){
                    long sum = nums[i]+nums[j];
                    sum += nums[k]+nums[l];
                    if(sum<target){
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[k],nums[l]});

                        k++;
                        while(k<l and nums[k]==nums[k-1]){
                            k++;
                        }

                        l--;
                        while(k<l and nums[l] == nums[l+1]){
                            l--;
                        }
                    }
                }
            }
        }
        return ans;
    }
};
