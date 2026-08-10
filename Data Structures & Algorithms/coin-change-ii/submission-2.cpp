class Solution {
public://optimal solution - Tabulation
//T.C. - O(n*amount)
//S.C. - O(n*amount)
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
        for(int i = 0;i<n;i++){
            dp[i][amount]=1;
        }
        for(int i=n-1;i>=0;i--){
            for(int sum=amount-1;sum>=0;sum--){
                dp[i][sum] = dp[i+1][sum];
                if(sum+coins[i] <= amount) dp[i][sum]+=dp[i][sum+coins[i]]; 
            }
        }
        return dp[0][0];
    }
};
