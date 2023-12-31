#include <bits/stdc++.h> 

//TC-O(n), SC-O(k)
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	vector<int> ans;
    map<int, int> m;

    int n = arr.size();

    int distinct_elems = 0;
    for(int j=0; j<k; j++){
        m[arr[j]]++;
        if(m[arr[j]] == 1){
            distinct_elems++;
        }
    }
    ans.push_back(distinct_elems);

    for(int i=k; i<n; i++){
        m[arr[i]]++;
        if(m[arr[i]] == 1){
            distinct_elems++;
        }
        m[arr[i-k]]--;
        if(m[arr[i-k]] == 0){
            distinct_elems--;
        }
        ans.push_back(distinct_elems);
    }
    return ans;
}

