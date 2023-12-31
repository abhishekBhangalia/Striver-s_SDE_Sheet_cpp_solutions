class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> out;
        unordered_map<int,int> map;

        for(int i=0; i<nums.size(); i++){
           int numToFind = target-nums[i];

           if(map.find(numToFind) != map.end()){
               out.push_back(map[numToFind]);
               out.push_back(i);
               return out;
           }

           map[nums[i]] = i;
        }
        return out;
    }
};
