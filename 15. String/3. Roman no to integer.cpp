class Solution {
public:
    // int romanToInt(string s) {
    //     unordered_map<char,int> map;
    //     map['I'] = 1;
    //     map['V'] = 5;
    //     map['X'] = 10;
    //     map['L'] = 50;
    //     map['C'] = 100;
    //     map['D'] = 500;
    //     map['M'] = 1000;

    //     int x=0;
    //     int n=s.length();
    //     for(int i=0; i<n; i++){
    //         int cur = map[s[i]], nxt = map[s[i+1]];
    //         if(i<n-1 and  cur < nxt ){
    //             x += nxt - cur;
    //             i++;
    //         }
    //         else    x += cur;
    //     }
    //     return x;
        
    // }

    // int romanToInt(string s) {
    //     unordered_map<char,int> map;
    //     map['I'] = 1;
    //     map['V'] = 5;
    //     map['X'] = 10;
    //     map['L'] = 50;
    //     map['C'] = 100;
    //     map['D'] = 500;
    //     map['M'] = 1000;

    //     int x=0;
    //     int n=s.length();
    //     for(int i=0; i<n; i++){
    //         int cur = map[s[i]], nxt = map[s[i+1]];
    //         if(cur < nxt )  x -= cur;
    //         else    x += cur;
    //     }
    //     return x;
        
    // }

    int romanToInt(string s) {

        int ans=0;
        map <char,int> mp{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

    for(int i=0;i<s.size();i++){
        if(mp[s[i]]<mp[s[i+1]]){
            //for cases such as IV,CM, XL, etc...
            ans=ans-mp[s[i]];
        }
        else{
            ans=ans+mp[s[i]];
        }
    }
        return ans;
    }
};
