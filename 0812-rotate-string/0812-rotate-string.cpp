class Solution {
public:
    void reverse(string& s, int left, int right) {
        while (left < right) {
            swap(s[left++], s[right--]);
        }
    }

    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (goal[i] == s[0]) {
                string temp = goal;
                reverse(temp, i, n - 1);
                reverse(temp, 0, i - 1);
                reverse(temp, 0, n - 1);
                if (temp == s) return true;
            }
        }

        return false;
    }
};
