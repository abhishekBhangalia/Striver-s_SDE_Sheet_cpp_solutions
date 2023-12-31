class Solution {
public:

    //TC-O(n^2), SC- O(1)
    // void rotate(vector<vector<int>>& matrix) {
    //     int n = matrix.size();
    //     for(int row=0;row<n;row++){
    //         for(int col=0; col<n-row-1; col++){
    //             swap(matrix[row][col],matrix[n-1-col][n-1-row]);
    //         }
    //     }

    //     //reverse all cols
    //     for(int row = 0; row<n/2; row++){
    //         for(int col = 0; col<n; col++){
    //             swap(matrix[row][col],matrix[n-1-row][col]);
    //         }
    //     }
    // }

    //TC-O(n^2), SC- O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        //O(n^2/2 - n)
        //Transpose Matrix
        for(int row=0;row<n-1;row++){
            for(int col=row+1; col<n; col++){
                swap(matrix[row][col],matrix[col][row]);
            }
        }

        //O(n^2/2)
        //reverse all cols
        for(int row = 0; row<n; row++){
            reverse(matrix[row].begin(),matrix[row].end());
        }
    }
};
