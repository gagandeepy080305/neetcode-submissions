class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26,0);
        for(char c : s)
        {
            freq[c-'a']++;
        }
        for(char ch : t)
        {
            freq[ch-'a']--;
        }
        for(int i : freq)
        {
            if(i!=0)
            {
                return false;
            }
        }
        return true;
    }
};
