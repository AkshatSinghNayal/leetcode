class Solution {
public:
    // Check if s[start..end] is a palindrome
    bool isPalindrome(const string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }

    void partitionHelper(const string &s, vector<vector<string>> &ans, vector<string> &temp, int start) {
        if (start == s.size()) {
            ans.push_back(temp);
            return;
        }

        string curr = "";
        for (int i = start; i < s.size(); i++) {
            curr += s[i];  // build substring manually
            if (isPalindrome(s, start, i)) { // check palindrome on indices
                temp.push_back(curr);
                partitionHelper(s, ans, temp, i + 1);  // recurse
                temp.pop_back();  // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partitionHelper(s, ans, temp, 0);
        return ans;
    }
};
