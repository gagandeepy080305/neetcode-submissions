class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            set<char>st;
            for(int j=i;j<n;j++){
                if(st.count(s[j])==1)break;
                int len = j-i+1;
                maxlen = max(maxlen,len);
                st.insert(s[j]);
            }
        }
        return maxlen;
    }
};
