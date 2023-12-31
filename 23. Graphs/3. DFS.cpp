class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // int n = adj.size();
        vector<int> ans;
        vector<int> vis(V);
        
        // we have to consider only nodes connected directly or indirectly to node 0
        // for(int i=0; i<V; i++){
        //     if(vis[i] == 0){
                
                queue<int> q; 
                q.push(0);
                
                while(not q.empty()){
                    int size = q.size();
                    while(size--){
                        if(vis[q.front()] == 0){
                            vis[q.front()] = 1;
                            ans.push_back(q.front());
                            for(int x:adj[q.front()]){
                                q.push(x);
                            }
                        }
                        q.pop();
                    }
                }
        //     }
        // }
        
        return ans;
    }
};
