class Solution {
public://optimal
//T.C. - O(Cₙ * n)
//S.C. - O(n)

    void helper(int n , vector<string>&ans ,string& comb,int open , int close){
        if(open==n && close==n){
            ans.push_back(comb);
            return;
        }
    
        if(open<n){//check if we call include '(' - if yes then recurse for next backtrack and check for other solution 
            comb.push_back('(');
            helper(n,ans,comb,open+1,close);
            comb.pop_back();
        }
        if(close < open){//check if we call include '(' - if yes then recurse for next backtrack and check for other solution 
            comb.push_back(')');
            helper(n,ans,comb,open,close+1);
            comb.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string comb="";
        helper(n,ans,comb,0,0);
        return ans;
    }
};
