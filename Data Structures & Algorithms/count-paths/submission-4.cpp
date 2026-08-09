class Solution {
public://optimal solution - tabulation with space optimized
//T.C. - O(m*n)
//S.C. - O(n)
    int uniquePaths(int m, int n) {
        vector<int>dp(n,1);
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[j] = dp[j]+dp[j+1];
            }
        }
        return dp[0];
    }
};
