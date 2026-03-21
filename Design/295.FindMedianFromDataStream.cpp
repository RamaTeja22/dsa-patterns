class MedianFinder {
public:
    priority_queue<int>small;
    priority_queue<int,vector<int>,greater<int>>large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(small.empty() && large.empty()){
            small.push(num);
            return;
        }
        small.push(num);
        if(small.size()-large.size()>1){
            int al=small.top();
            small.pop();
            large.push(al);
        }
        if(small.top()>large.top()){
            int al=small.top();
            small.pop();
            large.push(al);
            if(large.size()-small.size()>1){
                int cc = large.top();
                large.pop();
                small.push(cc);
            }
        }
    }
    
    double findMedian() {
        int smallSize=small.size();
        int largeSize=large.size();
        int totalSize = smallSize+largeSize;
        if(totalSize%2==1)
        return (double)(small.size()>large.size()?small.top():large.top());
        return (double)(small.top()+large.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */