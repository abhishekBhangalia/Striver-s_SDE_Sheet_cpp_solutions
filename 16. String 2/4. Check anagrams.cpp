class Solution {
public:
    // bool isAnagram(string s, string t) {
    //     unordered_map<char,int> map;
    //     for(char c:s)   map[c]++;
    //     for(char c:t){
    //         if(map.find(c)==map.end())  return false;
    //         map[c]--;
    //     }
    //     for(auto i:map){
    //         if(i.second > 0)    return false;
    //     }
    //     return true;
    // }


    bool isAnagram(string s, string t) {
        int n1 = s.length(), n2 = t.length();
        if(n1!=n2)  return false;

        int map[26] = {0};
        // for(int i=0; i<26; i++){
        //     map[i] = 0;
        // }
        for(int i=0; i<n1; i++){
            map[s[i]-'a']++;
            map[t[i]-'a']--;
        }
        
        for(int f:map)  if(f!=0)    return false;
        return true;
    }


};
