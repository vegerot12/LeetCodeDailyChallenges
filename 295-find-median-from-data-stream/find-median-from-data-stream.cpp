class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int> , greater<>> minHeap;
    int cnt=0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.size() == minHeap.size()){
            minHeap.push(num);
            int smallest = minHeap.top();
            minHeap.pop();
            maxHeap.push(smallest);
        }
        else{
            maxHeap.push(num);
            int largest = maxHeap.top();
            maxHeap.pop();
            minHeap.push(largest);
        }
        cnt++;
    }
    
    double findMedian() {
cout<<cnt;

        if(cnt%2==0){
            return double(maxHeap.top()+minHeap.top())/2.0;
        }
         return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */