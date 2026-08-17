class Solution {
public://optimal solution
//T.C. - O(n)
//S.C. - O(1)
    int jump(vector<int>& nums) {
        int jumps=0;
        int l=0,r=0;
        int n=nums.size();
        while(r<n-1){
            int farthest = 0;
            for(int i=l;i<=r;i++){
                farthest = max(farthest,i+nums[i]);
            }
            l=r+1;
            r=farthest;
            jumps++;
        }
        return jumps;
    }
};
