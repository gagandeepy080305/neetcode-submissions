class Solution {
public:
    // Space Optimized (Using prev & cur)
    // Time Complexity: O(n * amount)
    // Space Complexity: O(amount)

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);

        // Base Case
        for (int target = 0; target <= amount; target++) {
            if (target % coins[0] == 0)
                prev[target] = target / coins[0];
            else
                prev[target] = 1e9;
        }

        for (int idx = 1; idx < n; idx++) {

            for (int target = 0; target <= amount; target++) {

                int notTake = prev[target];

                int take = 1e9;
                if (coins[idx] <= target)
                    take = 1 + cur[target - coins[idx]];

                cur[target] = min(notTake, take);
            }

            prev = cur;
        }

        int ans = prev[amount];

        return (ans >= 1e9) ? -1 : ans;
    }
};