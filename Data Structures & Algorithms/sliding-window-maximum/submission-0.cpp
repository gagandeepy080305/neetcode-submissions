class Solution {
public://brute force
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;
        for(int i=0 ;i<=n-k;i++){
            int currMax = INT_MIN;
            for(int j=i;j<i+k;j++){
                currMax = max(currMax,nums[j]);
            }
            res.push_back(currMax);
        }
        return res;
    }
};
