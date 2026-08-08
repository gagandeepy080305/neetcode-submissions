class Solution {
public://optimal
//T.C. - O(n)
//S.C. - O(1)
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int product = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for(int i=0;i<n;i++){
            if(prefix==0)prefix=1;
            if(suffix==0)suffix=1;
            prefix = prefix * nums[i];
            suffix = suffix * nums[n-i-1];
            product = max(product,max(prefix,suffix));
        }
        return product;
    }
};
