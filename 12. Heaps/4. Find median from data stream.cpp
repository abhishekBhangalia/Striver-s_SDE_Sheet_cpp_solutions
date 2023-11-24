class MedianFinder {

private:
    priority_queue<int,vector<int>,greater<int>> hi;
    priority_queue<int> lo;

public:


    MedianFinder() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }


    // //TC-O(n*5*log(n/2)),SC-O(n)
    // void addNum(int num) {
    //     lo.push(num);
    //     if(lo.size()>hi.size()){
    //         hi.push(lo.top());
    //         lo.pop();
    //     }
    //     else{
    //         hi.push(lo.top());
    //         lo.pop();
    //         lo.push(hi.top());
    //         hi.pop();
    //     }
        
    // }


    //TC-O(n*3*log(n/2)),SC-O(n)
    void addNum(int num) {
        if(hi.empty()){
            hi.push(num);
            return;
        }
        if(num >= hi.top())     hi.push(num);
        else    lo.push(num);

        if(lo.size()>hi.size()){
            hi.push(lo.top());
            lo.pop();
        }
        else if (hi.size()>lo.size()+1){//keep size of hi either equal to lo or size of lo + 1
            lo.push(hi.top());
            hi.pop();
        }
        
    }
    
    //TC-O(1)
    double findMedian() {
        if(hi.size()>lo.size()) return hi.top();
        return ((lo.top()+hi.top())/2.0);
    }


};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
