bool is_palindrome(int i, int j, string& s){
    while(i<j){
        if(s[i]!=s[j])  return false;
        i++;
        j--;
    }
    return true;
}


int palindromePartitioning(string s)
{
    // Write your code here
    int n=s.size();
    int *dp = new int[n+1];
    // memset(dp, 0, sizeof(int)*(n+1));
    dp[n] = 0;

    // p_dp = new int*[n];
    // for(int i=0; i<n; i++){
    //     p_dp[i] = new int[n];
    //     memset(p_dp[i], -1, sizeof(int)*n);
    // }
    // memset(dp, -1, sizeof(int)*n);
    
    for(int i=n-1; i>=0; i--){
        int min_cost = n;
        for(int j=i; j<n; j++){
            if(is_palindrome(i,j,s)){
                min_cost = min(min_cost, 1+dp[j+1]);
            }
        }
        dp[i] = min_cost;
    }
    return dp[0]-1;
}



