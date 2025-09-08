class Solution {
public:
    int lengthOfLastWord(string s) {
        while (!s.empty() && s.back() == ' ') {
            s.pop_back();
        }
        int n = s.size() -1 ;
        int count = 0; 
        while(n>=0 && s[n]!=' '){
            count++;
            n--;
        }
        return count ; 
    }
};