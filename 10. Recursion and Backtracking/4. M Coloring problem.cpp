//TC-O(v)

bool can_color(int vertex, int color, vector<int>& colors, vector<vector<int>>& mat){
    int vertices = mat[0].size();
    for(int vtx = 0; vtx<vertices; vtx++){
        if(vtx != vertex and mat[vertex][vtx] and colors[vtx] == color)    return false;
    }
    return true;
}

// TC :
// O(M ^ V + M * V * V) where V is the number of vertices in the graph and M is the maximum number of colors allowed. 
// This is because for each node, there are M possibilities to color it and there are V nodes, which gives us M *...* M (V times) = M ^ V. Also, we iterate the adjacency matrix for each of the M colors which adds an extra complexity of M * V * V, which leads to the total time complexity of O(M ^ V + M * V * V).
// Although the worst-case time complexity would be the same as brute force, the average time complexity would be better than the brute force method.

//SC-O(v)
bool rec(int vertex, vector<int>& colors, vector<vector<int>>& mat,int m){
    if(vertex == mat.size()){
        return true;
    }

    //O(m * v)
    for(int c = 1; c<=m; c++){
        if(can_color(vertex, c, colors, mat)){
            colors[vertex] = c;
            if (rec(vertex+1, colors, mat, m)) return true;
            colors[vertex] = 0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    vector<int> colors(mat.size());
    if(rec(0, colors, mat, m))  return "YES";
    else    return "NO";
}
