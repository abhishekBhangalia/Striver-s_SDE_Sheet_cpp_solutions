class MyQueue {
    stack<int> st;
    
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st.size()==0){
            st.push(x);
            return;
        }
        stack<int> tmp; 
        while(st.size()){
            tmp.push(st.top());
            st.pop();
        }
        st.push(x);
        while(tmp.size()){
            st.push(tmp.top());
            tmp.pop();
        }
    }
    
    int pop() {
        if(st.size()==0)    return -1;
        int x = st.top();
        st.pop();
        return x;
    }
    
    int peek() {
        if(st.size()==0)    return -1;
        return st.top();
    }
    
    bool empty() {
        return st.size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
