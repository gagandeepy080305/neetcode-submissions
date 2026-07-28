class Solution {
public://optimal
//T.C. - O(n* 2^n)
//S.C. - O(n* 2^n)

    void getAllSubsets(vector<int>& nums , int i , vector<int>&comb ,vector<vector<int>>&allSubset ){
        if(i==nums.size()){
            allSubset.push_back(comb);
            return;
        };

        //Inclusion call
        comb.push_back(nums[i]);
        getAllSubsets(nums,i+1,comb,allSubset);

        //exclude-backtrack
        comb.pop_back();

        //while backtrack we sjould not choose the duplicate elem so the below code to skip it 
        int idx = i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1])idx++;
        getAllSubsets(nums,idx,comb,allSubset);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>comb;
        vector<vector<int>>allSubset;
        getAllSubsets(nums,0,comb,allSubset);
        return allSubset;
    }
};
