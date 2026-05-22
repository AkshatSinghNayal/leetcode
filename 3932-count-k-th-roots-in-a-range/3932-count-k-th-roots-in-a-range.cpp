class Solution {
public:
    long long power(long long a, int k, long long limit) {
    if (a == 0) return 0;

    long long res = 1;

    while (k--) {
        if (res > limit / a)
            return limit + 1;

        res *= a;
    }

    return res;
}
    int countKthRoots(int l, int r, int k) {
        if (k == 1) return r - l + 1;

        int left = 0, right = 1e6;

        // first x such that x^k >= l
        int low = 1e6, high = -1;

        int lo = 0, hi = 1e6;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (power(mid, k, r) >= l) {
                low = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        // last x such that x^k <= r
        lo = 0, hi = 1e6;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (power(mid, k, r) <= r) {
                high = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return max(0, high - low + 1);
    }
};