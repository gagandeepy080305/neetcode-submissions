class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int ans = INT_MIN;
        int right = n-1;
        while(left<right){
            int area = (right-left) * min(heights[left],heights[right]);
            ans = max(area,ans);
            if(heights[left] < heights[right])left++;
            else right--;
        }
        return ans;
    }
};
