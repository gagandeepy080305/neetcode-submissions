class Solution {
public:

    // Space Optimized
    // T.C. - O(n*m)
    // S.C. - O(m)

    bool isInterleave(string s1, string s2, string s3) {

        if(s1.length() + s2.length() != s3.length())
            return false;

        int n = s1.length();
        int m = s2.length();

        vector<int> curr(m+1, 0);
        vector<int> next(m+1, 0);

        // dp[n][m]
        next[m] = 1;

        // Last row -> dp[n][j]
        for(int j=m-1; j>=0; j--) {
            if(s2[j] == s3[n+j])
                next[j] = next[j+1];
        }

        for(int i=n-1; i>=0; i--) {

            // VERY IMPORTANT
            fill(curr.begin(), curr.end(), 0);

            // Last column -> dp[i][m]
            if(s1[i] == s3[i+m])
                curr[m] = next[m];

            for(int j=m-1; j>=0; j--) {

                if(s1[i] == s3[i+j])
                    curr[j] = curr[j] || next[j];

                if(s2[j] == s3[i+j])
                    curr[j] = curr[j] || curr[j+1];
            }

            next = curr;
        }

        return next[0];
    }
};