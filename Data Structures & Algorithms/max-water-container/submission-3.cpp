class Solution {
public:
    int maxArea(vector<int>& heights) { 
        int n = heights.size();
        int ans = 0;
        int left = 0;
        int right = n-1;
        while(left<right){
            int width = right - left;
            int height = min(heights[left],heights[right]);
            int res = width*height;
            ans = max(ans,res);
            if(heights[left]<heights[right])left++;
            else right--;
        }
        return ans;
    }
};
