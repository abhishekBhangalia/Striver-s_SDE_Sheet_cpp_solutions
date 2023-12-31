class Solution {
public:
    // // recursion(TLE), TC-O(2^n), SC-O(n)
    // int rec(int i, int prev, vector<int>& nums){
    //     if(i==0)    return nums[0] < prev;
    //     int take = nums[i] < prev ? 1 + rec(i-1, nums[i], nums) : 0;
    //     int not_take = rec(i-1, prev, nums);
    //     return max(take, not_take);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     return rec(n-1, 1e4+1, nums);
    // }
    

    // Memoization(), TC-O(2^n), SC-O(n)
    // int maxi;

    // int dp(int i, int prev, vector<int>& nums, vector<vector<int>>& DP){
    //     if(DP[i][prev+maxi] != -1)   return DP[i][prev+maxi];
    //     if(i==0)    return DP[i][prev+maxi] = nums[0] < prev;
    //     int take = nums[i] < prev ? 1 + dp(i-1, nums[i], nums, DP) : 0;
    //     int not_take = dp(i-1, prev, nums, DP);
    //     return DP[i][prev+maxi] = max(take, not_take);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     maxi = *max_element(nums.begin(), nums.end());
    //     int tmp = maxi;
    //     int min = *min_element(nums.begin(), nums.end());
    //     maxi = max(abs(min), abs(maxi));
    //     vector<vector<int>> DP(n, vector<int> (2*maxi+2,-1));
    //     return dp(n-1, tmp+1, nums, DP);
    // }


    // int maxi;
    
    // int dp(int i, int prev, vector<int>& nums, vector<vector<int>>& DP){
    //     if(DP[i][prev+maxi] != -1)   return DP[i][prev+maxi];
    //     if(i==0)    return DP[i][prev+maxi] = nums[0] < prev;
    //     int take = nums[i] < prev ? 1 + dp(i-1, nums[i], nums, DP) : 0;
    //     int not_take = dp(i-1, prev, nums, DP);
    //     return DP[i][prev+maxi] = max(take, not_take);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     maxi = *max_element(nums.begin(), nums.end());
    //     int tmp = maxi;
    //     int min = *min_element(nums.begin(), nums.end());
    //     maxi = max(abs(min), abs(maxi));
    //     vector<vector<int>> dp(n, vector<int> (2*maxi+2,0));
    //     nums.push_back(tmp+1);
    //     n=nums.size();
    //     for(int i=1; i<n; i++){
    //         dp[0][nums[i]+maxi] = nums[0] < nums[i];
    //     }
        
    //     for(int i=1; i<n; i++){
    //         for(int prev = i+1; prev<n; prev++){
    //             int take = nums[prev] > nums[i] ? 1 + dp[i-1][nums[i]+maxi] : 0;
    //             int not_take = dp[i-1][nums[prev]+maxi];
    //             dp[i][nums[prev] + maxi] = max(take, not_take);
    //         }
    //     }

    //     return dp[n-2][tmp+1+maxi];
    // }


    // // Memoization2, TC-O(n^2), SC-O(n^2)+O(n)
    // int dp(int i, int prev, vector<int>& nums, vector<vector<int>>& DP){
    //     if(DP[i][prev] != -1)   return DP[i][prev];
    //     if(i==0)    return DP[i][prev] = nums[0] < nums[prev];
    //     int take = nums[i] < nums[prev] ? 1 + dp(i-1, i, nums, DP) : 0;
    //     int not_take = dp(i-1, prev, nums, DP);
    //     return DP[i][prev] = max(take, not_take);
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     nums.push_back(1e4+1);
    //     vector<vector<int>> DP(n, vector<int> (n+1,-1));
    //     return dp(n-1, n, nums, DP);
    // }


    // // Tabulation, TC-O(n^2), SC-O(n^2)+O(n)
    // int lengthOfLIS(vector<int>& nums) {
    //     nums.push_back(1e4+1);
    //     int n = nums.size();
    //     vector<vector<int>> dp(n-1, vector<int> (n,-1));

    //     for(int prev = 1; prev<n; prev++){
    //         dp[0][prev] = nums[0] < nums[prev];
    //     }
    //     for(int i=1; i<n-1; i++){
    //         for(int prev = i+1; prev<n; prev++){
    //             int take = nums[i] < nums[prev] ? 1+dp[i-1][i] : 0;
    //             int not_take = dp[i-1][prev];
    //             dp[i][prev] = max(take, not_take);
    //         }
    //     }
    //     return dp[n-2][n-1];
    // }


    // // Tabulation(Space Optimization), TC-O(n^2), SC-+O(n)
    // int lengthOfLIS(vector<int>& nums) {
    //     nums.push_back(1e4+1);
    //     int n = nums.size();
    //     if(n==2)    return 1;
    //     vector<int> pre(n,0), cur(n,0);

    //     for(int prev = 1; prev<n; prev++){
    //         pre[prev] = nums[0] < nums[prev];
    //     }
        
    //     for(int i=1; i<n-1; i++){
    //         for(int prev = i+1; prev<n; prev++){
    //             int take = nums[i] < nums[prev] ? 1+pre[i] : 0;
    //             int not_take = pre[prev];
    //             cur[prev] = max(take, not_take);
    //         }
    //         pre = cur;
    //     }
    //     return cur[n-1];
    // }


    // Optimal using Binary Search, TC-O(n * log n), SC-O(n)
    // Note - this will only give length of LIS, lis may not be a actual LIS, so printing LIS is not possible with this method
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis;
        lis.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > lis.back())    lis.push_back(nums[i]);
            else{
                *lower_bound(lis.begin(), lis.end(), nums[i]) = nums[i];
            }
        }
        return lis.size();
    }
};
