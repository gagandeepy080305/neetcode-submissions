class Solution {
public:// better solution - memoiation
//T.C. - O(w1 * w2)
//S.C. - O(w1 * w2)
// dp[i][j] = minimum operations required to convert
// word1[i...] into word2[j...]
    int helper(int i,int j , string word1, string word2,vector<vector<int>>&dp){
        if(i==word1.length())return word2.length() - j;
        if(j==word2.length())return word1.length() - i;
        if(dp[i][j] != -1)return dp[i][j];
        if(word1[i] == word2[j]){
            return dp[i][j] = helper(i+1,j+1,word1,word2,dp);
        }
        int insert = helper(i,j+1,word1,word2,dp);
        int deleteChar = helper(i+1,j,word1,word2,dp);
        int replace = helper(i+1,j+1,word1,word2,dp);

        return dp[i][j] = 1+min({insert,deleteChar,replace});
    }

    int minDistance(string word1, string word2) {   
        int w1 = word1.length();
        int w2 = word2.length();
        vector<vector<int>>dp(w1+1,vector<int>(w2+1,-1));
        return helper(0,0,word1,word2,dp);
    }
};
