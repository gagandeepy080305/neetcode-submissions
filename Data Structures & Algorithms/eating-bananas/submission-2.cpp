class Solution {
public://optimal approach
    int calltime(vector<int>& arr, int k) {
        long long totalhrs = 0;
        for (int pile : arr) {
            totalhrs += (pile + k - 1) / k; // ceil(pile/k)
        }
        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxel = *max_element(piles.begin(), piles.end());
        int low = 1 , high = maxel,ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)/2;
            long long time = calltime(piles,mid);
            if(time<=h){
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans ;
    }
};
