class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> row(board.size(),vector<int>(1)), col(board.size(),vector<int>(1));
        solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for(int r=0; r<board.size(); r++){
            for(int c=0; c<board[0].size(); c++){
                if(board[r][c] == '.'){
                    for(char i='1'; i<='9'; i++){
                        if (can_place(r,c,i,board)){
                            
                            board[r][c] = i;
                            if(solve(board)){
                                return true;
                            }
                            board[r][c] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool can_place(int r, int c,char k, vector<vector<char>>& board){
        for( int i=0; i<board.size(); i++)
            if(board[r][i] == k or board[i][c] == k or board[(r/3)*3+i/3][(c/3)*3+i%3] == k)
                return false;
            

        // if(0<=r and r<3){
        //     if(0<=c and c<3){
        //         for(int i=0; i<3; i++)
        //             for(int j=0; j<3; j++)
        //                 if(board[i][j] == k)
        //                     return false;

        //     }
                
                     
        //     else if(2<c and c<6){
        //         for(int i=0; i<3; i++)
        //             for(int j=3; j<6; j++)
        //                 if(board[i][j] == k)
        //                     return false;

        //     }
                

        //     else{
        //         for(int i=0; i<3; i++)
        //             for(int j=6; j<9; j++)
        //                 if(board[i][j] == k)
        //                     return false;

        //     }
                

        // }
            

            
        
        // else if(2<r and r<6){
        //     if(0<=c and c<3){
        //         for(int i=3; i<6; i++)
        //             for(int j=0; j<3; j++)
        //                 if(board[i][j] == k)
        //                     return false;

        //     }
                

            
        //     else if(2<c and c<6){
        //         for(int i=3; i<6; i++)
        //             for(int j=3; j<6; j++)
        //                 if(board[i][j] == k)
        //                     return false;


        //     }
                
            
        //     else{
        //         for(int i=3; i<6; i++)
        //             for(int j=6; j<9; j++)
        //                 if(board[i][j] == k)
        //                     return false;
        //     }
                
                
        // }
            
            
        
        // else if(5<r and r<9){
        //     if(0<=c and c<3){
        //         for(int i=6; i<9; i++)
        //             for(int j=0; j<3; j++)
        //                 if(board[i][j] == k)
        //                     return false;

        //     }
                

            
        //     else if(2<c and c<6){
        //         for(int i=6; i<9; i++)
        //             for(int j=3; j<6; j++)
        //                 if(board[i][j] == k)
        //                     return false;

        //     }
                

            
        //     else{
        //         for(int i=6; i<9; i++)
        //             for(int j=6; j<9; j++)
        //                 if(board[i][j] == k)
        //                     return false;

        //     }
                
        // }
            
                
        return true;
    }
};
