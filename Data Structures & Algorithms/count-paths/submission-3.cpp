class Solution {
public://optimal solution - tabulation but not space optimized
//T.C. - O(m*n)
//S.C. - O(m*n)
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int j = 0;j<=n-1;j++)dp[m-1][j]=1;//last row
        for(int i=0;i<=m-1;i++)dp[i][n-1] = 1;//last col
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = dp[i][j+1] + dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};
