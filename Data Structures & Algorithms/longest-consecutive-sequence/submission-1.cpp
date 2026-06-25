class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        int longest = 1,x;
        int n = nums.size();
        for(int i=0;i<n;i++){
            x = nums[i];
            int cnt = 1;
            while(ls(nums,x+1)==true){
                x = x+1;
                cnt+=1;
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
    bool ls(vector<int>&arr,int num){
        for(int i=0;i<arr.size();i++){
            if(arr[i]==num)return true;
        }
        return false;
    }

};
