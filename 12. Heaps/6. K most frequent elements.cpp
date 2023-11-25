class Solution {
public:

    //Beats 99%
    //TC-O(n)+O(2k*log k), SC-O(2k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int x:nums){
            map[x]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto i:map){
            pq.push({i.second,i.first});
        }
        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }


    // //TC-O(2n)+O(2k*log k), SC-O(2k)
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> map;
    //     for(int x:nums){
    //         map[x]++;
    //     }
    //     priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
    //     for(auto i:map){
    //         pq.push({i.second,i.first});
    //         if(pq.size()>k) pq.pop();
    //     }
    //     vector<int> ans;
    //     while(k--){
    //         ans.push_back(pq.top().second);
    //         pq.pop();
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;
    // }


    // //TC-O(n)+O(2k*log k), SC-O(2k)
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     unordered_map<int,int> map;
    //     for(int x:nums){
    //         map[x]++;
    //     }
    //     vector<array<int,2>> freq;
    //     for(auto i:map){
    //         freq.emplace_back(array<int,2>{move(i.second),move(i.first)});
    //     }
    //     sort(freq.begin(),freq.end(),greater<>());
    //     vector<int> ans;
    //     int i=0;
    //     while(k--){
    //         ans.emplace_back(move(freq[i++][1]));
    //     }
    //     return ans;
    // }
};
