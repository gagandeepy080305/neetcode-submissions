class Solution {
public://optimal solution
    bool isvalid(int mapS[] , int mapT[]){
        for(int i=0;i<256;i++){
            if(mapT[i] > mapS[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int mapS[256] = {0};
        int mapT[256] = {0};
        int slen = s.size();
        int tlen = t.size();
        int minLen = INT_MAX;
        int left = 0 , right = 0 , minStart = 0;

        //populate T 
        for(char ch : t){
            mapT[ch]++;
        } 

    //sliding window logic
    for(int right=0;right<slen;right++){
        mapS[s[right]]++;
        while(isvalid(mapS,mapT)){
            if(right - left + 1 < minLen){
                minLen = right-left+1;
                minStart = left;
            }
            mapS[s[left]]--;
            left++;
        }
    }
    return (minLen==INT_MAX)?"":s.substr(minStart,minLen);

    }
};
