class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(128,0);
        for(char c : t) freq[c]++;

        int left = 0, start = 0, minLen = INT_MAX, need = t.size();

        for(int right = 0; right < s.size(); right++){
            if(freq[s[right]]-- > 0) need--;

            while(need == 0){
                if(right - left + 1 < minLen)
                    minLen = right - left + 1, start = left;

                if(++freq[s[left++]] > 0) need++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};