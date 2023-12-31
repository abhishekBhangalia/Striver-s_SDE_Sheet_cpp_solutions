class Solution {
public:


    //BFS, Kahn's Algo, using topological sort
    //TC-O(v+e), SC-O(v+e) + O(2v) + O(v) stack space
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses,vector<int>());
        // int inc[numCourses] = {0};
        vector<int> inc(numCourses,0);
        
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inc[prerequisites[i][0]] ++;
        }
        
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(inc[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            numCourses--;
            for(int v:adj[u]){
                if(--inc[v]==0){
                    q.push(v);
                }
            }
        }
        
        if(numCourses!=0){
            return false;
        }

        return true;
    }



    // //DFS
    // //TC-O(v+e), SC-O(v+e) + O(2v) + O(v) stack space
    // //recursive function to check whether there is a cycle or not
    // bool rec_visit(int i, vector<vector<int>>& adjList, vector<int>& vis, vector<int>& dfs_visit){
    //     vis[i] = 1;
    //     dfs_visit[i] = 1;

    //     for(int& v:adjList[i]){
    //         if(dfs_visit[v]){
    //             return true;
    //         }
    //         else {
    //             if(rec_visit(v, adjList, vis, dfs_visit)){
    //                 return true;
    //             }
    //         }

    //     }
    //     dfs_visit[i] = 0;
    //     return false;
    // }

    
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int> vis(numCourses);
    //     vector<int> dfs_visit(numCourses);

    //     vector<vector<int>> adjList(numCourses, vector<int>());

    //     for(auto &p : prerequisites){
    //         adjList[p[1]].push_back(p[0]);
    //     }

    //     for(int c=0; c<numCourses; c++){
    //         if(not vis[c]){
    //             //if there is a cycle then we can't complete all courses
    //             if(rec_visit(c,adjList, vis, dfs_visit)){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
    // }


    //BFS
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses);
        vector<int> dfs_visit(numCourses);

        vector<vector<int>> adjList(numCourses, vector<int>());

        for(auto &p : prerequisites){
            adjList[p[1]].push_back(p[0]);
        }

        for(int c=0; c<numCourses; c++){
            if(not vis[c]){
                //if there is a cycle then we can't complete all courses
                if(rec_visit(c,adjList, vis, dfs_visit)){
                    return false;
                }
            }
        }
        return true;
    }


};
