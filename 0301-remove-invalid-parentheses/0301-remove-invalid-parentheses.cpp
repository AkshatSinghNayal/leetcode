class Solution {
public:
    unordered_set<string> st;
    int maxiLen = 0;

    void solve(string& s, string result, int i,
               int open, int close,
               int remOpen, int remClose) {

        if (i >= s.size()) {
            if (open == close) {
                st.insert(result);
            }
            return;
        }

        if (s[i] == '(') {

            // remove '('
            if (remOpen > 0) {
                solve(s, result, i + 1,
                      open, close,
                      remOpen - 1, remClose);
            }

            // keep '('
            solve(s, result + s[i], i + 1,
                  open + 1, close,
                  remOpen, remClose);
        }

        else if (s[i] == ')') {

            // remove ')'
            if (remClose > 0) {
                solve(s, result, i + 1,
                      open, close,
                      remOpen, remClose - 1);
            }

            // keep ')' only if valid
            if (close < open) {
                solve(s, result + s[i], i + 1,
                      open, close + 1,
                      remOpen, remClose);
            }
        }

        else {
            // normal character: always keep
            solve(s, result + s[i], i + 1,
                  open, close,
                  remOpen, remClose);
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        st.clear();

        int remOpen = 0;
        int remClose = 0;

        // Find minimum removals needed
        for (char c : s) {
            if (c == '(') {
                remOpen++;
            }
            else if (c == ')') {
                if (remOpen > 0)
                    remOpen--;
                else
                    remClose++;
            }
        }

        solve(s, "", 0, 0, 0, remOpen, remClose);

        vector<string> ans;

        for (auto& x : st) {
            ans.push_back(x);
        }

        return ans;
    }
};