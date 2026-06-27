class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        int lmax = 0,rmax =0;
        int l = 0 ,r = n-1;
        while(l<r){
            lmax = max(lmax,height[l]);
            rmax = max(rmax,height[r]);
            if(lmax < rmax ){
                water+=lmax-height[l];
                l++;
            }
            else{
                water+=rmax-height[r];
                r--;
            }

        }
        return water;
    }
    
};
