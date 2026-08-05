class Solution {
public://better solution - time & space optimized
//T.C. - O(n)
//S.C. - O(1)
    int numDecodings(string s) {
        int n = s.size();
        int prev1 = 1;
        int prev2 = (s[0]=='0') ? 0 : 1 ;
        int res = prev2;
        if(n==1)return prev2;
        for(int i = 2 ; i<=n;i++){
            int curr = 0;
            int oneDigit = stoi(s.substr(i-1,1));
            int twoDigit = stoi(s.substr(i-2,2));
            if(oneDigit>=1)curr += prev2;
            if(twoDigit >= 10 && twoDigit<=26)curr +=prev1;
            prev1 = prev2;
            prev2 = curr;  
        }
        return prev2;
    }
};
