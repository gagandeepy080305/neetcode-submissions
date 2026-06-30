class Solution {
public:
    bool isFreqSame(int freq1[] , int freq2[]){
        for(int i=0;i<26;i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        int freq[26] = {0};
        for(int i=0;i<n1;i++){
            freq[s1[i]-'a']++;
        }
        int windows = n1;
        for(int i=0;i<n2;i++){
            int windidx = 0,idx=i;
            int windf[26] = {0};
            while(windidx<windows && idx < n2){
                windf[s2[idx]-'a']++;
                windidx++;
                idx++;
            }
            if(isFreqSame(freq,windf))return true;
        }
        return false;
    }
};
