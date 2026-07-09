class Solution {
public:
//approach 2 (another brute force)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Merge both arrays into one
        vector<int> merged = nums1;
        merged.insert(merged.end(), nums2.begin(), nums2.end());
        
        // Sort the merged array
        sort(merged.begin(), merged.end());
        
        int n = merged.size();
        if (n % 2 == 1) {
            // Odd length → middle element
            return merged[n/2];
        } else {
            // Even length → average of two middle elements
            return (merged[n/2 - 1] + merged[n/2]) / 2.0;
        }
    }
};
