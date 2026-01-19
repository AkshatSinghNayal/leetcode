class Solution {
public:
    int vowelConsonantScore(string s) {
        int vowel = 0, consonent = 0;

        unordered_set<char> st = {'1', '2', '3', '4', '5',
                                  '6', '7', '8', '9', '0'};

        for (auto& it : s) {
            if (it == 'a' or it == 'e' or it == 'i' or it == 'o' or it == 'u') {
                vowel++;
            } else {
                if (it == ' ' or st.count(it)) {

                } else {
                    consonent++;
                }
            }
        }
        return (consonent > 0) ? vowel / consonent : 0;
    }
};