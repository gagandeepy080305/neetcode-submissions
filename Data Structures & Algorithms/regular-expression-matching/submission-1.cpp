class Solution {
public:// Better solution - Memoization
// T.C. - O(s_len * p_len)
// S.C. - O(s_len * p_len) + O(s_len + p_len) recursion stack
    bool helper(int i , int j ,string s, string p,vector<vector<int>>&dp ){
        if(j==p.length())return i==s.length();
        if(i==s.length()){
            if(j+1<p.length() && p[j+1] == '*'){
                return helper(i,j+2,s,p,dp);
            }
            return false;
        }
        if(dp[i][j] != -1)return dp[i][j];
        bool match = (s[i]== p[j] || p[j]=='.');
        if(j+1 < p.length() && p[j+1] == '*'){
            if(match)return dp[i][j] = helper(i,j+2,s,p,dp) || helper(i+1,j,s,p,dp);
            return dp[i][j] = helper(i,j+2,s,p,dp);
        }
        if(match)return dp[i][j] = helper(i+1,j+1,s,p,dp);
        return dp[i][j] = 0;
    }

    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.length()+1,vector<int>(p.length()+1,-1));
        return helper(0,0,s,p,dp);
    }
};
