class Solution {
public://better solution - memoiation
//T.C. - O(s1_len * s2_len)
//S.C. - O(s1_len * s2_len)+ O(s1_len + s2_len) recursion stack


//dp[i][j] - can we reach/form s3 from the current positions i in s1 and j in s2
    bool helper(int i , int j , string& s1, string& s2, string& s,vector<vector<int>>&dp){
        if(i==s1.length() && j==s2.length())return true;
        if(dp[i][j] != -1)return dp[i][j];
        bool takes1 = false;
        bool takes2 = false;

        if(i < s1.length() && s1[i]==s[i+j])takes1 = helper(i+1,j,s1,s2,s,dp);
        if(j < s2.length() && s2[j]==s[i+j])takes2 = helper(i,j+1,s1,s2,s,dp);
        return dp[i][j] = takes1 || takes2;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.length() + s2.length() != s3.length())return false;

        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,-1));
        return helper(0,0,s1,s2,s3,dp);
    }
};
