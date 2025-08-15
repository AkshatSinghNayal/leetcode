class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq (3,0);
        int count = 0 ; 
        int n = s.size() ; 
        int left = 0 ; 
        for( int right = 0 ; right<s.size(); right++){
            freq[s[right]-'a']++;
            while(freq[0]>0 && freq[1]>0 && freq[2]>0){
                count+=n-right;
                freq[s[left]-'a']--;
                left++;
            }
        }
        return count;
    }
};