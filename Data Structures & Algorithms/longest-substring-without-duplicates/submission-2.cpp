class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0,r=0;
        int ans=0;
        vector<int>hash(256,-1);
        while(r<n){
            if(hash[s[r]]!=-1){
                l = max(l,hash[s[r]]+1);
            }
            hash[s[r]] = r;
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
