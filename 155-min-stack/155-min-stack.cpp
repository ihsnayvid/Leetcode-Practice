class MinStack {
public:
    stack<int> s,s2;
    int mn = INT_MAX;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(s2.empty() or val<=s2.top()) s2.push(val);        
    }
    
    void pop() {
        
        if(s2.top() == s.top()){
            s2.pop();
        }
        s.pop();
            
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return s2.top();
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