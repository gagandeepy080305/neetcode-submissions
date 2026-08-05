class Solution {
public://optimal solution
//T.C. - O(n^2)
//S.C. - O(1)

    void expand(int left , int right ,string& s,int& start ,int& maxLen){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        int len = right-left-1;
        if(len>maxLen){
            maxLen = len;
            start=left+1;
        }
    }

    string longestPalindrome(string s) {
        int n = s.length();
        if(n<=1)return s;
        int start = 0;
        int maxLen = 1;
        for(int i=0;i<n;i++){
            expand(i,i,s,start,maxLen);//odd length

            expand(i,i+1,s,start,maxLen);//even length
        }
        return s.substr(start,maxLen);
    }
};
