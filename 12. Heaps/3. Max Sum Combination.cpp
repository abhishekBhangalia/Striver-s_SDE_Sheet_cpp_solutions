
// TC-O(2n log 2n) + O(7C log 2C )
// SC-O(5C)
vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int n = A.size();
    
    // O(2n log 2n)
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({A[0]+B[0],{0,0}});
    
    // vector<vector<int>> vis(n, vector<int>(n,0));
    // vis[0][0] = 1;
    
    set<pair<int,int>> s;
    
    vector<int> ans;
    
    //O(C * 7 * log 2C)
    while(C--){
        ans.push_back(pq.top().first);
        pair<int,int> ids = pq.top().second;
        pq.pop();
        
        // 2d array vis will take O(n^2) time
        
        // if(ids.first+1 < n and vis[ids.first+1][ids.second] == 0){
        //     vis[ids.first+1][ids.second] = 1;
        //     pq.push({A[ids.first+1] + B[ids.second], {ids.first+1, ids.second}});
        // }
        
        // if(ids.second+1 < n and vis[ids.first][ids.second+1] == 0){
        //     vis[ids.first][ids.second+1] = 1;
        //     pq.push({A[ids.first] + B[ids.second+1], {ids.first, ids.second+1}});
        // }
        
        
        if(ids.first+1 < n and s.find({ids.first+1,ids.second})==s.end()){
            s.insert({ids.first+1,ids.second});
            pq.push({A[ids.first+1] + B[ids.second], {ids.first+1, ids.second}});
        }
        
        if(ids.second+1 < n and s.find({ids.first,ids.second+1})==s.end()){
            s.insert({ids.first,ids.second+1});
            pq.push({A[ids.first] + B[ids.second+1], {ids.first, ids.second+1}});
        }
        
    }
    return ans;
}
