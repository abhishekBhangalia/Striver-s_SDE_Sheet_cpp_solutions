#include <bits/stdc++.h> 
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    
    vector<pair<double, int>> m;
    
    // for(int i = 0; i<items.size(); i++){
    //     m.push_back(make_pair(items[i].second/(1.0*items[i].first), i));
    // }
    
    int ind = 0;
    for(const auto &i : items){
        m.push_back(make_pair(i.second/(1.0*i.first), ind++));
    }
    
    sort(begin(m), end(m), greater<pair<double, int>>());
    double profit = 0;
    
    for(const auto & i : m){
        if(w > items[i.second].first){
            w -= items[i.second].first;
            profit += items[i.second].second;
        }
        else{
            profit += (w/(items[i.second].first * 1.0)) * items[i.second].second;
            break;
        }
    }
    
    return profit;
    
}
