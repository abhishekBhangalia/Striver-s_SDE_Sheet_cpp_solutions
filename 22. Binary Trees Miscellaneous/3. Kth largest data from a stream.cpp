class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        // this->nums = nums;
        
        // sort(nums.begin(),nums.end(), greater<int>());
        // nums.erase(nums.begin()+k, nums.end());

        int x = min(k,(int)nums.size());
        for(int i=0; i<x; i++){
            q.push(nums[i]);
        }
        x= (int) nums.size();
        for(int i=k; i<x; i++){
            if(nums[i]>q.top()){
                q.pop();
                q.push(nums[i]);
            }
        }
        // for(int i:nums){
        //     q.push(i);
        // }
    }
    
    int add(int val) {
        // nums.emplace_back(val);
        // sort(nums.begin(), nums.end(), greater<int>());
        // nums.pop_back();
        // return nums[k-1];

        if( q.size()<k){
            q.push(val);
        }

        else if(val>q.top()){
            q.pop();
            q.push(val);
            
        }
        
        
        // q.push(val);
        // if(q.size()>k)
        //     q.pop();
        return q.top();
        
    }

private:
    int k;
    // vector<int> nums;
    priority_queue<int, vector<int>,greater<int>> q;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
