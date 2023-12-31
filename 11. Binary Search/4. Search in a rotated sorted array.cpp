class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=-1;
        int l=0,h=nums.size()-1;
        while(l<=h){
            int mid = (l+h)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[l]<=nums[mid]){//left half is sorted 
                if(nums[l]<=target and target <= nums[mid] ){
                    h = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{//right half is sorted
                if(nums[mid]<=target and target <= nums[h]){
                    l = mid+1;
                }
                else{
                    h = mid-1;
                }
            }
        }
        return i;
    }
};  
