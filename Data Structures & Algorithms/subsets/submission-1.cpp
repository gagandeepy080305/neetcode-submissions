class Solution {
public://optimal , but chatGPT way of code
//T.C. - O(n * 2^n)
//S.C. - O(n * 2^n)
vector<vector<int>>ans;
vector<int>subset;

    void solve(int index , vector<int>&nums){
        if(index == nums.size()){
            ans.push_back(subset);
            return;
        }

        //Pick
        subset.push_back(nums[index]);
        solve(index+1,nums);

        //backtrack
        subset.pop_back();

        //Not Pick
        solve(index+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        solve(0,nums);
        return ans;
    }
};
