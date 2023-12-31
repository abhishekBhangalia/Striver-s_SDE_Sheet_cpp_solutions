class Solution {
public:

    // //TC-O(3*r*c), SC- O(r+c)
    // void setZeroes(vector<vector<int>>& matrix) {
    //     unordered_set<int> rows;
    //     unordered_set<int> cols;

    //     //O(r*c)
    //     for(int r=0; r<matrix.size(); r++){
    //         for(int c=0; c<matrix[0].size(); c++){
    //             if(matrix[r][c]==0){
    //                 rows.insert(r);
    //                 cols.insert(c);
    //             }
    //         }
    //     }

    //     //O(r*c)
    //     for(auto row:rows){
    //         for(int col = 0; col<matrix[0].size(); col++){
    //             matrix[row][col] = 0;
    //         }
    //     }


    //     //O(c*r)
    //     for(auto col:cols){
    //         for(int row = 0; row<matrix.size(); row++){
    //             matrix[row][col] = 0;
    //         }
    //     }
    // }


    // //TC-O(2*r*c), SC- O(r+c)
    // void setZeroes(vector<vector<int>>& matrix) {
        
    //     vector<int> rows(matrix.size(),0), cols(matrix[0].size(),0);
    //     //O(r*c)
    //     for(int r=0; r<matrix.size(); r++){
    //         for(int c=0; c<matrix[0].size(); c++){
    //             if(matrix[r][c]==0){
    //                 rows[r]=1;
    //                 cols[c]=1;
    //             }
    //         }
    //     }

    //     //O(r*c)
    //     for(int r=0; r<matrix.size(); r++){
    //         for(int c=0; c<matrix[0].size(); c++){
    //             if(rows[r] || cols[c]){
    //                 matrix[r][c] = 0;
    //             }
    //         }
    //     }
    // }




    //TC-O(2*r*c), SC- O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        
        int col_0 = 1;
        int rows = matrix.size(),cols = matrix[0].size();
        //O(r*c)
        for(int r=0; r<matrix.size(); r++){
            for(int c=0; c<matrix[0].size(); c++){
                if(matrix[r][c]==0){
                    matrix[r][0] = 0;
                    if(c==0){
                        col_0 = 0;
                    }
                    else{
                        matrix[0][c] = 0;
                    }
                }
            }
        }

        //O(r*c)
        for(int r=rows-1; r>0; r--){
            for(int c=cols-1; c>0; c--){
                if(matrix[r][0]==0 || matrix[0][c]==0){
                    matrix[r][c] = 0;
                }
            }
        }
        if(matrix[0][0]==0){
            for(int col=1; col<cols; col++){
                matrix[0][col] = 0;
            }
        }
        if(col_0 == 0){
            for(int row=0; row<rows; row++){
                matrix[row][0] = 0;
            }
        }
    }
    
};
