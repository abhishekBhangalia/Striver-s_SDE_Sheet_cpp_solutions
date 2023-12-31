class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=1,h=nums.size()-2;
        if(nums.size()==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]){
            return nums[0];
        }
        if(nums[h+1]!=nums[h]){
            return nums[h+1];
        }
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid-1]!=nums[mid] and nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if((mid%2 == 0 and nums[mid+1] == nums[mid]) or (mid%2!=0 and nums[mid] == nums[mid-1])){//left block
                l=mid+1;
            }
            // if((mid%2 != 0 and nums[mid+1] == nums[mid]) or (mid%2==0 and nums[mid] == nums[mid-1])){//right block
            //     h=mid-1;
            // }
            else{
                h=mid-1;
            }
        }
        return -1;
    }
};
