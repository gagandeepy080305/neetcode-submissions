class Solution {
public://trial
    int findMin(vector<int> &nums) {
        sort(nums.begin(),nums.end());
        int res = *min_element(nums.begin(),nums.end());
        return res;
    }
};
