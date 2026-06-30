class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            int a = nums[i];
            int need = target - a;
            if(mpp.find(need)!=mpp.end()){
                return {mpp[need],i};
            }
            mpp[a] = i;
        }
        return {};
    }
};
 