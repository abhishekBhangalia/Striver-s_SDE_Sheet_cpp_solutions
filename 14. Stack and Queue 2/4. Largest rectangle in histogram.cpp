class Solution {
public:
    // Brute Force(TLE), TC-O(n(n+1)/2) = O(n^2), SC-O(1)
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxi = 0;
    //     int n = heights.size();
    //     for(int i=0; i<n; i++){
    //         maxi = max(maxi,heights[i]);
    //         int mini = heights[i];
    //         for(int j=i-1; j>=0; j--){
    //             mini = min(mini,heights[j]);
    //             maxi = max(maxi,mini*(i-j+1));
    //         }
    //     }
    //     return maxi;
    // }


    // //TC-O(5n), SC-O(3n)
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxi = 0;
    //     int n = heights.size();
    //     int left_min[n], right_min[n];
    //     vector<int> st;

    //     left_min[0] = 0;
    //     st.push_back(0);
    //     for(int i=1; i<n; i++){
    //         while(not st.empty() and heights[st.back()] >= heights[i])   st.pop_back();
    //         if(not st.empty())  left_min[i] = st.back()+1;
    //         else    left_min[i] = 0;
    //         st.push_back(i);
    //     }

    //     st.clear();
    //     right_min[n-1] = n-1;
    //     st.push_back(n-1);
    //     for(int i=n-2; i>=0; i--){
    //         while(not st.empty()  and heights[st.back()] >= heights[i])   st.pop_back();
    //         if(not st.empty())  right_min[i] = st.back()-1;
    //         else    right_min[i] = n-1;
    //         st.push_back(i);
    //     }

    //     //This loop can be removed and maxi can be calculated in previous for loop also.
    //     for(int i=0; i<n; i++){
    //         maxi = max((right_min[i]-left_min[i]+1)*heights[i],maxi);
    //     }
    //     return maxi;
    // }


    // //TC-O(2n), SC-O(n)
    // int largestRectangleArea(vector<int>& heights) {
    //     int maxi = 0;
    //     int n = heights.size();
    //     stack<pair<int,int>> st;
    //     pair<int,int> left_min, right_min, cur;
    //     st.push({heights[0],0});

    //     for(int i=1; i<n; i++){
    //         right_min = {heights[i],i};
    //         while(st.top().first >= heights[i]){
    //             cur = st.top();
    //             st.pop();
    //             if(st.empty()){
    //                 maxi = max(maxi, right_min.second * cur.first);
    //                 break;
    //             }
    //             else{
    //                 maxi = max(maxi, (right_min.second-st.top().second-1)*cur.first);
    //             }
    //         }
    //         st.push({heights[i],i});
    //     }
        
    //     while(not st.empty()){
    //         cur = st.top();
    //         st.pop();
    //         if(st.empty()){
    //             maxi = max(maxi, n*cur.first);
    //         }
    //         else{
    //             maxi = max(maxi,(n-st.top().second-1)*cur.first);
    //         }
    //     }
    //     return maxi;
    // }


    //TC-O(2n), SC-O(n)
    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0;
        int n = heights.size();
        stack<int> st;
        
        for(int i=0; i<=n; i++){
            while(not st.empty() and (i == n or heights[st.top()] >= heights[i])){
                int height = heights[st.top()];
                st.pop();
                if(st.empty())  maxi = max(maxi, i * height);
                else    maxi = max(maxi, (i-st.top()-1)*height);
            }
            st.push(i);
        }
        return maxi;
    }
};
