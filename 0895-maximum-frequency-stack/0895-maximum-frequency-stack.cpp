class FreqStack {
public:
    struct Node{
        int freq, timeArrived, value;
    }; 

    class comp{
        public: 
        bool operator()(const Node& a , const Node& b ){
            if(a.freq == b.freq){
                return a.timeArrived < b.timeArrived;
            }
            return a.freq<b.freq;
        }
    };

    unordered_map<int,int> mp ; 
    priority_queue<Node, vector<Node> , comp>pq;
    int globalTime = 0; 


    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++; 
        pq.push({ mp[val] , globalTime++ ,val }); 
    }
    
    int pop() {
        Node top = pq.top(); 
        mp[top.value]--; 
        pq.pop();
        return top.value;
    }   
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */