
//TC-O(4^(m*n)), SC-O(m*n)

void rec(int r,int c, string& path, vector<string>& paths, vector<vector<int>>& mat, vector<vector<int>>& vis){
    int n = mat.size();
    if(r==n-1 and c==n-1){
        paths.push_back(path);
        return;
    }

    //Moving in alphabetical directions so that the paths will be alphabetically ordered
    //Down
    if(r<n-1 and vis[r+1][c] == 0 and mat[r+1][c] ){
        path.push_back('D');
        vis[r][c] = 1;
        rec(r+1, c, path, paths, mat, vis);
        path.pop_back();
        vis[r][c] = 0;
    }

    //Left
    if(c>0 and vis[r][c-1]==0 and mat[r][c-1] ){
        path.push_back('L');
        vis[r][c] = 1;
        rec(r, c-1, path, paths, mat, vis);
        path.pop_back();
        vis[r][c] = 0;
    }

    //Right
    if(c<n-1 and vis[r][c+1]==0 and mat[r][c+1] ){
        path.push_back('R');
        vis[r][c] = 1;
        rec(r, c+1, path, paths, mat, vis);
        path.pop_back();
        vis[r][c] = 0;
    }

    //Up
    if(r>0 and vis[r-1][c]==0 and mat[r-1][c] ){
        path.push_back('U');
        vis[r][c] = 1;
        rec(r-1, c, path, paths, mat, vis);
        path.pop_back();
        vis[r][c] = 0;
    }

    
}


vector<string> ratMaze(vector<vector<int>> &mat) {
    // Write your code here.
    int n=mat.size();
    vector<string> paths;
    vector<vector<int>> vis(n, vector<int>(n));
    if(mat[n-1][n-1] == 0)  return paths;

    string path = "";
    rec(0, 0, path, paths, mat, vis);
    return paths;
}
