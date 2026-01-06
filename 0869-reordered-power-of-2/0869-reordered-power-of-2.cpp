class Solution {
public:
    bool reorderedPowerOf2(int a) {
        string s = to_string(a);
        sort(s.begin(), s.end()); // start with smallest permutation

        // check the first permutation manually
        if (s[0] != '0') {
            int n = stoi(s);
            if ((n & (n - 1)) == 0) return true;
        }

        // now iterate over remaining permutations
        while (next_permutation(s.begin(), s.end())) {
            if (s[0] != '0') {
                int n = stoi(s);
                if ((n & (n - 1)) == 0) return true;
            }
        }

        return false;
    }
};
