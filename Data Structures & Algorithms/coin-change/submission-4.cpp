class Solution {
public:
    // Tabulation (Bottom-Up DP)
    // Time Complexity: O(n * amount)
    // Space Complexity: O(n * amount)

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // Base Case
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                dp[0][target] = target / coins[0];
            else
                dp[0][target] = 1e9;
        }

        // Fill the DP table
        for (int idx = 1; idx < n; idx++) {
            for (int target = 0; target <= amount; target++) {

                int notTake = dp[idx - 1][target];

                int take = 1e9;
                if (coins[idx] <= target)
                    take = 1 + dp[idx][target - coins[idx]];

                dp[idx][target] = min(notTake, take);
            }
        }

        int ans = dp[n - 1][amount];

        return (ans >= 1e9) ? -1 : ans;
    }
};