class Solution {
public://my approach but not optimal 
// T.C. - O(nlogn)
//S.C. - O(n)
    int findDuplicate(vector<int>& nums) {
        set<int>st;
        for(int it : nums){
            if(st.find(it)!=st.end())return it;
            st.insert(it);
        }
        return -1;
    }
};
