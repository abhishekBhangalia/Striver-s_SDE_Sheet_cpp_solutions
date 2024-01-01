#include <stack> 

// Brute Force(heap) TLE, TC-O(n^2 * log n )
// vector<int> maxMinWindow(vector<int> a, int n) {
//     // Write your code here.
    // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    // vector<int> ans;
    // for(int win_size = 1; win_size<=n; win_size++){
    //     int maxi = INT_MIN;
    //     while(not pq.empty())   pq.pop();
    //     for(int i=0; i<win_size; i++){
    //         pq.push({a[i],i});
    //     }
    //     maxi = max(maxi,pq.top().first);
    //     for(int i=win_size; i<n; i++){
    //         pq.push({a[i],i});
    //         while(pq.top().second<=i-win_size)   pq.pop();
    //         maxi = max(maxi,pq.top().first);
    //     }
    //     ans.push_back(maxi);
    // }
//     return ans;
// }

// // TC-O(n*(n+1)/2)
// vector<int> maxMinWindow(vector<int> a, int n) {
//     // Write your code here.
//     vector<int> ans;
//     ans.push_back(*max_element(a.begin(),a.end()));
//     for(int win_size = 2; win_size<=n; win_size++){
//         int maxi = INT_MIN;
//         for(int i=0; i<n-win_size+1; i++){
//             a[i] = min(a[i],a[i+1]);
//             maxi = max(maxi, a[i]);
//         }
//         ans.push_back(maxi);
//     }
//     return ans;
// }

//TC-O(3n), SC-O(2n)
vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
    vector<int> ans(n,INT_MIN);

    int next_min[n], prev_min[n];
    stack<int> st;
    st.push(0);
    prev_min[0] = -1;
    for(int i=1; i<n; i++){
        while(not st.empty() and a[st.top()]>=a[i]) st.pop();
        if(st.empty())  prev_min[i] = -1;
        else    prev_min[i] = st.top();
        st.push(i);
    }

    stack<int> st2;
    st2.push(n-1);
    next_min[n-1] = n;
    for(int i=n-2; i>=0; i--){
        while(not st2.empty() and a[st2.top()] >= a[i])   st2.pop();
        if(st2.empty()) {
            next_min[i] = n;
        }
        else    next_min[i] = st2.top();
        st2.push(i);
    }

    
    for(int i=0; i<n; i++){
        int win_size = next_min[i]-prev_min[i]-2;
        ans[win_size] = max(ans[win_size], a[i]);
    }

    for(int i=n-2; i>=0; i--){
        ans[i] = max(ans[i],ans[i+1]);
    }
    
    return ans;
}


// /*
//     Time Complexity: O(N)
// 	Space complexity: O(N)

// 	Where 'N' is the number elements present in the given array.
//  */


// // This function will return an array.
// // Each ith position contains the index of previous smaller elements in the original array.
// vector<int> previousSmaller(vector<int> &arr, int n) 
// {
//     vector<int> prev(n);
//     stack<int> s;

//     for (int i = 0; i < n; i++) 
//     {
//         while (!s.empty() && arr[s.top()] >= arr[i]) 
//         {
//             s.pop();
//         }
        
//         if (s.empty()) 
//         {
//             prev[i] = -1;
//         } 
//         else 
//         {
//             prev[i] = s.top();
//         }

//         s.push(i);
//     }
    
//     return prev;
// }

// // This function will return an array.
// // Each ith position contains the index of next smaller elements in the original array.
// vector<int> nextSmaller(vector<int> &arr, int n) 
// {
//     stack<int> s;
//     vector<int> next(n);

//     for (int i = n - 1; i >= 0; i--) 
//     {
//         while (!s.empty() && arr[s.top()] >= arr[i]) 
//         {
//             s.pop();
//         }
        
//         if (s.empty()) 
//         {
//             next[i] = n;
//         } 
//         else 
//         {
//             next[i] = s.top();
//         }
    
//         s.push(i);
//     }
    
//     return next;
// }

// vector<int> maxMinWindow(vector<int> &arr, int n) 
// {
//     // Definition: answer[i] will store the maximum of minimum of every window of size 'i'.
//     vector<int> answer(n, INT_MIN);

//     // Definition: next[i] will store the index of next smaller element which lie on the right hand side of 'i'.
//     vector<int> next = nextSmaller(arr, n);

//     // Definition: prev[i] will store the index of previous smaller element which lie on the left hand side of 'i'.
//     vector<int> prev = previousSmaller(arr, n);

//     for (int i = 0; i < n; i++) 
//     {
//         // Length of the window in which a[i] is minimum
//         int length = next[i] - prev[i] - 1;

//         // Update the answer[length-1] ( 0 based indexing )  with a[i]
//         answer[length - 1] = max(answer[length - 1], arr[i]);
//     }

// 	// Some entries in answer[] may not be filled yet.
// 	// We fill them by taking maximum element from suffix starting from 'i'.
//     for (int i = n - 2; i >= 0; i--) 
//     {
//         answer[i] = max(answer[i], answer[i + 1]);
//     }

//     return answer;
// }


