class Solution {
public:
    bool CheckPalindrome(const string& s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    void partioning(string& s, vector<vector<string>>& ans, vector<string>& temp,
                    int index) {

        if (index == s.size()) {
            ans.push_back(temp);
        }

        string curr = "";
        for (int i = index; i < s.size(); i++) {
            curr += s[i];
            if (CheckPalindrome(s, index, i)) {
                temp.push_back(curr);
                partioning(s, ans, temp, i + 1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        partioning(s, ans, temp, 0);

        return ans;
    }
};