class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;

        bool neg = num < 0;
        string s = to_string(num);

        if (neg) {
            sort(s.begin() + 1, s.end(), greater<char>());
        } else {
            sort(s.begin(), s.end());

            if (s[0] == '0') {
                int i = 0;
                while (i < s.size() && s[i] == '0') i++;

                swap(s[0], s[i]);
            }
        }

        return stoll(s);
    }
};