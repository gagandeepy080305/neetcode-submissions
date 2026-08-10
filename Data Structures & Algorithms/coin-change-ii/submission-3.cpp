class Solution {
public://optimal solution - Tabulation with space optimized
//T.C. - O(n*amount)
//S.C. - O(1)
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int>next(amount+1,0);
        vector<int>curr(amount+1,0);
        next[amount] = 1;
        for(int i=n-1;i>=0;i--){
            curr[amount]=1;
            for(int sum=amount-1;sum>=0;sum--){
                curr[sum] = next[sum];//not take
                if(sum+coins[i] <= amount) curr[sum] += curr[sum+coins[i]];//take 
                next=curr;
            }
        }
        return next[0];
    }
};
