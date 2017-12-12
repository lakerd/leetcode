class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x <= minSt.top()) {
            minSt.push(x);
        }
    }
    
    void pop() {
        int x = st.top();
        st.pop();
        if (x == minSt.top()) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */