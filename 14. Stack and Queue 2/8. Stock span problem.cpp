class StockSpanner {
    stack<pair<int,int>> st;
public:

    StockSpanner() {
        
    }
    
    // //TC-O(n^2), SC-O(1)
    // int next(int price) {
    //     st.push_back(price);
    //     int span = 0;
    //     for(int i=st.size()-1; i>=0; i--){
    //         if(st[i]<=price)    span++;
    //         else    break;
    //     }
    //     return span;
    // }


    //TC-< O(n^2), SC-O(1)
    int next(int price) {
        int span = 1;
        while(not st.empty() and st.top().first <= price){
            span += st.top().second;
            st.pop();
        }
        st.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
