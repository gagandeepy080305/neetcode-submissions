class Solution {
public://brute force - Recurrsion
//T.C. - O(m*n)
//S.C. - O(m*n)

    int helper(int i , int j , int m ,int n,vector<vector<int>>&dp){
        if(i==m-1 && j==n-1)return 1;
        if(i>m-1 || j>n-1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = helper(i,j+1,m,n,dp)+helper(i+1,j,m,n,dp);
    }

    int uniquePaths(int m, int n) {
        int cnt = 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return helper(0,0,m,n,dp);
    }
};
