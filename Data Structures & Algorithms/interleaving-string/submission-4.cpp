class Solution {
public://better solution - tabulation
//T.C. - O(s1_len * s2_len)
//S.C. - O(s1_len * s2_len)


//dp[i][j] - can we reach/form s3 from the current positions i in s1 and j in s2
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if(s1.length() + s2.length() != s3.length())return false;
        
        vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1,0));
        dp[s1.length()][s2.length()]=1;
        // s2 is completely used
        for(int i=n-1; i>=0; i--) {
            if(s1[i] == s3[i+m])
                dp[i][m] = dp[i+1][m];
        }

        // s1 is completely used
        for(int j=m-1; j>=0; j--) {
            if(s2[j] == s3[n+j])
                dp[n][j] = dp[n][j+1];
        }

        for(int i=s1.length()-1;i>=0;i--){
            for(int j=s2.length()-1;j>=0;j--){
                if(s1[i]==s3[i+j])dp[i][j]=dp[i+1][j] || dp[i][j];
                if(s2[j]==s3[i+j])dp[i][j]=dp[i][j+1]||dp[i][j];
            }
        }

        return dp[0][0];
    }
};
