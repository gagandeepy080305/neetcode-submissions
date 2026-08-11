class Solution {
public://better solution - tabulation
//T.C. - O(n*totSum)
//S.C. - O(n*totSum)

//dp[i][sum]-number of different ways to reach target for curr sum starting from index i

    int findTargetSumWays(vector<int>& nums, int target) {
        int  n = nums.size();
        int totSum = 0;
        for(auto num : nums)totSum+=num;
        int offset = totSum;
        if(abs(target) > totSum)return 0;
        vector<vector<int>>dp(n+1,vector<int>(2*totSum+1,0));
        dp[n][target+offset] = 1;
        for(int i=n-1;i>=0;i--){
            for(int sum=-totSum;sum<=totSum;sum++){
                int pos = sum+nums[i];
                int neg = sum-nums[i];
                if(pos <= totSum )dp[i][sum+offset] += dp[i+1][sum+nums[i]+offset];
                if(neg >= -totSum)dp[i][sum+offset] += dp[i+1][sum-nums[i]+offset];
                

            }
        }
        return dp[0][offset];
    }
};
