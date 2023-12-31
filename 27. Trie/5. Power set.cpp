#include <bits/stdc++.h> 

//TC-O(2^n * n), SC-O(1)
vector<vector<int>> pwset(vector<int>v)
{
    int n = v.size();
    int e = (1<<n) - 1; // 2^n - 1
    vector<vector<int>> ans;

    //O(2^n)
    for(int i=0; i<=e; i++){
        vector<int> tmp;
        //O(n)
        for(int b = 0; b<n; b++){
            if((i & (1<<b)) != 0){// if bth bit is set
                tmp.push_back(v[b]);
            }
        }
        ans.push_back(tmp);
    }
    return ans;
}
