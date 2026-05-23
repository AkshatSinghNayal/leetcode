class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if (k == 1) return r - l + 1;

        int left = ceil(pow(l, 1.0 / k) - 1e-8);
        int right = floor(pow(r, 1.0 / k) + 1e-8);

        return max(0, right - left + 1);
    }
};