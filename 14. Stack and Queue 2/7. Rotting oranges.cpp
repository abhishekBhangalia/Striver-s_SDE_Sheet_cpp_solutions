class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time=0;
        int fresh_oranges=0;
        int r=grid.size();
        int c=grid[0].size();

        queue<pair<int,int>> st;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++){
                if(grid[i][j]==1)
                    fresh_oranges++;
                if(grid[i][j]==2)
                    st.push({i,j});
            }
            
        if(fresh_oranges != 0){
            // while(!st.empty() and fresh_oranges>0){
            while(!st.empty()){
                time++;
                int size = st.size();
                while(size--){
                    pair<int,int> orng = st.front();
                    st.pop();

                    int nr = orng.first-1;
                    int nc = orng.second;
                    if(nr>=0 and grid[nr][nc] == 1){
                        fresh_oranges--;
                        grid[nr][nc] = 2;
                        st.push({nr,nc});
                    }

                    nr = orng.first+1;
                    nc = orng.second;
                    if(nr<r and grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        st.push({nr,nc});
                        fresh_oranges--;
                    }

                    nr = orng.first;
                    nc = orng.second-1;
                    if(nc>=0 and grid[nr][nc]==1){
                        grid[nr][nc] = 2;
                        st.push({nr,nc});
                        fresh_oranges--;
                    }
                    nr = orng.first;
                    nc = orng.second+1;
                    if(nc<c and grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        st.push({nr,nc});
                        fresh_oranges--;
                    }
                }
            }
        }
        if(fresh_oranges!=0){
            return -1;
        }
        return time==0?0:time-1;
    }
};
