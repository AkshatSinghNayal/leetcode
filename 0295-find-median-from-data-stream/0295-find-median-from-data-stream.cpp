class MedianFinder {
public:

    priority_queue<int> left ; // max heap
    priority_queue<int , vector<int> , greater<int>> right; // min heap
    int size; 
    MedianFinder() {    
        size =0; 
    }
    
    void addNum(int num) {
        size++; 
        double temp = (double)num ; 
        right.push(temp);

        if(right.size() > left.size() ){
            left.push(right.top()); right.pop(); 
        }

        if(left.top() > right.top()){
            double hi = left.top(); left.pop(); 
            left.push(right.top()); right.pop(); 
            right.push(hi); 
        }

    }
    
    double findMedian() {
        if( size&1 ){
            return left.top(); 
        }
        return ( left.top() + right.top() )/2.0; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */