class Solution {
public:
    void reverseRange(string& s, int i, int j) {
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }

    string reverseWords(string s) {

        string result = "";
        reverse(s.begin(), s.end());
        int i = 0;
        int j = s.size() - 1;

        while (s[i] == ' ')
            i++;

        while (s[j] == ' ')
            j--;
        int k = i;

        while (i <= j) {
            while (k <= j && s[k] != ' ') {
                k++;
            }
            reverseRange(s, i, k - 1);

            if (!result.empty()) result += ' ';
            result += s.substr(i, k - i);

           while(k<=j && s[k] == ' ')k++; 
           i= k;
        }

        return result;
    }
};