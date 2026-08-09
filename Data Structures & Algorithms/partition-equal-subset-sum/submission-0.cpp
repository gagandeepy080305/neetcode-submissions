class Solution {
public://brute force - recurssion
//T.C. - O(2^n)
//S.C. - O(n)

    bool helper(int i ,vector<int>& nums,int sum , int target,int n){
        if(sum==target)return true;
        if(i==n)return false;
        
        return helper(i+1,nums,sum+nums[i],target,n) || helper(i+1,nums,sum,target,n);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int num : nums){
            target+=num;
        }
        if(target%2==1)return false;
        target = target/2;
        return helper(0,nums,0,target,n);
    }
};
