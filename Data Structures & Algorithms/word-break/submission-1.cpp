class Solution {
public://optimal solution
//T.C. - O(n^2)
//S.C. - O(n)
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict;
        int n = s.size();
        for (string word : wordDict){
            dict.insert(word);
        }

        int maxLen = 0;
        for(auto it : dict){
            maxLen = max(maxLen,(int)it.length());
        }

        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=max(0,i-maxLen);j--){
                if(dp[j] && dict.find(s.substr(j,i-j))!=dict.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];

    }
};
