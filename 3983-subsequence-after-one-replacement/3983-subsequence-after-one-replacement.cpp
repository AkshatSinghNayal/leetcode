class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        int i0 = 0; 
        int i1 = 0; 

        for (int j = 0; j < m; j++) {
            int next_i0 = i0;
            int next_i1 = i1;

            if (i1 < n && s[i1] == t[j]) {
                next_i1 = max(next_i1, i1 + 1);
            }

            if (i0 < n) {
                next_i1 = max(next_i1, i0 + 1);
            }

            if (i0 < n && s[i0] == t[j]) {
                next_i0 = max(next_i0, i0 + 1);
            }

            i0 = next_i0;
            i1 = next_i1;

            if (i0 == n || i1 == n) return true;
        }

        return i0 == n || i1 == n;
    }
};