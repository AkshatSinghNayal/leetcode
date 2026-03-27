class FreqStack {
public:
    unordered_map<int,int> freq;
    int timer = 0;

    struct Node {
        int f, t, val;
    };

    struct comp {
        bool operator()(const Node& a, const Node& b) {
            if (a.f == b.f)
                return a.t < b.t;   // more recent first
            return a.f < b.f;       // higher freq first
        }
    };

    priority_queue<Node, vector<Node>, comp> pq;

    FreqStack() {}

    void push(int val) {
        freq[val]++;
        pq.push({freq[val], timer++, val});
    }

    int pop() {
        Node top = pq.top();
        pq.pop();

        freq[top.val]--;   // decrease frequency
        return top.val;
    }
};