class Solution {
public://better solution - memoiation approach
//T.C. - O(n)
//S.C. - O(n) 
    int helper(int i,int hold,vector<int>& prices,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][hold]!=-1)return dp[i][hold];
        if(hold==1)dp[i][hold] = max(helper(i+1,1,prices,dp),prices[i]+helper(i+2,0,prices,dp));
        else dp[i][hold] = max(helper(i+1,0,prices,dp),-prices[i]+helper(i+1,1,prices,dp));
        return dp[i][hold] ;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return helper(0,0,prices,dp);
    }
};
