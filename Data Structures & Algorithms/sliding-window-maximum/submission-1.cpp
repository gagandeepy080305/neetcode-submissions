class Solution {
public://optimal solution
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>res;
        deque<int>dq;
        // first window
        for(int i=0;i<k;i++){
            while(dq.size()>0 && nums[dq.back()] <= nums[i])dq.pop_back();
            dq.push_back(i);
        }

        //calculting sliding window max from k to n 
        for(int i=k;i<n;i++){
            res.push_back(nums[dq.front()]);
            while(dq.size() && dq.front() <= i-k)dq.pop_front();
            while(dq.size() > 0 && nums[dq.back()] <= nums[i])dq.pop_back();
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);
        return res;
    }
};
