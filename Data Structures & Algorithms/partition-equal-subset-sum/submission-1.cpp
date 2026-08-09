class Solution {
public:  // better solution - Memoiation
//T.C. - O(n × target)
//S.C. - O(n × target)
    bool helper(int i, int target, int sum, vector<int>& nums, int n,vector<vector<int>>&dp) {
        if (sum==target){
            dp[i][sum] =  1;
            return dp[i][sum];
        }
        if(sum>target)return 0;
        if (i == n) {
            dp[i][sum] = 0;
            return dp[i][sum];
        }
        if(dp[i][sum]!=-1)return dp[i][sum];
        dp[i][sum] = helper(i+1,target,sum+nums[i],nums,n,dp) || helper(i+1,target,sum,nums,n,dp);
        return dp[i][sum];
    }

    bool canPartition(vector<int>& nums) { 
        int n = nums.size(); 
        int target = 0;
        for(auto num : nums){
            target+=num;
        }
        if(target%2==1)return false;
        target=target/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return helper(0,target,0,nums,n,dp);
    }
};
