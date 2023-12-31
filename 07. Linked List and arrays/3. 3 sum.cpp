class Solution {
public:

    // Using recursion(TLE), TC-O(2^n) + O(triplets x log triplets) + O(triplets ^ 2), SC-O(triplets) + O(n)
    // void rec(int i, int sum, int selected, vector<int>& nums, vector<vector<int>>& triplets, vector<int> cur_trip ){
        
    //     if(selected == 3){
    //         if(sum == 0){
    //             sort(cur_trip.begin(),cur_trip.end());
    //             triplets.push_back(cur_trip);
    //         }
    //         return;
    //     }
    //     if(i==0){
    //         if(selected == 2 and sum + nums[0] == 0){
    //             cur_trip.push_back(nums[0]);
    //             sort(cur_trip.begin(), cur_trip.end());
    //             triplets.push_back(cur_trip);
    //         }
    //         return;
    //     }
    //     rec(i-1,sum,selected,nums,triplets,cur_trip);
    //     cur_trip.push_back(nums[i]);
    //     rec(i-1,sum+nums[i],selected+1,nums,triplets,cur_trip);
    // }


    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> triplets;
    //     vector<int> cur_trip;
    //     rec(nums.size()-1, 0, 0,nums,triplets,cur_trip);

    //     if(triplets.size()<=1){
    //         return triplets;
    //     }

    //     sort(triplets.begin(),triplets.end());

    //     vector<vector<int>> ans;
    //     int n=triplets.size();

    //     if(triplets[0] == triplets[1]){
    //         ans.push_back(triplets[1]);
    //     }else{
    //         ans.push_back(triplets[0]);
    //         ans.push_back(triplets[1]);
    //     }

    //     for(int i = 2; i<n; i++){
    //         if(triplets[i]!=triplets[i-1]){
    //             ans.push_back(triplets[i]);
    //         }
    //     }
        
    //     return ans;
    // }



    // // Brute Force (TLE), TC-O(n^3) + O(n/3 x log n/3), SC-O(n) for set
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<vector<int>> set;
        
    //     for(int i=0; i<nums.size(); i++){
    //         for(int j=i+1; j<nums.size(); j++){
    //             for(int k=j+1; k<nums.size(); k++){
    //                 if(nums[i]+nums[j]+nums[k] == 0){
    //                     vector<int> triplet = {nums[i],nums[j],nums[k]};
    //                     sort(triplet.begin(), triplet.end());
    //                     set.insert(triplet);
    //                 }
    //             }
    //         }
    //     }

    //     vector<vector<int>> ans(set.begin(),set.end());
    //     return ans;
    // }


    // // Brute Force (TLE), TC-O(n^2) + O(n/3 x log n/3) for set, SC-O(n) for set + O(n) for is_present
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     set<vector<int>> set;
        
        
    //     for(int i=0; i<nums.size(); i++){
    //         unordered_set<int> is_present;
    //         for(int j=i+1; j<nums.size(); j++){
    //             int third = -(nums[i]+nums[j]);
    //             if(is_present.find(third) != is_present.end()){
    //                 vector<int> triplet = {nums[i],nums[j],third};
    //                 sort(triplet.begin(), triplet.end());
    //                 set.insert(triplet);
    //             }
    //             is_present.insert(nums[j]);
                
    //         }
    //     }

    //     vector<vector<int>> ans(set.begin(),set.end());
    //     return ans;
    // }


    // Brute Force (TLE), TC-O(n^2) + O(n/3 x log n/3) for set, SC-O(n) for set
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        
        int one = 0, two = 1, three = n-1;

        for(one = 0; one < n-2; one++){
            if(one>0 and nums[one]==nums[one-1]){
                
                continue;
            }
            two = one+1;
            three = n-1;
            while(two<three){
                int sum = nums[one]+nums[two]+nums[three];
                if(sum == 0){
                    ans.push_back({nums[one],nums[two],nums[three]});
                    two++;
                    while(two<three and nums[two]==nums[two-1]){
                        two++;
                    }
                    three--;
                    while(two<three and nums[three] == nums[three+1]){
                        three--;
                    }
                }
                else if(sum < 0){
                    two++;
                    // while(two<three and nums[two]==nums[two-1]){
                    //     two++;
                    // }
                }
                else{
                    three--;
                    // while(two<three and nums[three] == nums[three+1]){
                    //     three--;
                    // }
                }

            }
        }
        return ans;
    }
};
