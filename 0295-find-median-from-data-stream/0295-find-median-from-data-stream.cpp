class MedianFinder {
public:
    priority_queue<double>small; // max heap
    priority_queue<double>large; //min heap
    //head sizes should be equal not more than 1 diff!
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //always add in the small heap then adjust sizes
        small.push(num);
        if(small.size()!=0 && large.size()!=0 && small.top()>large.top()){
            //all the elements in the left are not strictly smaller hm
            double val=small.top();
            small.pop();
            large.push(-val);
        }
        
        //if sizes unequal
        
        if(small.size()>large.size()+1){
            double val=small.top();
            small.pop();
            large.push(-val);
        }
        if(large.size()>small.size()+1){
            double val=large.top();
            large.pop();
            small.push(-val);
        }
    }
    
    double findMedian() {
        if(small.size()>large.size()){
            return small.top();
        }
        if(large.size()>small.size()){
            return -large.top();
        }
        double x=-large.top();
        return (small.top()+x)/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */