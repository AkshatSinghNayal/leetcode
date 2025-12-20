class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long ans = 0;
        priority_queue<int> pq;

        int i = 0;
        int n = s.size();
        while (i < n) {

            pq.push(nums[i]);
            if (s[i] == '1') {
                ans += pq.top();
                pq.pop();
            }

            i++;
        }

        return ans;
    }
};