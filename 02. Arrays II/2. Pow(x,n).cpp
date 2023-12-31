class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)    return 1;
        long N = n;//abs(INT_MIN) can overflow if we use int
        if(N<0)     N *= -1; 
        double ans = 1;
        while(N > 0){
            if(N%2 == 0){
                x = x*x;
                N = N/2;
            }
            else{
                ans *= x;
                N--;
            }
        }
        if(n<0)     ans = 1/ans;
        return ans;
    }
};
