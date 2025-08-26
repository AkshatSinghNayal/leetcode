class Solution {
public:
    // Helper to check if a string is a palindrome
    bool isPalindrome(const string &s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void partitionHelper(string s, vector<vector<string>>& ans, vector<string>& temp, int index) {
        if (index == s.size()) {
            ans.push_back(temp);  // reached the end, store the partition
            return;
        }

        for (int i = index; i < s.size(); i++) {
            string result = s.substr(index, i - index + 1);  // current substring
            if (isPalindrome(result)) {                      // check palindrome
                temp.push_back(result);                      // choose
                partitionHelper(s, ans, temp, i + 1);       // recurse
                temp.pop_back();                             // backtrack
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
