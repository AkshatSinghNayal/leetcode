class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long d1 = d[0], d2 = d[1];
        long long r1 = r[0], r2 = r[1];

        long long g = gcd(r1, r2);
        long long lcm = (r1 / g) * r2;

        auto possible = [&](long long t) {
            long long avail1 = t - t / r1;
            long long avail2 = t - t / r2;

            // Hours where at least one drone can make a delivery
            long long availTotal = t - t / lcm;

            return avail1 >= d1 &&
                   avail2 >= d2 &&
                   availTotal >= d1 + d2;
        };

        long long lo = 0, hi = 1;

        // Find a valid upper bound
        while (!possible(hi)) {
            hi *= 2;
        }

        // Find minimum feasible time
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;

            if (possible(mid))
                hi = mid-1;
            else
                lo = mid + 1;
        }

        return lo;
    }
};