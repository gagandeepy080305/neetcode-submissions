class Solution {
public://brute force (my approach)
//T.C. - O(n+m)
//S.C. - O(n+m)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        double ans;
        int i =0, j=0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }
            else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size()){
            res.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size()){
            res.push_back(nums2[j]);
            j++;
        }
        int l = 0 , r = res.size()-1;
        int mid = (l+r)/2;
        if((res.size())%2==0){
            int val1 = mid;
            int val2 = mid+1;
            ans = (res[val1]+res[val2])/2.0;
        }
        else{
            ans = res[mid];
        }
        return ans;
    }
};
