class Solution {

public:

    // Recursion, TC-O(2^(n+m)), SC-O(n+m)
    // int rec(int i, int j, string &s, string &t){
    //     if(j<0)     return i+1; //delete remaining chars in s
    //     if(i==0)    return j+1; //insert/replace char in s

    //     if(s[i] == t[j])    return rec(i-1, j-1, s, t);
    //     else{
    //         int del = 1 + rec(i-1,j,s,t);
    //         int replace = 1 + rec(i-1, j-1, s, t);
    //         return min(del, replace);
    //     }
    // }

    // int minDistance(string s, string t) {
    //     int n1 = s.size(), n2 = t.size();
    //     return rec(n1-1, n2-1, s, t);
    // }


    // // Memoization, TC-O(n*m), SC-O(n*m)+O(n+m)
    // int dp(int i, int j, string &s, string &t, int** DP){
    //     if(j<0)     return i+1; //delete remaining chars of s
    //     if(i<0)     return j+1; //insert remaining chars of t in s
    //     if(DP[i][j] != -1)  return DP[i][j];

    //     if(s[i] == t[j])    return  DP[i][j] = dp(i-1, j-1, s, t, DP);
    //     else{
    //         int del = 1 + dp(i-1,j,s,t, DP);
    //         int replace = 1 + dp(i-1, j-1, s, t, DP);
    //         int insert = 1 + dp(i, j-1, s, t, DP);
    //         return  DP[i][j] = min({del, replace, insert});
    //     }
    // }

    // int minDistance(string s, string t) {
    //     int n1 = s.size(), n2 = t.size();
    //     if(n1==0)   return n2;

    //     int ** DP = new int*[n1];
    //     for(int i=0; i<n1; i++){
    //         DP[i] = new int[n2];
    //         memset(DP[i],-1,n2*sizeof(int));
    //     }

    //     return dp(n1-1, n2-1, s, t, DP);
    // }



    // //Tabulation, TC-O(n*m), SC-O(n*m)
    // int minDistance(string s, string t) {
    //     int n1 = s.size(), n2 = t.size();
    //     if(n1==0)   return n2;

    //     int ** DP = new int*[n1+1];
    //     for(int i=0; i<=n1; i++){
    //         DP[i] = new int[n2+1];
    //         memset(DP[i],-1,(n2+1)*sizeof(int));
    //     }

    //     DP[0][0] = 0; //when both s and t are empty
    //     for(int i=1; i<=n1; i++){
    //         DP[i][0] = i;   // delete remaining chars of s
    //     }
    //     for(int j=1; j<=n2; j++){
    //         DP[0][j] = j;   // insert remaining chars of t in s
    //     }
        
    //     for(int i=1; i<=n1; i++){
    //         for(int j=1; j<=n2; j++){
    //             if(s[i-1] == t[j-1])     DP[i][j] = DP[i-1][j-1];
    //             else{
    //                 int del = 1 + DP[i-1][j];
    //                 int replace = 1 + DP[i-1][j-1];
    //                 int insert = 1 + DP[i][j-1];
    //                 DP[i][j] = min({del, replace, insert});
    //             }
    //         }
    //     }
    //     return DP[n1][n2];
    // }


    //Tabulation, TC-O(n*m), SC-O(2m)
    int minDistance(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        if(n1==0)   return n2;

        int *cur = new int[n2+1], *prev = new int[n2+1];

        prev[0] = 0; //when both s and t are empty
        for(int j=1; j<=n2; j++){
            prev[j] = j;   // insert remaining chars of t in s
        }
        
        for(int i=1; i<=n1; i++){
            cur[0] = i;
            for(int j=1; j<=n2; j++){
                if(s[i-1] == t[j-1])     cur[j] = prev[j-1];
                else{
                    int del = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    int insert = 1 + cur[j-1];
                    cur[j] = min({del, replace, insert});
                }
            }
            swap(prev, cur);
        }
        return prev[n2];
    }


};
