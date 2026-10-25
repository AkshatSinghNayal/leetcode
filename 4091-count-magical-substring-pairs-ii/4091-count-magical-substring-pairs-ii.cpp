class Solution {
public:
    long long countMagicalPairs(string s) {
        long long count = 0; 
        int n = s.size(); 
        
        // atMost1[r][ch] = substrings ending at r with <= ch distinct chars
        // atMost2[l][ch] = substrings starting at l with <= ch distinct chars
        vector<array<int, 27>> atMost1(n, {0}), atMost2(n, {0});

        // 1. Precompute Left side (i..j-1) for ch = 1..26 using Sliding Window
        for(int ch = 1; ch <= 26; ch++){
            int freq[26] = {}, distinct = 0, i = 0;
            for(int j = 0; j < n; j++){
                if(freq[s[j] - 'a']++ == 0) distinct++;
                while(distinct > ch){
                    if(--freq[s[i] - 'a'] == 0) distinct--;
                    i++;
                }
                atMost1[j][ch] = j - i + 1;
            }
        }

        // 2. Precompute Right side (j..k) for ch = 1..26 using Sliding Window
        for(int ch = 1; ch <= 26; ch++){
            int freq[26] = {}, distinct = 0, k = n - 1;
            for(int j = n - 1; j >= 0; j--){
                if(freq[s[j] - 'a']++ == 0) distinct++;
                while(distinct > ch){
                    if(--freq[s[k] - 'a'] == 0) distinct--;
                    k--;
                }
                atMost2[j][ch] = k - j + 1;
            }
        }

        // 3. Your exact split loop, using exact(ch) = atMost(ch) - atMost(ch - 1)
        for(int j = 1; j <= n - 1; j++){
            for(int ch = 1; ch <= 26; ch++){
                long long hash1_ch = atMost1[j - 1][ch] - atMost1[j - 1][ch - 1];
                long long hash2_ch = atMost2[j][ch] - atMost2[j][ch - 1];
                count += hash1_ch * hash2_ch;
            }
        }
        return count;
    }
};