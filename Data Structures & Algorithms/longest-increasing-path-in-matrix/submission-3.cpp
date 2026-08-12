class Solution {
public:// Better solution - Memoization
// T.C. - O(n * m)
// S.C. - O(n * m) + O(n * m)

    int helper(int r,int c,vector<vector<int>>& matrix,int totRow,int totCol,vector<vector<int>>&dp){
        if(dp[r][c] != -1)return dp[r][c];

        int up=0,down=0,right=0,left=0;
        if(r>0 && matrix[r-1][c] > matrix[r][c])up =helper(r-1,c,matrix,totRow,totCol,dp);
        if(c+1<totCol && matrix[r][c+1] > matrix[r][c])right =helper(r,c+1,matrix,totRow,totCol,dp);
        if(r+1<totRow && matrix[r+1][c] > matrix[r][c])down = helper(r+1,c,matrix,totRow,totCol,dp);
        if(c>0 && matrix[r][c-1] > matrix[r][c])left = helper(r,c-1,matrix,totRow,totCol,dp);

        return dp[r][c] = 1+max({up,right,down,left});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int totRow = matrix.size();
        int totCol = matrix[0].size();
        int ans = 0;
        vector<vector<int>>dp(totRow,vector<int>(totCol,-1));
        for(int i=0;i<totRow;i++){
            for(int j=0;j<totCol;j++){
                int res =  helper(i,j,matrix,totRow,totCol,dp);
                ans = max(ans,res);
            }
        }
        return ans;
    }
};
