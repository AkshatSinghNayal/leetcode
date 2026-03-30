class Solution {
public:
    bool canTransform(string s, string r) {
        int n = s.size();
        int left = 0, right = 0;

        while (left < n || right < n) {
            while (left < n && s[left] == 'X') left++;
            while (right < n && r[right] == 'X') right++;

            // if (left == n || right == n)
            //     return left == n && right == n;

            if (s[left] != r[right]) return false;

            if (s[left] == 'R' && left > right) return false;
            if (s[left] == 'L' && left < right) return false;

            left++;
            right++;
        }

        return true;
    }
};