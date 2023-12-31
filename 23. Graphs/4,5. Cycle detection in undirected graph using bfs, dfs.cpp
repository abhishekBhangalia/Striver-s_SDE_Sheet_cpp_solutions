#include <bits/stdc++.h>

// //Using BFS
// TC-O(n+m), SC-O(n)
// string cycleDetection (vector<vector<int>>& edges, int n, int m)
// {
//     vector<vector<int>> adjList(n+1,vector<int>());
//     vector<int> vis(n+1);

//     for(vector<int>& edge:edges){
//         adjList[edge[0]].push_back(edge[1]);
//         adjList[edge[1]].push_back(edge[0]);
//     }

    
//     for(int v=1; v<=n; v++){
//         if(vis[v] == 0){
//             vis[v] = 1;
//             queue<pair<int,int>> q;
//             q.push({v,-1});

//             while(not q.empty()){
//                 int vtx = q.front().first;
//                 int par = q.front().second;
//                 q.pop();

//                 for(int& adj_vtx:adjList[vtx]){
//                     if(adj_vtx != par and vis[adj_vtx]){
//                         return "Yes";
//                     }
//                     else if(vis[adj_vtx] == 0){
//                         vis[adj_vtx] = 1;
//                         q.push({adj_vtx, vtx});
//                     }
//                 }
//             }
//         }
//     }
//     return "No";
// }


//Using DFS
//TC-O(n+m), SC-O(n)
bool rec(int vtx, int par, vector<vector<int>>& adjList, vector<int>& vis){
    vis[vtx] = 1;

    for(int& x: adjList[vtx]){
        if(x != par and vis[x]){
            return true;
        }
        else if(vis[x] == 0){
            if(rec(x, vtx, adjList, vis)){
                return true;
            }
        }
    }
    return false;
}

//Using DFS
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> adjList(n+1,vector<int>());
    vector<int> vis(n+1);

    for(vector<int>& edge:edges){
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    bool ans;
    for(int v=1; v<=n; v++){
        if(vis[v] == 0){
            ans = rec(v, -1, adjList, vis);
            if(ans){
                return "Yes";
            }
        }
    }
    return "No";
}




