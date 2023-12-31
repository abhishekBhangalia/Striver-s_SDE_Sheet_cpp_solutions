class Solution {
    
public:

    // Recursion(TLE), TC-O(2^n1 + 2^n2)? , SC-O(max(n1,n2))
    // int rec(int i1, int i2, string s1, string s2){
    //     if(i1 < 0 or i2 < 0)    return 0;
    //     if(s1[i1] == s2[i2])    return 1 + rec(i1-1, i2-1, s1, s2);
    //     return max(rec(i1-1, i2, s1, s2), rec(i1, i2-1, s1, s2));
    // }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1 = text1.length(), n2 = text2.length();
    //     return rec(n1-1, n2-1, text1, text2);
    // }


    // // Memoization, TC-O(n1*n2), SC-O(n1*n2 + max(n1,n2))
    // int rec(int i1, int i2, string& s1, string& s2, vector<vector<int>>& DP){
    //     if(i1 < 0 or i2 < 0)    return 0;
    //     if(DP[i1][i2] != -1)    return DP[i1][i2];
    //     if(s1[i1] == s2[i2])    return DP[i1][i2] = 1 + rec(i1-1, i2-1, s1, s2, DP);
    //     return DP[i1][i2] = max(rec(i1-1, i2, s1, s2, DP), rec(i1, i2-1, s1, s2, DP));
    // }

    // int longestCommonSubsequence(string text1, string text2) {
    //     int n1 = text1.length(), n2 = text2.length();
    //     vector<vector<int>> DP(n1, vector<int> (n2, -1));
    //     return rec(n1-1, n2-1, text1, text2, DP);
    // }


    // // Tabulation, TC-O(n1*n2), SC-O(n1*n2 + max(n1,n2))

    // int longestCommonSubsequence(string s1, string s2) {
    //     int n1 = s1.length(), n2 = s2.length();
    //     vector<vector<int>> DP(n1, vector<int> (n2, 0));
    //     DP[0][0] = s1[0] == s2[0];
    //     for(int i2=1; i2<n2; i2++){
    //         DP[0][i2] = (s1[0] == s2[i2]) ? 1 : DP[0][i2-1];
    //     }
    //     for(int i1=1; i1<n1; i1++){
    //         DP[i1][0] = (s1[i1] == s2[0]) ? 1 : DP[i1-1][0];
    //     }

    //     for(int i1=1; i1<n1; i1++){
    //         for(int i2=1; i2<n2; i2++){
    //             DP[i1][i2] = (s1[i1] == s2[i2]) ? 1+DP[i1-1][i2-1] 
    //                         : max(DP[i1][i2-1], DP[i1-1][i2]);
    //         }
    //     }
    //     return DP[n1-1][n2-1];
    // }



    // // // Tabulation(Space Optimized), TC-O(n1*n2), SC-O(n2)
    // int longestCommonSubsequence(string s1, string s2) {
    //     int n1 = s1.length(), n2 = s2.length();
    //     if(n1 == 0 or n2 == 0)  return 0;
    //     vector<int> prev(n2, 0), cur(n2, 0);
    //     prev[0] = s1[0] == s2[0];
    //     for(int i2=1; i2<n2; i2++){
    //         prev[i2] = (s1[0] == s2[i2]) ? 1 : prev[i2-1];
    //     }
    //     if(n1==1) return prev[n2-1];

    //     for(int i1=1; i1<n1; i1++){
    //         cur[0] = s1[i1] == s2[0] ? 1 : prev[0];
    //         for(int i2=1; i2<n2; i2++){
    //             cur[i2] = (s1[i1] == s2[i2]) ? 1+prev[i2-1] 
    //                         : max(cur[i2-1],prev[i2]);
    //         }
    //         prev = cur;
    //     }
    //     return cur[n2-1];
    // }


    // // Tabulation Space optimized, TC-O(n1*n2), SC-O(n2)
    int longestCommonSubsequence(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 == 0 or n2 == 0)  return 0;
        int *prev = new int[n2], *cur = new int[n2];
        prev[0] = s1[0] == s2[0];
        for(int i2=1; i2<n2; i2++){
            prev[i2] = (s1[0] == s2[i2]) ? 1 : prev[i2-1];
        }
        if(n1==1) return prev[n2-1];

        for(int i1=1; i1<n1; i1++){
            cur[0] = s1[i1] == s2[0] ? 1 : prev[0];
            for(int i2=1; i2<n2; i2++){
                cur[i2] = (s1[i1] == s2[i2]) ? 1+prev[i2-1] 
                            : max(cur[i2-1],prev[i2]);
            }
            swap(prev,cur);
        }
        return prev[n2-1];
    }

    // // // Tabulation, TC-O(n1*n2), SC-O(n1*n2 + max(n1,n2))
    // int longestCommonSubsequence(string s1, string s2) {
    //     int n1 = s1.length(), n2 = s2.length();
    //     if(n1 == 0 or n2 == 0)  return 0;
    //     if(n1>=n2){
    //         vector<int> prev(n2, 0), cur(n2, 0);
    //         prev[0] = s1[0] == s2[0];
    //         for(int i2=1; i2<n2; i2++){
    //             prev[i2] = (s1[0] == s2[i2]) ? 1 : prev[i2-1];
    //         }
    //         if(n1==1) return prev[n2-1];

    //         for(int i1=1; i1<n1; i1++){
    //             cur[0] = s1[i1] == s2[0] ? 1 : prev[0];
    //             for(int i2=1; i2<n2; i2++){
    //                 cur[i2] = (s1[i1] == s2[i2]) ? 1+prev[i2-1] 
    //                             : max(cur[i2-1],prev[i2]);
    //             }
    //             prev = cur;
    //         }
    //         return cur[n2-1];
    //     }
    //     else{
    //         vector<int> prev(n1, 0), cur(n1, 0);
    //         prev[0] = s2[0] == s1[0];
    //         for(int i1=1; i1<n1; i1++){
    //             prev[i1] = (s2[0] == s1[i1]) ? 1 : prev[i1-1];
    //         }
    //         if(n2==1) return prev[n1-1];

    //         for(int i2=1; i2<n2; i2++){
    //             cur[0] = s2[i2] == s1[0] ? 1 : prev[0];
    //             for(int i1=1; i1<n1; i1++){
    //                 cur[i1] = (s1[i1] == s2[i2]) ? 1+prev[i1-1] 
    //                             : max(cur[i1-1],prev[i1]);
    //             }
    //             prev = cur;
    //         }
    //         return cur[n1-1];
    //     }
        
    // }



    
};
