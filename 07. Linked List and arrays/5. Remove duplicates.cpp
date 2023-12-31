class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //int k=nums.size();
        int n = nums.size();
        for(int i=1; i<n; i++){
            while(nums[i] ==nums[i-1] and i < n){
                //k++;
                for(int j =i;j < n-1;j++){
                    nums[j]=nums[j+1];
                    
                }
                n--;
                
            }
            //i--;
        }
        return n;
    }
};
