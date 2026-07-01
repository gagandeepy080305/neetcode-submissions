class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            char symb = s[i];
            if(symb == '[' || symb == '(' || symb == '{'){
                st.push(symb);
            }
            else{
                if(st.empty())return false;
                if(symb == ']' && st.top() == '[' || symb == '}' && st.top() == '{' || symb == ')' && st.top() == '('){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.empty())return true;
        return false;
    }
};
