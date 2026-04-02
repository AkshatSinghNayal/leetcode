class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum = 0;

        for (int x : nums) {
            pq.push(x);
            sum += x;
        }

        double target = sum / 2;
        double reduced = 0;
        int operations = 0;

        while (reduced < target) {
            double x = pq.top(); pq.pop();
            double half = x / 2;
            reduced += half;
            pq.push(half);
            operations++;
        }

        return operations;
    }
};