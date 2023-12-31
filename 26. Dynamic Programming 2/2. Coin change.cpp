class Solution {
public:

    // // recursive sol (TLE) TC- O(n^n), SC - O(n)
    // int rec(int i,int amount, vector<int>& coins){
    //     if(amount == 0){
    //         return 0;
    //     }
    //     if(i==0){
    //         if(coins[0]<=amount){
    //             if(amount % coins[0] == 0){
    //                 return amount/coins[0];
    //             }
    //             else{
    //                 return 1e8;
    //             }
    //         }
    //         return 1e8;
    //     }
    //     int take =  1e8;
    //     if(coins[i]<=amount ){
    //         take = 1 + rec(i,amount-coins[i],coins);
    //     }
    //     int not_take = rec(i-1,amount,coins);
        
    //     return min(take,not_take);
    // }


    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount == 0) return 0;
    //     int min_coins = rec(coins.size()-1,amount,coins);
    //     if(min_coins == 1e8){
    //         return -1;
    //     }
    //     return min_coins;
    // }


    // // dp sol using memoization, TC- O(n*amount), SC - O(n) + O(n*amount)
    // int rec(int i,int amount, vector<int>& coins,vector<vector<int>>& min_coins){
    //     if(min_coins[i][amount]!=-1){
    //         return min_coins[i][amount];
    //     }
    //     if(amount == 0){
    //         return min_coins[i][amount] = 0;
    //     }
    //     if(i==0){
    //         if(coins[0]<=amount){
    //             if(amount % coins[0] == 0){
    //                 return min_coins[i][amount] = amount/coins[0];
    //             }
    //             else{
    //                 return min_coins[i][amount] = 1e8;
    //             }
    //         }
    //         return min_coins[i][amount] = 1e8;
    //     }
    //     int take =  1e8;
    //     if(coins[i]<=amount ){
    //         take = 1 + rec(i,amount-coins[i],coins,min_coins);
    //     }
    //     int not_take = rec(i-1,amount,coins,min_coins);
        
    //     return min_coins[i][amount] = min(take,not_take);
    // }


    // int coinChange(vector<int>& coins, int amount) {
    //     if(amount == 0) return 0;
    //     vector<vector<int>> minCoins(coins.size(),vector<int>(amount+1,-1));
    //     int min_coins = rec(coins.size()-1,amount,coins,minCoins);
    //     if(min_coins == 1e8){
    //         return -1;
    //     }
    //     return min_coins;
    // }



    // dp sol using tabulation, TC- O(n*amount), SC - O(n*amount)


    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> minCoins(coins.size(),vector<int>(amount+1,0));
        for(int i=0; i<coins.size(); i++){
            minCoins[i][0] = 0;
        }
        for(int amt = 1; amt<=amount; amt++){
            if(coins[0]<=amt){
                if(amt % coins[0] == 0){
                     minCoins[0][amt] = amt/coins[0];
                }
                else{
                     minCoins[0][amt] = 1e8;
                }
            }
             minCoins[0][amt] = 1e8;
        }
        for(int i=1; i<coins.size(); i++){
            for(int amt = 1; amt<=amount; amt++){
                int take =  1e8;
                if(coins[i]<=amt ){
                    take = 1 + minCoins[i][amt-coins[i]];
                }
                int not_take = minCoins[i-1][amt];
            }
        }

        int min_coins = minCoins[coins.size()-1][amount];
        if(min_coins == 1e8){
            return -1;
        }
        return min_coins;
    }


};
