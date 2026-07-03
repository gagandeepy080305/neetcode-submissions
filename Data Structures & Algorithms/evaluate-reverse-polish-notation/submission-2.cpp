class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int num1,num2,res;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                num1 = st.top();//first poped is right operand
                st.pop();
                num2 = st.top();//first poped is left operand
                st.pop();
                if(tokens[i]=="+")st.push(num2+num1);
                else if(tokens[i]=="-")st.push(num2-num1);
                else if(tokens[i]=="*")st.push(num1*num2);
                else if(tokens[i]=="/")st.push(num2/num1);
            }

            else st.push(stoi(tokens[i]));
        }
        res = st.top();
        return res;
    }
};
