class MinStack {
public:
    stack<int> st ; 
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
       st.pop();
    }
    
    int top() {
        
        return st.top();
    }
    
    int getMin() {
         stack<int> temp = st; // Create a copy of the current stack
        int mini = INT_MAX;

        while (!temp.empty()) {
            mini = min(mini, temp.top());
            temp.pop();
    }
    return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */