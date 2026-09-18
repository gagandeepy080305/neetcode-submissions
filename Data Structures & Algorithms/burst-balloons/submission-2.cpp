class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> balloons;
        balloons.push_back(1);
        for (int x : nums) balloons.push_back(x);
        balloons.push_back(1);
        
        int m = balloons.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        
        for (int len = 2; len < m; ++len) {
            for (int i = 0; i < m - len; ++i) {
                int j = i + len;
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + (balloons[i] * balloons[k] * balloons[j]) + dp[k][j]);
                }
            }
        }
        
        return dp[0][m - 1];
    }
};
