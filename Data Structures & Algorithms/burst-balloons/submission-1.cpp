class Solution {
public:/// Better solution - memoization
// T.C. - O(n^3)
// S.C. - O(n^2) + O(n) recursion stack

    int helper(int i , int j ,vector<int>& nums,vector<vector<int>>&dp ){
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int maxi = INT_MIN;
        for(int k=i;k<=j;k++){
            int coins = nums[i-1] * nums[k] * nums[j+1] + helper(i,k-1,nums,dp) + helper(k+1,j,nums,dp);
            maxi = max(maxi,coins);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(1,nums.size()-2,nums,dp);
    }
};
