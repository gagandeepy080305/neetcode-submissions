class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int len= 0;
        unordered_set<int>st;
        for(int it : nums){
            st.insert(it);
        }
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)==st.end()){
                int cnt = 1;
                int x = nums[i]+1;
                while(st.find(x)!=st.end()){
                    cnt++;
                    x=x+1;
                }
                len = max(cnt,len);
            }
            
        }
        return len;
    }
};
