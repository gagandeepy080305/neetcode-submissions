class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        vector<int>ans;
        for(auto it : nums)
        {
           mpp[it]++; 
        }
        vector<pair<int,int>>freq;
            for(auto it : mpp)
            {
                freq.push_back({it.second,it.first});
            }
            sort(freq.begin(),freq.end(),greater<pair<int,int>>());
            
            for(int i=0;i<k;i++)
            {
                ans.push_back(freq[i].second);
            }
        return ans;
    }
};
