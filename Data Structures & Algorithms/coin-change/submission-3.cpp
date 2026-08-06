class Solution {
public://brute force solution - recurssion
//T.C. - O(2^(n+amount))
//S.C. - O(n+amount)

    int minCoin(int idx , vector<int>& coins, int amount){
        if(idx==0){
            if(amount%coins[idx]==0)return amount/coins[idx];
            return 1e9;
        }

        int notTake = minCoin(idx-1,coins,amount);

        int take = INT_MAX;
        if(coins[idx]<=amount) take = 1+minCoin(idx,coins,amount-coins[idx]);

        return min(notTake,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans =  minCoin(n-1,coins,amount);
        return (ans>=1e9) ? -1 : ans;
    }
};