class Solution {
public://brute force
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int res=0;
        for(int i=0;i<n;i++){
            int h = heights[i];
            for(int j = i;j<n;j++){
                int w = j-i+1;
                h = min(h,heights[j]);
                int area = w*h;
                res = max(area,res);
            }
        }
        return res;
    }
};
