class Solution {
public:
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     vector<int> ans;
    //     int n = nums.size();

    //     vector<int> max_heap = {nums.begin(),nums.begin()+k};
    //     make_heap(max_heap.begin(),max_heap.end());
    //     ans.push_back(max_heap[0]);

    //     for(int i=k; i<n; i++){
    //         for(int j=0; j<max_heap.size(); j++)
    //             if(max_heap[j]==nums[i-k])  max_heap.erase(max_heap.begin()+j);
            
    //         max_heap.push_back(nums[i]);
    //         make_heap(max_heap.begin(),max_heap.end());
    //         ans.push_back(max_heap[0]);
    //     }
    //     return ans;
    // }


    //TC-O(2n * log n) if nums is in desc order, SC-O(n) if nums is in ascending order
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        priority_queue<pair<int,int>> pq;
        for(int i=0; i<k; i++){
            pq.push({nums[i],i});
        }
        ans.push_back(pq.top().first);
        
        for(int i=k; i<n; i++){
            pq.push({nums[i],i});
            while(not pq.empty() and pq.top().second <= i-k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
