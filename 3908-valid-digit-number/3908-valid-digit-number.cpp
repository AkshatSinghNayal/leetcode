class Solution {
public:
    bool validDigit(int n, int x) {
        string s = to_string(n); 
        return ( s[0] != x+'0' and s.find(x+'0') != string::npos ) ? true : false;
    }
};