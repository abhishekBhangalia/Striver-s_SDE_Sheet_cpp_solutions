auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {
public:

    void dfs(int r, int c, vector<vector<char>>& grid){
        grid[r][c] = '0';

        //right
        int right_col = c+1;
        if(right_col < grid[0].size() and grid[r][right_col] == '1'){
            dfs(r, right_col, grid);
        }
        //down
        int down_row = r+1;
        if(down_row < grid.size() and grid[down_row][c] == '1'){
            dfs(down_row, c, grid);
        }
        //up
        int up_row = r-1;
        if(up_row >= 0 and grid[up_row][c] == '1'){
            dfs(up_row, c, grid);
        }
        //left
        int left_col = c-1;
        if(left_col>=0 and grid[r][left_col] == '1'){
            dfs(r, left_col, grid);
        }
    }

    // void dfs(int r, int c, vector<vector<char>>& grid){
    //     grid[r][c] = '0';

    //     //right
    //     if(c+1 < grid[0].size() and grid[r][c+1] == '1'){
    //         dfs(r, c+1, grid);
    //     }
    //     //down
    //     if(r+1 < grid.size() and grid[r+1][c] == '1'){
    //         dfs(r+1, c, grid);
    //     }
    //     //up
    //     if(r-1 >= 0 and grid[r-1][c] == '1'){
    //         dfs(r-1, c, grid);
    //     }
    //     //left
    //     if(c-1>=0 and grid[r][c-1] == '1'){
    //         dfs(r, c-1, grid);
    //     }
    // }



    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int islands = 0;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(i, j, grid);
                }
            }
        }
        return islands;
    }
};



