class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> tmp(n,string(n,'.'));
        vector<int> c(n,1),ul(2*n-1,1),ur(2*n-1,1);
        solve(ans,tmp,0,c,ul,ur,n);
        return ans;
    }

    void solve(vector<vector<string>>& ans,vector<string>& tmp, int r,vector<int>& col, vector<int>& ul, vector<int>& ur,int n){
        if(r == n){
            ans.push_back(tmp);
            return;
        }
        for(int c=0; c<n; c++){
            if(col[c] && ul[n-1+c-r] && ur[c+r]){
                tmp[r][c]='Q';
                col[c] = 0;
                ul[n-1+c-r] = 0;
                ur[c+r] = 0;
                solve(ans,tmp,r+1,col,ul,ur,n);
                tmp[r][c]='.';
                col[c] = 1;
                ul[n-1+c-r] = 1;
                ur[c+r] = 1;
            }
        }
    }
};
