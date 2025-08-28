class MinStack {
private:
    stack<pair<int,int>> st; // {val, minSoFar}
    
public:
    MinStack() {}
    
    void push(int val) {
        if (st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
