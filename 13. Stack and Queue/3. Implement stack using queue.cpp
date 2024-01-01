class MyStack {
    queue<int> q;
public:
    MyStack() {
        
    }
    
    // SC-O(2n)
    // void push(int x) {
    //     if(q.empty()){
    //         q.push(x);
    //         return;
    //     }
    //     queue<int> tmp;
    //     while(!q.empty()){
    //         tmp.push(q.front());
    //         q.pop();
    //     }
    //     q.push(x);
    //     while(!tmp.empty()){
    //         q.push(tmp.front());
    //         tmp.pop();
    //     }
    // }


    //SC-O(n)
    void push(int x) {
        q.push(x);
        int n = q.size()-1;
        while(n--){
            int front = q.front();
            q.pop();
            q.push(front);
        }
    }
    
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
