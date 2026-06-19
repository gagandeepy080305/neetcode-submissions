class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int i,j,flag=0;
        for(i=0;i<nums.size();i++)
        {
            for(j=i+1;j<nums.size();j++)
            {
                if(nums[i]==nums[j])
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1)
        {
            return true;
        }
        return false;
    }
};