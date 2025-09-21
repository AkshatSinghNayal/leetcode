class Solution {
public:
    
    string helper(string& s, int& left) {
        string word = "";
        int n = s.size();
        while (left < n && s[left] != ' ') {
            word.push_back(s[left]);
            left++;
        }
        if (left < n) left++; // skip space
        return word;
    }

    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> c2s;
        unordered_map<string, char> s2c;
        int left = 0;

        for (int i = 0; i < pattern.size(); i++) {
            string word = helper(s, left);
            if (word.empty()) return false; // fewer words than pattern

            char c = pattern[i];

            // Check existing mapping
            if (c2s.count(c) && c2s[c] != word) return false;
            if (s2c.count(word) && s2c[word] != c) return false;

            // Set mapping
            c2s[c] = word;
            s2c[word] = c;
        }

        // Extra words in s?
        if (left < s.size()) return false;

        return true;
    }
};
