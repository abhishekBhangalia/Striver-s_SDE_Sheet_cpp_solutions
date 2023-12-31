class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > min_heap;
        int min_cost = 0;
        vector<int> vis(V);
        
        //this is not needed in this question
        //this is used to store the edges of mst
        vector<pair<int,int>> mst;
        
        //inside min heap each vector v has three elements
        //v[0] = weight, v[1] = vertex, v[2] = parent i.e edge is v[2]->v[1] with weight v[0]
        //at first we will push the start vertex
        min_heap.push({0,0,-1});
        
        
        while(not min_heap.empty()){
            vector<int> min_edge = min_heap.top();
            min_heap.pop();
            if(vis[min_edge[1]] == 0){
                vis[min_edge[1]] = 1;
                if(min_edge[2] != -1){
                    mst.push_back({min_edge[2], min_edge[1]});
                }
                min_cost += min_edge[0];
                for(vector<int>& a: adj[min_edge[1]]){
                    if(vis[a[0]] == 0){
                        min_heap.push({a[1], a[0], min_edge[1]});
                    }
                }
            }
        }
        
        return min_cost;
    }
};
