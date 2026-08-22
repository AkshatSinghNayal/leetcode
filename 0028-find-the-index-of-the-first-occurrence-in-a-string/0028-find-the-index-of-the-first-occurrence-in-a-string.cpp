class Solution {
public:
    int strStr(string s, string f) {
        return ( s.find(f) != string::npos ) ? s.find(f) : -1; 
    }
};