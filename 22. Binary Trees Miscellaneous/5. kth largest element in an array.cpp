class Solution {
public:

    //TC-O((n+k) * log n), SC-O(n)
    // int findKthLargest(vector<int>& nums, int k) {
    //     priority_queue<int> pq;
    //     for(int x : nums){
    //         pq.push(x);
    //     }
    //     k--;
    //     while(k--){
    //         pq.pop();
    //     }
    //     return pq.top();
    // }



    // int val = 10000; 
    // //TC-O(2*n), SC-O(20001)
    // int findKthLargest(vector<int>& nums, int k) {
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(0);
    //     int arr[20001]={0} , sum=0;
    //     for(auto x : nums){
    //         arr[val+x]++;
    //     }
    //     for(int i=2*val;i>=0;i--){
    //         sum+=arr[i];
    //         if(sum>=(k)) return i-val;
    //     }
    //     return 0;
    // }

// //TC-O(n)
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        nth_element(nums.begin(), nums.end() - k, nums.end());

        return nums[nums.size()-k];
    }
};
