class Solution {
public://better solution - memoiation
//T.C. - O(n * amount)
//S.C. - O(n * amount) + recursion stack
    int helper(int i,int amount,vector<int>& coins,int sum,vector<vector<int>>&dp){
        if(sum==amount)return 1;
        if(i==coins.size())return 0;
        if(sum>amount)return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        int take = helper(i,amount,coins,sum+coins[i],dp);
        int notTake = helper(i+1,amount,coins,sum,dp);
        return dp[i][sum] = take+notTake;
    }

    int change(int amount, vector<int>& coins) {
        int sum=0;
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return helper(0,amount,coins,0,dp);
    }
};
