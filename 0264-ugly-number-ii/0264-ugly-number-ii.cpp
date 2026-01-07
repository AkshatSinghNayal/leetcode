class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> minHeap;
        unordered_set<long> seen;

        minHeap.push(1);
        seen.insert(1);

        long number = 1;

        for (int i = 0; i < n; i++) {
            number = minHeap.top();
            minHeap.pop();

            for (int p : {2, 3, 5}) {
                long next = number * p;
                if (!seen.count(next)) {
                    minHeap.push(next);
                    seen.insert(next);
                }
            }
        }

        return (int)number;
    }
};
