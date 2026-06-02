class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        long long ans = LLONG_MAX;

        auto solve = [&](vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {

            int n = C.size();
            vector<pair<int,int>> rides(n);

            for(int i = 0; i < n; i++)
                rides[i] = {C[i], D[i]};

            sort(rides.begin(), rides.end());

            vector<int> start(n);
            vector<long long> prefMinDur(n);
            vector<long long> suffMin(n + 1, LLONG_MAX);

            for(int i = 0; i < n; i++) {
                start[i] = rides[i].first;
                prefMinDur[i] = rides[i].second;
                if(i) prefMinDur[i] = min(prefMinDur[i], prefMinDur[i - 1]);
            }

            for(int i = n - 1; i >= 0; i--) {
                suffMin[i] = min(suffMin[i + 1], 1LL * rides[i].first + rides[i].second);
            }

            for(int i = 0; i < A.size(); i++) {

                long long T = 1LL * A[i] + B[i];

                int idx = upper_bound(start.begin(), start.end(), T)- start.begin();

                // case 1: start <= T
                if(idx > 0) {
                    ans = min(ans, T + prefMinDur[idx - 1]);
                }

                // case 2: start > T
                if(idx < n) {
                    ans = min(ans, suffMin[idx]);
                }
            }
        };

        solve(landStartTime, landDuration,waterStartTime, waterDuration);

        solve(waterStartTime, waterDuration,landStartTime, landDuration);

        return (int)ans;
    }
};