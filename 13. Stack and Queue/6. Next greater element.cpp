class Solution {
public:

    // // Brute Force TC-O(n*m), SC-O(1)
    // vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    //     int n=nums1.size();
    //     int m = nums2.size();
    //     int j=0;
    //     vector<int> ans(n);

    //     for(int i=0; i<n; i++){
    //         for(j=0; j<m; j++){
    //             if(nums1[i]==nums2[j]){
    //                 j++;
    //                 break;
    //             }
    //         }
    //         for(; j<m; j++){
    //             if(nums2[j]>nums1[i]){
    //                 break;
    //             }
    //         }
    //         if(j<m) ans[i] = nums2[j];
    //         else    ans[i] = -1;
    //     }
    //     return ans;
    // }



    // Stack TC- less than O(m*m)+O(n), SC-O(m)
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m = nums2.size();
        int j=0;
        vector<int> ans(n);
        unordered_map<int,int> map;
        stack<int> st;
        st.push(nums2[m-1]);
        map[nums2[m-1]] = -1;

        for(int i=m-2; i>=0; i--){
            while(not st.empty() and st.top()<=nums2[i])     st.pop();
            if(st.empty())  map[nums2[i]] = -1;
            else    map[nums2[i]] = st.top();
            st.push(nums2[i]);
        }

        for(int i=0; i<n; i++){
            ans[i] = map[nums1[i]];
        }
        return ans;
    }
};
