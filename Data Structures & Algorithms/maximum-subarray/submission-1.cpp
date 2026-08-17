class Solution {
public://optimal solution - Kadanes algo
//T.C. - O(n)
//S.C. - O(1)
    int maxSubArray(vector<int>& nums) {
        int sum = 0,maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum = sum+nums[i];
            maxi = max(maxi,sum);
            if(sum<0)sum=0;
        }
        return maxi;
    }
};
