class Solution {
public:

    // //Brute Force, TC-O(n^2)
    // string longestPalindrome(string s) {
    //     int n = s.length();
    //     int max_len=0;
    //     string ans;
    //     int i=0;

    //     label1: for(; i<n; i++){
    //         int j=n-1;
    //         label2 : while(j>=0 and s[j]!=s[i])  j--;
    //         if(j<0) continue;
    //         int r = j;
    //         int l = i;
    //         while(l<r){
    //             if(s[l] == s[r]){
    //                 l++;    r--;
    //             }
    //             else{
    //                 j--;
    //                 goto label2;
    //             }
    //         }
    //         int cur_len = j-i+1;
    //         if(cur_len > max_len){
    //             max_len = cur_len;
    //             ans = s.substr(i,cur_len);
    //         }
    //     }
    //     return ans;
    // }



    // //Brute Force, TC-O(n^2)
    // string longestPalindrome(string s) {
    //     int n = s.length();
    //     int max_len=0;
    //     int start = 0;

    //     string rev = string(s.rbegin(),s.rend());
    //     int i=0, j;
    //     for(;i<n; i++){
    //         j=0;
    //         while(j<n){
    //             int len = 0;
    //             int l = i;
    //             while(j<n and s[l] != rev[j]) j++;
    //             while(j<n and l<n and s[l] == rev[j]){
    //                 l++;    j++;
    //                 len++;
    //             }
    //             if(len > max_len){
    //                 l=i;
    //                 j=i+len-1;
    //                 int is_pal = 1;
    //                 while(l<j){
    //                     if(s[l]==s[j]){
    //                         l++;    j--;
    //                     }
    //                     else{
    //                         is_pal = 0;
    //                         break;
    //                     }
    //                 }
    //                 if(is_pal){
    //                     max_len = len;
    //                     start = i;
    //                 }
    //             }
    //         }
    //     }
    //     return s.substr(start,max_len);
    // }


    string longestPalindrome(string s){
        int max_len = 1;
        int start = 0;
        int i=0;
        int n=s.length();
        while(i<n){
            if(n-i-1 <= max_len/2)    break;
            int l = i, r = i;

            // expanding window end if chars are same and palindrome is of even length
            while(r<n-1 and s[r] == s[r+1])   r++;
            i = r+1;

            // expanding window from both sides until it is palindrome
            while(r<n-1 and l > 0 and s[r+1]==s[l-1]){
                l--;    r++;
            }
            int len = r-l+1;
            if(len > max_len){
                max_len = len;
                start = l;
            }
        }

        return s.substr(start,max_len);
    }
};
