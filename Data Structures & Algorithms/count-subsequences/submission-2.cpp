class Solution {
public:// better solution - Memoization
// T.C. - O(s_len * t_len)
// S.C. - O(s_len * t_len) + O(s_len) recursion stack
//dp[i][j] = number of distinct ways we can form/reach t from index j onwards, starting from index i in s.
    int helper(int i , int j , string& s, string& t ,int s_len , int t_len,vector<vector<int>>&dp){
        if(j==t_len)return 1;
        if(i==s_len)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        if(s[i]!=t[j])return dp[i][j] = helper(i+1,j,s,t,s_len,t_len,dp);
        int take = helper(i+1,j+1,s,t,s_len,t_len,dp);
        int notTake = helper(i+1,j,s,t,s_len,t_len,dp);
        return dp[i][j] = take+notTake;
    }

    int numDistinct(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        vector<vector<int>>dp(s_len+1,vector<int>(t_len+1,-1));
        return helper(0,0,s,t,s_len,t_len,dp);
    }
};
