class Solution {
public:

    // Recursive Method
    // int superEggDrop(int e, int f) 
    // {
    //     if(e == 0 || f==0)  return 0;
    //     if(e==1)    return f;   // at worst case we will have to check all floors starting from floor 1 to f
        
    //     int min_moves = INT_MAX;
    //     for(int k = 1; k<=f; k++){
    //         int moves_if_egg_breaks = superEggDrop(e-1, k-1);
    //         int moves_if_egg_doesnt_break = superEggDrop(e, f-k);
    //         int cur_moves = 1 + max(moves_if_egg_breaks, moves_if_egg_doesnt_break);
    //         min_moves = min(cur_moves, min_moves);
    //     }
    //     return min_moves;
    // }
    

    //Memoization (TLE)
    // int rec(int e, int f, int dp[][10001]){
    //     if(dp[e][f] != -1)  return dp[e][f];
        
    //     if(e == 0)  return dp[e][f] = 0;
    //     if(f==0 || f==1)    return dp[e][f] = f;
    //     if(e==1)    return dp[e][f] = f;   // at worst case we will have to check all floors starting from floor 1 to f
        
    //     int min_moves = INT_MAX;
    //     for(int k = 1; k<=f; k++){
    //         int moves_if_egg_breaks = dp[e-1][k-1]!=-1 ? dp[e-1][k-1] : rec(e-1, k-1, dp);
    //         int moves_if_egg_doesnt_break = dp[e][f-k]!=-1 ? dp[e][f-k] : rec(e, f-k, dp);
            
    //         //Taking maximum of both values because we don't know whether egg will break or not
    //         //So, we will take worst case here to tell with certainty the min moves
    //         int cur_moves = 1 + max(moves_if_egg_breaks, moves_if_egg_doesnt_break);
            
    //         //We will take minimum of all the values that we will get after selecting a specific kth floor as first floor
    //         min_moves = min(cur_moves, min_moves);
    //     }
    //     return dp[e][f] = min_moves;
    // }
    

//    //Memoization with Binary Search
//    int rec(int e, int f, int** dp){
//        if(dp[e][f] != -1)  return dp[e][f];
//        
//        if(e == 0)  return dp[e][f] = 0;
//        if(f==0 || f==1)    return dp[e][f] = f;
//        if(e==1)    return dp[e][f] = f;   // at worst case we will have to check all floors starting from floor 1 to f
//        
//        int min_moves = INT_MAX;
//        int l=1, h = f;
//        while(l<=h){
//            int mid = (l+h)/2;
//            int moves_if_egg_breaks = dp[e-1][mid-1]!=-1 ? dp[e-1][mid-1] : rec(e-1, mid-1, dp);
//            int moves_if_egg_doesnt_break = dp[e][f-mid]!=-1 ? dp[e][f-mid] : rec(e, f-mid, dp);
//            
//            //Taking maximum of both values because we don't know whether egg will break or not
//            //So, we will take worst case here to tell with certainty the min moves
//            int cur_moves = 1 + max(moves_if_egg_breaks, moves_if_egg_doesnt_break);
//            
//            //We will take minimum of all the values that we will get after selecting a specific kth floor as first floor
//            min_moves = min(cur_moves, min_moves);
//
//            if(moves_if_egg_breaks < moves_if_egg_doesnt_break){
//                l = mid+1;
//            }
//            else{
//                h = mid-1;
//            }
//        }
//        return dp[e][f] = min_moves;
//    }
    
    // int superEggDrop(int e, int f) {
    //     int** dp = new int*[e+1];
    //     for(int i=0; i<=e; i++){
    //         dp[i] = new int[f+1];
    //         memset(dp[i], -1, sizeof(int)*(f+1));
    //     }
    //     return rec(e, f, dp);
    // }


    // int rec(int e, int f, int dp[][10001]){
    //     if(dp[e][f] != -1)  return dp[e][f];
        
    //     if(e == 0)  return dp[e][f] = 0;
    //     if(f==0 || f==1)    return dp[e][f] = f;
    //     if(e==1)    return dp[e][f] = f;   // at worst case we will have to check all floors starting from floor 1 to f
        
    //     int min_moves = INT_MAX;
    //     int l=1, h = f;
    //     while(l<=h){
    //         int mid = (l+h)/2;
    //         int moves_if_egg_breaks = dp[e-1][mid-1]!=-1 ? dp[e-1][mid-1] : rec(e-1, mid-1, dp);
    //         int moves_if_egg_doesnt_break = dp[e][f-mid]!=-1 ? dp[e][f-mid] : rec(e, f-mid, dp);
            
    //         //Taking maximum of both values because we don't know whether egg will break or not
    //         //So, we will take worst case here to tell with certainty the min moves
    //         int cur_moves = 1 + max(moves_if_egg_breaks, moves_if_egg_doesnt_break);
            
    //         //We will take minimum of all the values that we will get after selecting a specific kth floor as first floor
    //         min_moves = min(cur_moves, min_moves);

    //         if(moves_if_egg_breaks < moves_if_egg_doesnt_break){
    //             l = mid+1;
    //         }
    //         else{
    //             h = mid-1;
    //         }
    //     }
    //     return dp[e][f] = min_moves;
    // }

    // int superEggDrop(int e, int f) 
    // {
    //     int dp[101][10001];
    //     memset(dp,-1, sizeof(int)*101*10001);
    //     return rec(e, f, dp);
    // }
    
    // int superEggDrop(int e, int f) {
    //     int** dp = new int*[e+1];
    //     for(int i=0; i<=e; i++){
    //         dp[i] = new int[f+1];
    //         // memset(dp[i], -1, sizeof(int)*(f+1));
    //     }

    //     for(int i=0; i<=f; i++){
    //         dp[0][i] = 0;
    //         dp[1][i] = i;
    //     }

    //     for(int j=1; j<=e; j++){
    //         dp[j][0] = 0;
    //     }

    //     for(int i = 2; i<=e; i++){
    //         for(int j=1; j<=f; j++){
    //             int min_moves = INT_MAX;
    //             int l = 1, h = j;

    //             while(l<=h){
    //                 int mid = (l+h)/2;
    //                 int brk = dp[i-1][mid-1];
    //                 int n_brk = dp[i][j-mid];
    //                 if(brk < n_brk){
    //                     l = mid+1;
    //                 }
    //                 else{
    //                     h = mid-1;
    //                 }
    //                 min_moves = min(min_moves,1 + max(brk, n_brk));
    //             }
    //             dp[i][j] = min_moves;
    //         }
    //     }

    //     return dp[e][f];
    // }



    // int superEggDrop(int e, int f) {
    //     int * prev = new int[f+1];
    //     int * cur = new int[f+1];

    //     for(int i=0; i<=f; i++){
    //         prev[i] = i;
    //         cur[i] = i;
    //     }

    //     for(int i = 2; i<=e; i++){
    //         for(int j=2; j<=f; j++){
    //             int min_moves = INT_MAX;
    //             int l = 2, h = j;
    //             while(l<=h){
    //                 int mid = (l+h)/2;
    //                 int brk = prev[mid-1];
    //                 int n_brk = cur[j-mid];
    //                 if(brk < n_brk){
    //                     l = mid+1;
    //                 }
    //                 else{
    //                     h = mid-1;
    //                 }
    //                 min_moves = min(min_moves,1 + max(brk, n_brk));
    //             }
    //             cur[j] = min_moves;
    //         }
    //         prev = cur;
    //     }

    //     return cur[f];
    // }

    //Don't know the intuition behind this code
    //TC-O(ans * k), SC - O()
    int superEggDrop(int k, int n) {
        // Value in table is max-n(f, k).
        int f = 0;  // Count f we need.
        const int T_HEIGHT = k+1;
        vector<int> table(T_HEIGHT, 0);
        vector<int> aux_table(table);  // Store table's temporary state while counting.

        while (table.back() < n){
            for (int i = 1; i < T_HEIGHT; ++i)
                aux_table[i] = table[i-1] + table[i] + 1;
            table = aux_table;
            ++f;
        }
        
        return f;
    }
};
