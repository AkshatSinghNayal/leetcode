class Solution {
public:

    vector<string> solve(string &s, unordered_set<string> &st, unordered_map<string, vector<string>> &mp, int i) {

    if (s.empty()) return {""};

    if (mp.count(s)) return mp[s];

    for (int l = 1; l <= s.size(); l++) {

        string currentWord = s.substr(0, l);

        if (st.count(currentWord)) {

            string subString = s.substr(l);

            auto result = solve(subString, st, mp, l);

            for (auto &x : result) {
                if (x.empty())
                    mp[s].push_back(currentWord);
                else
                    mp[s].push_back(currentWord + " " + x);
            }
        }
    }

    return mp[s];
}

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st; 
        for(auto& it : wordDict){
            st.insert(it); 
        }
        unordered_map<string,vector<string>>mp; 
        return solve(s , st , mp , 1 ); 
    }
};