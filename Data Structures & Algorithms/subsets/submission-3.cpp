class Solution {
public://optimal
//T.C. - O(n * 2^n)
//S.C. - O(n * 2^n)
vector<vector<int>>ans;
vector<int>subset;

    void solve(vector<int>&nums , int start){
        //store the current subset
        ans.push_back(subset);

        //try including every element from 'start' onwards
        for(int i =start ; i<nums.size();i++){
            //Include current element 
            subset.push_back(nums[i]);

            //recurse for the remanining elements
            solve(nums,i+1);

            //backtrack (remove the added element)
            subset.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
};
