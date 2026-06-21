class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i=0,j=0;
        int res=1;
        vector<int>ans;
        for(i=0;i<nums.size();i++)
        {
            for(j=0;j<nums.size();j++)
            {
                if(i==j){
                    continue;
                }
                else{
                    res *= nums[j];
                }
            }
            ans.push_back(res);
            res=1;
        }
        return ans;
    }
};
