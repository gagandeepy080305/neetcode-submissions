class Solution {
public://optimal solution
//T.C. - O(n)
//S.C. - O(1)
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>maxVal(3);
        for(auto triplet : triplets){
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]){
                maxVal[0] = max(maxVal[0],triplet[0]);
                maxVal[1] = max(maxVal[1],triplet[1]);
                maxVal[2] = max(maxVal[2],triplet[2]);
            }
        }
        return maxVal[0]==target[0] && maxVal[1]==target[1] && maxVal[2]==target[2];
    }
};
