#include <bits/stdc++.h> 

// // TC-O(n*k log(k)), SC-O(k)?
// vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
// {
//     // Write your code here.
//     vector<int> ans;
//     priority_queue<int, vector<int>, greater<int>> pq;
//     int i=0;
//     int n = kArrays.size();

//     while(true){
//         int f = false;
//         for(int j=0; j<n; j++){
//             if(i<kArrays[j].size()){
//                 f=true;
//                 pq.push(kArrays[j][i]);
//             }
//         }
//         i++;
//         if(f==false)    break;
//         ans.push_back(pq.top());
//         pq.pop();
//     }

//     while(! pq.empty()){
//         ans.push_back(pq.top());
//         pq.pop();
//     }
//     return ans;
    
// }

// TC-O(n*k log(k)), SC-O(k)
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here.
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
    int i=0;
    int n = kArrays.size();

    for(int j=0; j<n; j++){
        pq.push({kArrays[j][0],{j,0}});
    }

    while(not pq.empty()){
        ans.push_back(pq.top().first);
        int list = pq.top().second.first;
        int next_id = pq.top().second.second + 1; 
        pq.pop();
        if(next_id < kArrays[list].size())
            pq.push({kArrays[list][next_id],{list,next_id}});
    }

    return ans;
    
}

