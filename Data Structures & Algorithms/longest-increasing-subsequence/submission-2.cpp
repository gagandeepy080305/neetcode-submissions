class Solution {
public://optimal solution
// T.C. - O(n log n)
// S.C. - O(n)

    int lengthOfLIS(vector<int>& nums) {

        vector<int> temp;

        for(int i = 0; i < nums.size(); i++) {

            if(temp.empty() || nums[i] > temp.back()) {
                temp.push_back(nums[i]);
            }
            else {
                int idx = lower_bound(temp.begin(), temp.end(), nums[i])
                          - temp.begin();

                temp[idx] = nums[i];
            }
        }

        return temp.size();
    }
};