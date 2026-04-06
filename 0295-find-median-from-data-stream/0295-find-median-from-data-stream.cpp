class MedianFinder {
public:

    priority_queue<double,vector<double>,greater<double>> right; 
    priority_queue<double>left;
    int size ; 

    MedianFinder() {
        size = 0;  
    }
    
    void addNum(int num) {
        right.push((double)num);
        if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }

        if(!left.empty() and !right.empty() and left.top()>right.top()){
            auto leftTop = left.top();
            auto rightTop = right.top();
            left.pop(); right.pop();
            left.push(rightTop);
            right.push(leftTop);
        }



        size++; 
    }
    
    double findMedian() {
        if( size&1 ){
            return left.top();
        }
        return (left.top()+right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */