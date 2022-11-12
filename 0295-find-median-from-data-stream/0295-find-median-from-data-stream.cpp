class MedianFinder {
public:
    priority_queue<long> minHeap, maxHeap;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        minHeap.push(num);
        maxHeap.push(-minHeap.top());
        minHeap.pop();
        if(minHeap.size() < maxHeap.size()) {
            minHeap.push(-maxHeap.top());
            maxHeap.pop();
        }
    }
    
    double findMedian() {
        return minHeap.size() > maxHeap.size() ? minHeap.top() : (minHeap.top() - maxHeap.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */