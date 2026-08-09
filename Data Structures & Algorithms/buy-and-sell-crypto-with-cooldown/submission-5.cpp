class Solution {
public://optimal solution - tabulation
//T.C. - O(n)
//S.C. - O(1)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>curr(2,0);
        vector<int>nextNext(2,0);//for after sell we need track of after 2 days
        vector<int>next(2,0);//for buy or skip we need track of next
        for(int i=n-1;i>=0;i--){
            curr[0] = max(next[0] , -prices[i] + next[1]);//if not hold {skip,buy}
            curr[1]= max(next[1] , prices[i]+nextNext[0]);//if hold {skip,sell} 
            
            nextNext = next;
            next = curr;
        }
        return next[0];
    }
};
