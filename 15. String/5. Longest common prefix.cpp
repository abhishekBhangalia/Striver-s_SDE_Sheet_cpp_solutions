class Solution {
public:

    // // TC-O(n*longest_common_pref_len), SC-O(1)
    // string longestCommonPrefix(vector<string>& strs) {
    //     string ans = "";
    //     int i=0;
    //     int n = strs[0].length();
    //     while(true){
    //         int is_same = true;
    //         for(string s : strs){
    //             if(i == s.length() or (i<s.length() and s[i] != strs[0][i])){
    //                 is_same = false;
    //                 break;
    //             }
    //         }
    //         if(is_same){
    //             ans.push_back(strs[0][i]);
    //             i++;
    //         }
    //         else break;
    //     }

    //     return ans;
        
    // }


    // TC-O(n*log n) + O(lon_pref_len), SC-O(1)
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        sort(strs.begin(), strs.end());

        int n=strs.size(), i=0;
        int len = strs[0].length();
        if(strs[n-1].length() < len)    len = strs[n-1].length();
        
        while(i<len and strs[0][i] == strs[n-1][i]){
            ans.push_back(strs[0][i]);
            i++;
        }

        return ans;
        
    }


};
