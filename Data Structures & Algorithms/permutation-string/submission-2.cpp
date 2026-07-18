class Solution {
public://optimal solution 
// new one , previous is also optimal 
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n2<n1)return false;
        vector<int>freq1(26,0);
        vector<int>freq2(26,0);
        for(char ch : s1){
            freq1[ch-'a']++;
        }
        for(int i = 0;i<n1;i++){
            freq2[s2[i]-'a']++;
        }
        if(freq1==freq2)return true;
        for(int i=n1;i<n2;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n1]-'a']--;
            if(freq1==freq2)return true;
        }
        return false;
    }
};
