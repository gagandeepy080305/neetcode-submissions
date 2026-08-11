class Solution {
public://better solution - memoiation
//T.C. - O(n * totSum)
//S.C. - O(n * totSum)
    int helper(int i,vector<int>& nums, int target,int sum,vector<vector<int>>&dp,int offset){
        
        if(i==nums.size())return (sum==target);
        if(dp[i][sum+offset]!=-1)return dp[i][sum+offset];
        int putPos = helper(i+1,nums,target,sum+nums[i],dp,offset);
        int putNeg = helper(i+1,nums,target,sum-nums[i],dp,offset);
        return dp[i][sum+offset] = putPos+putNeg;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int num : nums)totSum+=num;
        vector<vector<int>>dp(n+1,vector<int>(2*totSum+1,-1));
        //dp[i][sum]-number of different ways to reach target for curr sum starting from index i
        return helper(0,nums,target,0,dp,totSum);
    }
};