class Solution {
public://optimal
//T.C. - O(2^n * k)
//S.C. - O(k * x) 

    void helper(vector<int>&arr , int idx , int target , vector<int>&ds , vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1])continue;
            if(arr[i]>target)break;
            ds.push_back(arr[i]);
            helper(arr,i+1,target-arr[i],ds,ans);
            ds.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>ds;//this is combination
        vector<vector<int>>ans;
        helper(candidates,0,target,ds,ans);
        return ans;
    }
};
