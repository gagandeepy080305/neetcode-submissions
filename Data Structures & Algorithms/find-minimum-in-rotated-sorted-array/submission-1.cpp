class Solution {
public://trial
    int findMin(vector<int> &nums) {
        return *min_element(nums.begin(),nums.end());
    }
};
