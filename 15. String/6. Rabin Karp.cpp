#define base 26

class Solution {
public:

    // TC-O(n1 * n2)
    // int repeatedStringMatch(string a, string b) {
    //     int i=0, j=0;
    //     int n1 = a.length(), n2 = b.length();
    //     int reps = 0;

    //     label1: while(i<n1 and a[i] != b[j]) i++;

    //     if(i == n1)     return -1;
    //     else if(i!=0)   reps++;
    //     int tmp = i+1;

    //     while(j<n2){
    //         if(a[i] == b[j]){
    //             if(i==0)    reps++;
    //             i++;
    //             j++;
    //             if(i==n1)   i=0;
    //         }
    //         else{
    //             i = tmp;
    //             j = 0;
    //             reps = 0;
    //             goto label1;
    //         }
    //     }
       
    //     return reps;
    // }

    // target = b, source = a

    // 
    bool RabinKarpSubStringFind(string a, string b){
        int n1=a.length();
        int n2=b.length();

        int h1 = 0, h2 = 0;
        int pow = 1;
        int mod = 1e7 + 3;

        for(int i=0; i<n2; i++){
            h2 = ((h2*base) + b[i]) % mod;
            h1 = ((h1*base) + a[i]) % mod;
            if(i<n2-1)  pow = (pow * base) % mod;
        }
        
        if(h1 == h2){
            if(a.substr(0,n2) == b)  return true;
        }

        for(int i=n2; i<n1; i++){
            h1 =  (h1 - pow * a[i-n2]) % mod;
            if(h1<0) h1 += mod;
            h1 =  (h1 * base + a[i]) % mod;
            if(h1 == h2){
                if(a.substr(i-n2+1,n2) == b)  return true;
            }
        }
        return false;

    }

    int repeatedStringMatch(string a, string b) {
        if(b=="")   return 0;
        if(a==b)    return 1;
        int reps = 1;
        string new_a = a;
        while(new_a.length() < b.length()){
            new_a += a;
            reps++;
        }

        if(new_a == b)  return reps;
        if(RabinKarpSubStringFind(new_a,b)) return reps;
        if(RabinKarpSubStringFind(new_a+a,b))   return reps+1;
        return -1;
    }
};
