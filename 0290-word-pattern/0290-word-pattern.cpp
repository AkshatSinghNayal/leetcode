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
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        int left = 0;

        for (int i = 0; i < pattern.size(); i++) {
            string temp = helper(s, left);

            if( temp.empty()) return false; 
            char c  = pattern[i]; 
            if( mp1.count(c) && mp1[c]!=temp) return false;
            if( mp2.count(temp) && mp2[temp]!=c) return false; 


            mp1[c] = temp ;
            mp2[temp] = c ; 




        }  
        if( left < s.size() ) return false;
        return true;
    }
};
