class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int rows = graph.size();
        vector<int> color(rows,-1);
        for(int i=0; i<rows; i++)
            if(color[i]==-1){
                color[i]=0;
                if(dfs(i,graph,color))
                    return false;
            }
                
            
        return true;
    }

    bool bfs(int start,vector<vector<int>>& adj, vector<int>& color){
        color[start] = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:adj[u]){
                if(color[v]==-1){
                    color[v] = 1-color[u];
                    q.push(v);
                }
                else if(color[v]==color[u]){

                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(int start,vector<vector<int>>& adj, vector<int>& color){
        
        for(int v:adj[start]){
            if(color[v]==-1){
                color[v]=1-color[start];
                if(dfs(v,adj,color))
                    return true;
            }
            else if(color[v]==color[start]){
                return true;
            }
        }
        return false;
    }


};
