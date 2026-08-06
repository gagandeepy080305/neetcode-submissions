class Solution {
public://Better solution -  Memoization (Top-Down DP)
// Time Complexity: O(n * amount)
// Space Complexity: O(n * amount) + O(n + amount) recursion stack
// Overall: O(n * amount)

    int minCoin(int idx , vector<int>& coins, int amount,vector<vector<int>>&dp){
        if(idx==0){
            if(amount%coins[idx]==0)return amount/coins[idx];
            return 1e9;
        }
        if(dp[idx][amount]!=-1)return dp[idx][amount];
        int notTake = minCoin(idx-1,coins,amount,dp);

        int take = INT_MAX;
        if(coins[idx]<=amount) take = 1+minCoin(idx,coins,amount-coins[idx],dp);

        return dp[idx][amount]=min(notTake,take);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans =  minCoin(n-1,coins,amount,dp);
        return (ans>=1e9) ? -1 : ans;
    }
};
