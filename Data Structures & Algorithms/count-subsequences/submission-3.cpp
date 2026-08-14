class Solution {
   public:// optimal solution - tabulation 
// T.C. - O(s_len * t_len)
// S.C. - O(s_len * t_len)
    
    int numDistinct(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();

        vector<vector<int>> dp(s_len + 1, vector<int>(t_len + 1, 0));

        for (int i = 0; i <= s_len; i++) {
            dp[i][t_len] = 1;
        }

        for (int i = s_len - 1; i >= 0; i--) {
            for (int j = t_len - 1; j >= 0; j--) {
                if (s[i] != t[j])
                    dp[i][j] = dp[i + 1][j];

                else
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
            }
        }

        return dp[0][0];
    }
};
