auto fast = [](){
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);
    return 0;
}();

class Solution {
public:


    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        while(slow != fast);

        fast = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }


    // int findDuplicate(vector<int>& nums) {
    //     for (int i = 0; i < nums.size(); ++i) {
    //         int num = abs(nums[i]);
    //         if (nums[num] < 0) {
    //             return num;
    //         }
    //         nums[num] = -nums[num];
    //     }
    //     return -1;
    // }
};
