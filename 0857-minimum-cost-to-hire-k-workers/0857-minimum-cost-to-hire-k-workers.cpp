class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        priority_queue<int> pq;
        double result = DBL_MAX;
        int n = quality.size() ;  long long total = 0;
        vector<pair<double, int>> workers;

        for (int i = 0; i < n; i++) {
            double ratio = (double)wage[i] / quality[i];
            workers.push_back({ratio, quality[i]});
        }

        sort(workers.begin(), workers.end());

        for (auto& it : workers) {
            auto [ratio, currQuality] = it;
            pq.push(currQuality);
            total += currQuality;

            if (pq.size() > k) {
                total -= pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                result = min(result, total * ratio);
            }
        }
        return result;
    }
};