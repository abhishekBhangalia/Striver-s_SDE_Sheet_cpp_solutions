static const auto speed=[]{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return false;
}();


class Solution {

    bool isPalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l]!= s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }

    // bool isPalindrome(string& s){
    //     int l = 0, r = s.size()-1;
    //     while(l<r){
    //         if(s[l] != s[r])    return false;
    //         l++;
    //         r--;
    //     }
    //     return true;
    // }

    void rec(int i, string& s, vector<vector<string>>& ans, vector<string>& partition){
        if(i==s.size()){
            ans.push_back(partition);
            return;
        }
        // string sub="";
        for(int j=i; j<s.size(); j++){
            // sub.push_back(s[j]);
            // if(isPalindrome(sub)){
            if(isPalindrome(s,i,j)){
                // partition.push_back(sub);
                partition.push_back(s.substr(i, j-i+1));
                rec(j+1, s, ans, partition);
                partition.pop_back();
            }
        }
    }

public:

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;
        rec(0, s, ans, partition);
        return ans;
    }
};


