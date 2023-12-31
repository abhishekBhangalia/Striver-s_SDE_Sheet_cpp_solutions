class Solution {
public:
//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         int old_color = image[sr][sc];
//         if(old_color == color)
//             return image;

//         int n = image.size(); //total rows
//         int m = image[0].size(); // total columns

//         stack<pair<int,int>> st;
//         st.push({sr,sc});
//         image[sr][sc]=color;

//         while(!st.empty()){
//             pair<int,int> pxl = st.top();
//             st.pop();
            
//             vector<int> dr = {0,0,1,-1};
//             vector<int> dc = {1,-1,0,0};

//             for(int i=0; i<4; i++){
                
//                 int nr = pxl.first+dr[i];
//                 int nc = pxl.second+dc[i];

//                 if(0<=nr and nr<n and 0<=nc and nc<m and image[nr][nc] == old_color){
//                     image[nr][nc] = color;
//                     st.push({nr,nc});
//                 }
//             }
            
//         }
//         return image;
//     }


    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        if(old_color == color)
            return image;

        int n = image.size(); //total rows
        int m = image[0].size(); // total columns

        stack<pair<int,int>> st;
        st.push({sr,sc});
        image[sr][sc]=color;

        while(!st.empty()){
            pair<int,int> pxl = st.top();
            st.pop();
            
            if(0<pxl.first and image[pxl.first-1][pxl.second] == old_color){
                image[pxl.first-1][pxl.second] = color;
                st.push({pxl.first-1,pxl.second});
            }
            if(pxl.first<n-1 and image[pxl.first+1][pxl.second] == old_color){
                image[pxl.first+1][pxl.second] = color;
                st.push({pxl.first+1,pxl.second});
            }
            if(0<pxl.second and image[pxl.first][pxl.second-1] == old_color){
                image[pxl.first][pxl.second-1] = color;
                st.push({pxl.first,pxl.second-1});
            }
            if(pxl.second<m-1 and image[pxl.first][pxl.second+1] == old_color){
                image[pxl.first][pxl.second+1] = color;
                st.push({pxl.first,pxl.second+1});
            }
            
        }
        return image;
    }
};
