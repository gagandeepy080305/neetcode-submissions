class Solution {
public://brute force
    string minWindow(string s, string t) {
        int tlen = t.size();
        int slen = s.size();
        string ans = "";
        int minLen = INT_MAX;
        int freqT[256]={0};
        for(int i=0;i<tlen;i++)
        {
            freqT[t[i]]++;
        }
        
        for(int i=0;i<slen;i++){
            int freqS[256] = {0};
            for(int j=i;j<slen;j++){
                freqS[s[j]]++;
                bool valid = true; 


                for(int k=0;k<256;k++){
                    if(freqS[k] < freqT[k]){
                        valid = false;
                        break;
                    }
                }

                if(valid){
                    int len = j-i+1;
                    if(len<minLen){
                        minLen = len;
                        ans = s.substr(i,len);
                    }
                }
            }
        }
        return ans;
    }
};
