class Solution {
public://optimal
//solved in exponential time and space complexity 
    set<vector<int>>s;
    void helper(vector<int>&arr ,int i ,vector<int>&combNation,vector<vector<int>>&ans , int target){
        
        if(i==arr.size() || target<0)return;

        if(target==0){
            if(s.find(combNation)==s.end()){
                ans.push_back(combNation);
                s.insert(combNation);
            }
            return;
        }

        //pushing inclusion elem in vector combination
        combNation.push_back(arr[i]);

        //single inclusion of elem
        helper(arr,i+1,combNation,ans,target-arr[i]);

        //multiple inclusion
        helper(arr,i,combNation,ans,target-arr[i]);

        //elem exclusion , i.e., backtracking
        combNation.pop_back();
        helper(arr,i+1,combNation,ans,target);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>combNation;
        vector<vector<int>>ans;
        helper(nums,0,combNation,ans,target);
        return ans;
    }
};
