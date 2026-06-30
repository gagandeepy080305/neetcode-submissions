class Solution {
public://my method of brute force
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(n<m)return false;
        string sort1 = s1;
        sort(sort1.begin(),sort1.end());
        for(int i=0;i<=n-m;i++){
            string sub = s2.substr(i,m);
            sort(sub.begin(),sub.end());
            if(sub==sort1)return true;
        }
        return false;
    }
};
