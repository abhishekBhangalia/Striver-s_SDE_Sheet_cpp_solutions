#define base 26
class Solution {

    //  int RabinKarpSubStringFind(string a, string b){
    //     int n1=a.length();
    //     int n2=b.length();

    //     int h1 = 0, h2 = 0;
    //     int pow = 1;
    //     int mod = 1e7 + 3;

    //     for(int i=0; i<n2; i++){
    //         h2 = ((h2*base) + b[i]) % mod;
    //         h1 = ((h1*base) + a[i]) % mod;
    //         if(i<n2-1)  pow = (pow * base) % mod;
    //     }
        
    //     if(h1 == h2){
    //         if(a.substr(0,n2) == b)  return 0;
    //     }

    //     for(int i=n2; i<n1; i++){
    //         h1 =  (h1 - pow * a[i-n2]) % mod;
    //         if(h1<0) h1 += mod;
    //         h1 =  (h1 * base + a[i]) % mod;
    //         if(h1 == h2){
    //             if(a.substr(i-n2+1,n2) == b)  return (i-n2+1);
    //         }
    //     }
    //     return -1;
    // }

    int KMP_pattern_match(string s, string p){
        int n1 = s.length();
        int n2 = p.length();

        // populating lps array which will store the longest length of prefix which is also a suffix of p
        vector<int> lps(n2);
        for(int i=1; i<n2; i++){
            int j = lps[i-1];
            while(j>0 and p[i]!=p[j])   j = lps[j-1];
            if(p[i] == p[j])    j++;
            lps[i] = j;
        }

        int i = 0, j = 0;
        while(i<n1 and j<n2){
            if(s[i] == p[j]){
                i++;
                j++;
            }
            else if(j==0)   i++;
            else    j = lps[j-1];
        }
        if(j==n2)   return i-n2;
        return -1;
    }



    
public:

    int strStr(string haystack, string needle) {
        return KMP_pattern_match(haystack,needle);
    }

};
