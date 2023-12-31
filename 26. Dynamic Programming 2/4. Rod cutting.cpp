class Solution {
public:


    //TC-O(n^3), SC-O(n^2) + O(n)
    
    // int rec(int s, int e, vector<int>& cuts, int** dp){
    //     if(dp[s][e] != -1)  return dp[s][e];
    //     if(s>e) return dp[s][e] = 0;
        
    //     int min_cost = INT_MAX;
    //     for(int i=s; i<=e; i++){
    //         int cost = cuts[e+1] - cuts[s-1] + rec(s, i-1, cuts, dp) + rec(i+1,e, cuts, dp);
    //         min_cost = min(min_cost, cost);
    //     }
    //     return dp[s][e] = min_cost;
    // }


    // int minCost(int n, vector<int>& cuts) {
    //     sort(cuts.begin(), cuts.end());
    //     cuts.insert(cuts.begin(), 0);
    //     cuts.push_back(n);
    //     int size = cuts.size();
    //     int **dp = new int*[size];
    //     for(int i=0; i<size; i++){
    //         dp[i] = new int[size];
    //         memset(dp[i], -1, sizeof(int)*(size));
    //     }
    //     return rec(1,size-2,cuts, dp);
    // }


    // TC-O(n^3), SC-O(n^2)
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size = cuts.size();
        int **dp = new int*[size];
        for(int i=0; i<size; i++){
            dp[i] = new int[size];
            memset(dp[i], 0, sizeof(int)*(size));
        }
        // memset(dp[0],0,sizeof(int)*size);
        // for(int s=0; s<size; s++)   dp[s][size-1] = 0;

        for(int s=size-2; s>0; s--){
            for(int e=s; e<size-1; e++){
                int min_cost = INT_MAX;
                for(int i=s; i<=e; i++){
                    int cost = dp[s][i-1] + dp[i+1][e];
                    min_cost = min(min_cost, cost);
                }
                dp[s][e] = min_cost + cuts[e+1] - cuts[s-1];
            }
        }
        return dp[1][size-2];
    }


};
