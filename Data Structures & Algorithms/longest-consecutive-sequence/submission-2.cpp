class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lastsmall = INT_MIN;
        int cnt = 0;
        int longest=1;
        for(int i=0;i<n;i++){
            if(nums[i]-1 == lastsmall){
                cnt+=1;
                lastsmall=nums[i];
            }
            else if(lastsmall != nums[i]){
                cnt = 1;
                lastsmall = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
    }

};
