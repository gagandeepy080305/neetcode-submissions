class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        for(int i=0;i<n;i++){
            int lmax = 0;
            int rmax = 0;
            for(int j=0;j<=i;j++){
                lmax = max(lmax,height[j]);
            }
            for(int j=i;j<n;j++){
                rmax= max(rmax,height[j]);
            }
            water = water + min(lmax,rmax)-height[i];
        }
        return water;
    }
    
};
