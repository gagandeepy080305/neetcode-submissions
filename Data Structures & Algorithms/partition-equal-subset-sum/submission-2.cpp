class Solution {
public://optimal solution - tabulation
//T.C. -  O(n × target)
//S.C. -  O(target)
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;
        for(int num : nums)totalSum+=num;
        if(totalSum%2==1)return false;
        int target = totalSum/2;

        vector<bool>dp(target+1,false);
        dp[0] = true;
        for(int num :  nums){
            for(int sum=target;sum>=num;sum--){
                dp[sum] = dp[sum] || dp[sum-num];
            }
        }
        return dp[target];
    }
};
