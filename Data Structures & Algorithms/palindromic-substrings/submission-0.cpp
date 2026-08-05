class Solution {
public://optimal solution
//T.C. - O(n^2)
//S.C. - O(1)
    int cnt = 0;
    int countPallin(int left , int right , string& s){
        while(left>=0 && right<s.length() && s[left]==s[right]){
            cnt++;
            left--;
            right++;
        }
        return cnt;
    }

    int countSubstrings(string s) {
        int n = s.length();
        if(n==1)return 1;
        
        for(int i =0;i<n;i++){
            countPallin(i,i,s);//odd pallindrome
            countPallin(i,i+1,s);//even pallindrome
        }

        return cnt;
    }
};
