class MinStack {
public:
    // stack<int> s;
    // vector<int> v;
    // int min;
    // MinStack() {
    //     min=INT_MAX;
    // }
    
    // void push(int val) {
    //     // s.push(val);
    //     v.emplace_back(val);
    //     min = *min_element(v.begin(),v.end());
    //     // sort(v.begin(),v.end());
    // }
    
    // void pop() {
    //     // remove(v.begin(),v.end(),s.top());
    //     // sort(v.begin(),v.end());
    //     v.pop_back();
    //     min = *min_element(v.begin(),v.end());

    // }
    
    // int top() {
    //     return v.back();
    // }
    
    // int getMin() {
    //     return min;
    // }
    typedef struct node{
        int v;
        int minUntilNow;
        node* next;
    }node;

    
    MinStack() : topN(nullptr){
        
    }
    
    void push(int val) {
        // node n {val,val,nullptr};
        node* n = new node;
        n->v = n->minUntilNow = val;
        n->next = nullptr;
        
        
        if(topN == nullptr){
            topN = n;
        }

        else{
            n->minUntilNow = min(n->v,topN->minUntilNow);
            n->next = topN;
            topN = n;
        }
    }
    
    void pop() {
        topN = topN->next;
    }
    
    int top() {
        return topN->v;
    }
    
    int getMin() {
        return topN->minUntilNow;
    }

    private:
    node* topN;


};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
