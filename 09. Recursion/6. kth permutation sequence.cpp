class Solution {
public:
    string getPermutation(int n, int k) {
        string s;
        vector<char> v;
        k--;
        char nc = to_string(n)[0];
        for(int i='1'; i<=nc; i++){
            v.push_back(i);
        }
        int f=1,x=n-1; 
        while(x){
            f*=x;
            x--;
        }
        while(true){
            
            s.push_back(v[k/f]);
            v.erase(v.begin()+k/f);
            k%=f;
            if(!v.size())
                break;
            f/=v.size();
        }
        return s;
    }

    
};
