class Solution {
public://my approach but not optimal but better T.C. than solution 1
//set stores in tree fashion so T.C. is O(nlogn) where as unordered_set is like hashset
//with T.C. as O(n)
// T.C. - O(n)
//S.C. - O(n)
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>st;
        for(int it : nums){
            if(st.find(it)!=st.end())return it;
            st.insert(it);
        }
        return -1;
    }
};
