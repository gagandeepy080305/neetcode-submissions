class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // brute force
        int n = temperatures.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(temperatures[i]<temperatures[j]){
                    res[i] = j-i;
                    break;
                }
            }
        }
        return res;
    }
};
