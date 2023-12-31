class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> combn;
        vector<int> tmp;
        findUniqueCombn(0,combn,target,tmp,candidates);
        return combn;
    }
    
    void findUniqueCombn(int i, vector<vector<int>>& comb, int target, vector<int>& tmp, vector<int>& arr){
        if(target == 0){
            comb.push_back(tmp);
            return;
        }
        if(i==arr.size()){
            return;
        }
        
        if(arr[i]<=target){
            tmp.push_back(arr[i]);
            findUniqueCombn(i,comb,target-arr[i],tmp,arr);
            tmp.pop_back();
        }
        findUniqueCombn(i+1,comb,target,tmp,arr);
        
    }
};

// class Solution {
// public:
//     void combinationSum(vector<int>& candidates, int target,vector<vector<int>> &sol,vector<int>&tmp,int start=0){
//         if (target==0){
//             sol.push_back(tmp);
//             return;
//         }
//         for(int i= start;i<candidates.size();i++){
//             if (candidates[i]<=target){
//                 tmp.push_back(candidates[i]);
//                 combinationSum(candidates,target-candidates[i],sol,tmp,i);
//                 tmp.pop_back();
//             }
//         }

//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int>> sol={};
//         vector<int>tmp={};
//         combinationSum(candidates,target,sol,tmp);
//         return sol;
//     }
// };
