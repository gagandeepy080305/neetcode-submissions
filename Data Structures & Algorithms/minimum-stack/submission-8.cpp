class MinStack {
public:
    stack<long long> st;   // use long long to avoid overflow
    long long minel = LLONG_MAX;

    MinStack() {}

    void push(int val) {
        if(st.empty()){
            st.push(val);
            minel = val;
        } else {
            if(val >= minel){
                st.push(val);
            } else {
                st.push(2LL*val - minel); // use 2LL to force long long arithmetic
                minel = val;
            }
        }
    }

    void pop() {
        long long n = st.top();
        st.pop();
        if(n < minel){
            minel = 2*minel - n;
        }
    }

    int top() {
        long long n = st.top();
        return (n >= minel) ? (int)n : (int)minel;
    }

    int getMin() {
        return (int)minel;
    }
};
