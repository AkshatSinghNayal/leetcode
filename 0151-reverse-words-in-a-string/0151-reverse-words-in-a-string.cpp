class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;

       for(int i = 0; i < s.size(); i++){
            if (word.empty() && s[i] != ' ') {
                word += s[i];
            } else if (word.empty() && s[i] == ' ') {
                continue;
            } else if (!word.empty() && s[i] == ' ') {
                words.push_back(word);
                word.erase();
            }
            else{
                word+=s[i];
            }
        }
            if (!word.empty()) {
                words.push_back(word);
            }
            reverse(words.begin(),words.end());
        string result;
        for(int i = 0; i < words.size(); i++) {
            result += words[i];
            if (i < words.size() - 1) {
                result += ' ';
            }
        }
        return result;
    }
};