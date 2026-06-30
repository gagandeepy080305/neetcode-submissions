class Solution {
public://revision
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;
        for(auto it : strs){
            string temp = it;
            sort(temp.begin(),temp.end());
            mpp[temp].push_back(it);
        }
        for(auto it : mpp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
