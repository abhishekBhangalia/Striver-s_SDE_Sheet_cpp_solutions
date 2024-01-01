class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        n--;
        while(n--){
            int n = s.length();
            string new_s = "";
            for(int i=0; i<n; i++){
                char c = s[i];
                int tmp = i;
                while(c == s[i])    i++;
                new_s += to_string(i-tmp);
                new_s.push_back(c);
                i--;
            }
            s = new_s;
        }
        return s;
    }
};
