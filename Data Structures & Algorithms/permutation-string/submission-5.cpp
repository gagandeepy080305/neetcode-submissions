class Solution {
public:

    bool checkFreq(vector<int>&have , vector<int>&need){
        for(int i=0;i<256;i++){
            if(have[i] != need[i])return false;
        }
        return true;
    }


    bool checkInclusion(string s1, string s2) {
        int s1l = s1.length();
        int s2l = s2.length();
        if(s2l<s1l)return false;
        int low=0,high;
        vector<int>need(256,0);//s1
        vector<int>have(256,0);//s2
        for(char ch:s1)need[ch]++;
        for(int i=0;i<s1l;i++)have[s2[i]]++;
        if(checkFreq(have,need))return true;
        for(high = s1l;high<s2l;high++){
            have[s2[low]]--;
            low++;

            have[s2[high]]++;
            if(checkFreq(have,need))return true;
        }
        return false;
    }
};
