class MedianFinder {
public:

    class comp{
        public: 
        bool operator()( const double& a , const double& b ){
            return a < b; 
        }
    }; 
    int size ; 
    priority_queue<int,vector<int> , comp > left ;
    priority_queue<int , vector<int> ,greater<int>> right ;

    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        
        double temp = (double)num;
        right.push(temp);
        if( left.size() < right.size() ){
            left.push(right.top());
            right.pop();
        }

        while( !left.empty() and !right.empty() and left.top()> right.top() ){
           
                auto ele = left.top();
                auto ele2 = right.top();
                right.pop(); left.pop();
                right.push(ele);
                left.push(ele2 ); 
           
        }
        size++; 
    }
    
    double findMedian() {
        if( size%2 != 0  ){
            return left.top();
        }
        return (double)(left.top()+right.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */