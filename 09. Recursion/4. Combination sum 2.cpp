class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> arr;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());

        findUniqCombn(0,target,arr,tmp,candidates);
        return arr;
    }

    void findUniqCombn(int start, int target, vector<vector<int>>& arr, vector<int>& tmp, vector<int>& candidates){
        if(target == 0){
            arr.push_back(tmp);
            return;
        }
        

        for(int i=start; i<candidates.size(); i++){
            if(candidates[i]>target)
                break;
            if((i>start) && (candidates[i] == candidates[i-1])){
                continue;
            }
            tmp.push_back(candidates[i]);
            findUniqCombn(i+1,target-candidates[i],arr,tmp,candidates);
            tmp.pop_back(); 
        }
        
    }
};
