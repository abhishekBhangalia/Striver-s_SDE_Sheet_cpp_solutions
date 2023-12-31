vector<int> MinimumCoins(int n)
{
    // Write your code here
    int arr[] = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    vector<int>  ans;
    int i = 8;
    while(n){
        while(n/arr[i]){
            ans.push_back(arr[i]);
            n -= arr[i];
        }
        i--;
    }
    return ans;
}
