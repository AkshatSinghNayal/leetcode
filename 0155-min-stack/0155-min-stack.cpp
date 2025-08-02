class MinStack {
public:
    stack<int> st; 
    stack<int> mini ; 

    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mini.empty() || val<=mini.top()){
            mini.push(val);
        }
    }
    
    void pop() {
        if(st.top()== mini.top()){
            mini.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mini.top();
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