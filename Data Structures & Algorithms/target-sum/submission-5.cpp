class Solution {
public://optimal solution - tabulation along with space optimized
//T.C. - O(n*totSum)
//S.C. - O(totSum)
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(auto num : nums)totSum+=num;
        if(abs(target) > totSum)return 0;
        vector<int>curr(2*totSum+1,0);
        vector<int>next(2*totSum+1,0);
        int offset = totSum;

        next[target+offset] = 1;
        for(int i=n-1;i>=0;i--){
            for(int sum = -totSum ; sum<=totSum;sum++){
                int pos = sum+nums[i];
                int neg = sum-nums[i];

                if(pos <= totSum){
                    curr[sum+offset] += next[pos+offset];
                }

                if(neg >= -totSum){
                    curr[sum+offset] += next[neg+offset];
                }
                
            }
            next = curr;
            fill(curr.begin(), curr.end(), 0);
        }
        return next[offset];
    }
};
