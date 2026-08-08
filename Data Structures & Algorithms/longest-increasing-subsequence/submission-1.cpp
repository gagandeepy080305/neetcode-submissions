class Solution {
public://better solution - memoiation
//T.C. - O(n^2)
//S.C. - O(n^2)
    int helper(int i,int prev,vector<int>& nums,int n,vector<vector<int>>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i][prev+1] != -1)return dp[i][prev+1];
        int len = 0+helper(i+1,prev,nums,n,dp);
        if(prev==-1 || nums[i]>nums[prev]){
            len = max(len,1+helper(i+1,i,nums,n,dp));
        }
        return dp[i][prev+1]=len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int prev = -1;
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,prev,nums,n,dp);
    }
};
