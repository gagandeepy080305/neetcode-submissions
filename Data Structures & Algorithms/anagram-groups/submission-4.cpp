class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mpp;
        vector<vector<string>>ans;

        for(auto str : strs){
            string temp = str;
            sort(str.begin(),str.end());
            mpp[str].push_back(temp);
        }

        for(auto it : mpp){
            ans.push_back(it.second);
        }

        return ans;



    }
};
