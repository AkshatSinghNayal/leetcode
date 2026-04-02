class Solution {
public:
    int halveArray(vector<int>& nums) {
        double total = accumulate(nums.begin(), nums.end(), 0.0);
        double target = total / 2;

        priority_queue<double> pq(nums.begin(), nums.end());

        int operations = 0;
        double reduced = 0;

        while (reduced < target) {
            
            auto half = pq.top()/2;
            reduced+=half;
            pq.pop(); 
            pq.push(half); 

            operations++; 
        }

        return operations;
    }
};