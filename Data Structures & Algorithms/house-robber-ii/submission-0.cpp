class Solution {
public://better solution
//T.C. - O(n)
//S.C. - O(n)
    int helper(vector<int>& nums,int start , int end){//this function is house robber 1 logic
    int n = nums.size();
    vector<int>dp(n-1);
    dp[0] = nums[start];
    dp[1] = max(nums[start],nums[start+1]);

    for(int i=start+2,j=2;i<=end;i++,j++){
        dp[j] = max(dp[j-1],dp[j-2]+nums[i]);
    }

    return dp[n-2];
    }

    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        if(nums.size()==2)return max(nums[0],nums[1]);
        return max(helper(nums,0,nums.size()-2) , helper(nums,1,nums.size()-1));
    }
};
