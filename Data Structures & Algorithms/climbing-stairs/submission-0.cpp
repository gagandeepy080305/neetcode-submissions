class Solution {
public://optimal 
    int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        if(n>2){
            int n1 = 2;
            int n2 = 1;
            int temp;
            for(int i = 3;i<=n;i++){
                temp = n1+n2;
                n2 = n1;
                n1 = temp;
            }
            return temp;
        }
        return -1;
    }
};
