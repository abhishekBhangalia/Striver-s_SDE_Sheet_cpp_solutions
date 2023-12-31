static const auto fast = []{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {
public:

    // bool rec(int i, string& s, unordered_set<string>& dic, vector<int>& dp){
    //     if(dp[i] != -1) return dp[i];
    //     if(i==s.size()){
    //         return dp[i] = true;
    //     }
    //     int can_break = false;
    //     string tmp = "";
    //     for(int j = i; j<s.size(); j++){
    //         tmp.push_back(s[j]);
    //         if(dic.count(tmp)){
    //             // cout<<j;
    //             can_break = can_break or rec(j+1, s, dic, dp);
    //         }
    //     }
    //     return dp[i] = can_break;
    // }

    // This will perform better than below tabulation
    //TC-O(n^2) + O(length of all words in dic for inserting to set)
    //SC-O(length of all words in dic) + O(n) + O(n) stack space
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> dic;
    //     for(string& w: wordDict){
    //         dic.insert(w);
    //     }
    //     vector<int> dp(s.size()+1, -1);
    //     return rec(0, s, dic, dp);
    // }

    //TC-O(n^2) + O(length of all words in dic for inserting to set)
    //SC-O(length of all words in dic) + O(n)
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string> dic;
    //     int n = s.size();

    //     for(string& w: wordDict){
    //         dic.insert(w);
    //     }
    //     // vector<int> dp(n+1, -1);
    //     int* dp = new int[n+1];
    //     // memset(dp,-1, sizeof(int)*(n+1));
    //     dp[n] = true;

    //     for(int i=n-1; i>=0; i--){
    //         int can_break = false;
    //         string tmp = "";
    //         for(int j = i; j<n; j++){
    //             tmp.push_back(s[j]);
    //             if(dic.count(tmp)){
    //                 can_break = can_break or dp[j+1];
    //             }
    //         }
    //         dp[i] = can_break;
    //     }
    //     return dp[0];
    // }


    //beats 100%
    //TC-O(n1 * n2 (n3 * n1))
    //TC-O(string size * dict size*(size of max word in dict * string size))
    //because the inner if condition can be true at max n times (for eg if input is aaaaaaaaaaaaabc and abc is a word in wordDict) 
    //
    //SC-O(n) 
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        
        int* dp = new int[n+1];
        memset(dp, 0, sizeof(int)*(n+1));
        dp[0] = true;

        for(int i=0; i<n; i++){
            for(string& word: wordDict){
                if(word[0] == s[i] and i+word.size() <= n){
                    if(s.substr(i, word.size()) == word){
                        dp[i+word.size()] = dp[i] or dp[i+word.size()];
                    }
                }
            }
        }
        return dp[n];
    }

};
