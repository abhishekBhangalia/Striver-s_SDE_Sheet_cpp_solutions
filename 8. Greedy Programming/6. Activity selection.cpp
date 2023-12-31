#include <bits/stdc++.h>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> acts;
    int n = start.size();

    for(int i=0; i<n; i++){
        acts.push_back({finish[i], start[i]});
    }
    sort(acts.begin(), acts.end());

    int time = 0;
    int max_acts = 0;
    for(const auto& a:acts){
        if(a.second > time){
            time = a.first;
            max_acts++;
        }
    }
    return max_acts;
}

