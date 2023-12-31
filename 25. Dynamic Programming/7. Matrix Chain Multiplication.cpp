// User function Template for C++

class Solution{
public:
    // Memoization, TC-O(N^2), SC-O(N^2)+O(N)
    // int rec(int s, int e, int arr[], vector<vector<int>>& DP){
    //     if(s==e)    return 0;
    //     if(DP[s][e] != -1)  return DP[s][e];
    //     int min_multis = INT_MAX;
    //     for(int k=s; k<e; k++){
    //         int multis = arr[s-1] * arr[k] * arr[e] + rec(s,k,arr, DP) + rec(k+1, e, arr, DP);
    //         if(multis < min_multis)     min_multis = multis;
    //     }
    //     return DP[s][e] = min_multis;
    // }
    
    // int matrixMultiplication(int N, int arr[])
    // {
    //     vector<vector<int>> DP(N, vector<int>(N,-1));
    //     return rec(1,N-1,arr,DP);
    // }
    
    
    
    int matrixMultiplication(int N, int arr[])
    {
        
        int dp[N][N];
        for(int i=1; i<N; i++)  dp[i][i] = 0;
        
        for(int s=N-1; s>0; s--){
            for(int e=s+1; e<N; e++){
                int min_multis = INT_MAX;
                for(int k=s; k<e; k++){
                    int multis = arr[s-1] * arr[k] * arr[e] + dp[s][k] + dp[k+1][e];
                    if(multis < min_multis)     min_multis = multis;
                }
                dp[s][e] = min_multis;
                
            }
            
        }
        
        return dp[1][N-1];
    }
    
};
