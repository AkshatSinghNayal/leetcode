class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        unordered_set<string> st;

        for (int i = 0; i < words.size() - 1; i++) {

            if (words[i].size() < k || words[i+1].size() < k)
                continue;

            string prefix1 = words[i].substr(0, k);
            string prefix2 = words[i+1].substr(0, k);

            if (prefix1 == prefix2) {
                st.insert(prefix1);
            }
        }

        return st.size();
    }
};
