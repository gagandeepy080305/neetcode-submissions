class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<int>v;
        int ans = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            {
                int width = j-i;
                int height = min(heights[i],heights[j]);
                int maxwater = width * height;
                ans = max(ans,maxwater);
            }
        }
        return ans;
    }
};
