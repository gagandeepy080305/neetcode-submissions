class Solution {
public://optimal solution
//T.C. - O(n)
//S.C. - O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev1 = 0;
        int prev2 = 0;
        int res = 0;

        for(int i=2;i<=n;i++){
            res = min(prev2+cost[i-1],prev1+cost[i-2]);
            prev1 = prev2;
            prev2 = res;
        }
        return res;
    }
};
