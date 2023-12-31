class Solution {
public:

    // // Brute Force(TLE), TC-O(n^2), SC-O(1)
    // int maxProduct(vector<int>& nums) {
    //     int max_product = nums[0];
    //     int prod=1;
    //     for(int i=0; i<nums.size(); i++){
    //         prod=1;
    //         for(int j=i; j<nums.size(); j++){
    //             prod *= nums[j];
    //             max_product = max(max_product,prod);
    //         }
    //     }
    //     return max_product;
    // }



    // Brute Force(TLE), TC-O(n^2), SC-O(1)
    int maxProduct(vector<int>& a) {
        int max_prod = INT_MIN;
        int prefix=1;
        int suffix=1;
        int n=a.size();

        for(int i=0; i<n; i++){
            prefix *= a[i];
            suffix *= a[n-1-i];
            
            max_prod = max(max_prod,max(prefix,suffix));
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
        }

        return max_prod;
    }
};
