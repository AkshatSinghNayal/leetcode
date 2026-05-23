class Solution {
public:

    long long power(long long a, int k, long long limit) {
        long long res = 1;

        while (k--) {
            if ( a!=0 and res > limit / a)
                return limit + 1;

            res *= a;
        }

        return res;
    }

    int countKthRoots(int l, int r, int k) {

        if (k == 1) return r - l + 1;

        int low = -1, high = -1;

        int lo = 0, hi = r;

        // first x such that x^k >= l
        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            long long val = power(mid, k, r);

            if (val >= l) {
                low = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }

        lo = 0, hi = r;

        // last x such that x^k <= r
        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            long long val = power(mid, k, r);

            if (val <= r) {
                high = mid;
                lo = mid + 1;
            }
            else {
                hi = mid - 1;
            }
        }

        if (low == -1 || high == -1) return 0;

        return max(0, high - low + 1);
    }
};