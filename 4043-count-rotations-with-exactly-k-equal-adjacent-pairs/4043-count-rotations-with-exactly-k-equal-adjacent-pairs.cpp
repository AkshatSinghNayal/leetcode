class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();

        int total = 0;

        // Count all n circular adjacent pairs
        for (int i = 0; i < n; i++) {
            if (s[i] == s[(i + 1) % n])
                total++;
        }

        int ans = 0;

        // Rotation by r positions excludes the pair
        // immediately before r.
        for (int r = 0; r < n; r++) {
            int excluded = (r - 1 + n) % n;

            int score = total;

            if (s[excluded] == s[(excluded + 1) % n])
                score--;

            if (score == k)
                ans++;
        }

        return ans;
    }
};
