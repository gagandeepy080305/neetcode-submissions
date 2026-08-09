class Solution {
public://optimal solution - tabulation
//T.C. - O(n)
//S.C. - O(n)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int i=n-1;i>=0;i--){
            dp[i][0] = max(dp[i+1][0] , -prices[i]+dp[i+1][1]);//if not hold {skip,buy}
            dp[i][1] = max(dp[i+1][1] , prices[i]+dp[i+2][0]);//if hold {skip,sell} 
        }
        return dp[0][0];
    }
};
