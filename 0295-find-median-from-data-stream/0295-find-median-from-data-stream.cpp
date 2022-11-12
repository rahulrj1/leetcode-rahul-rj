class MedianFinder {
public:
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> mpq;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        pq.push(num);
        mpq.push(pq.top());
        pq.pop();
        
        if(pq.size()<mpq.size()) {
            pq.push(mpq.top());
            mpq.pop();
        }
    }
    
    double findMedian() {
        return pq.size() == mpq.size() ? (double)(pq.top()+mpq.top())*1.0/2.0 : pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */