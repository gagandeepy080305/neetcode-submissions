class Solution {
public:
    int maxArea(vector<int>& heights) {
        vector<int>v;
        int n = heights.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++)
            {
                int width = j-i;
                int height = 0;
                if(heights[i]<heights[j])height=heights[i];
                else height = heights[j];
                int maxwater = width * height;
                v.push_back(maxwater);
            }
        }
        int ans = *max_element(v.begin(), v.end());
        return ans;
    }
};
