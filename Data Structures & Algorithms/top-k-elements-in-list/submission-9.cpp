class Solution {
public://revision
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        int n = nums.size();
        for(int it : nums){
            mpp[it]++;
        }
        vector<vector<int>>bucket(n+1);
        for(auto it : mpp){
            int num = it.first;
            int freq = it.second;
            bucket[freq].push_back(num);
        }
        for(int i = n;i>=1 && ans.size() < k ;i--){
           for(int num : bucket[i]){
            ans.push_back(num);
            if(ans.size()==k){
                return ans;
            }
           }
        }
        return ans;
    }
};
