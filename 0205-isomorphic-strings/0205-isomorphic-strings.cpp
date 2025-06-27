class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        if(m!=n) return false;
        vector<int> ans1(256,0);
        vector<int> ans2(256,0);
        for(int i = 0 ; i<n ; i++){
            if(ans1[s[i]] != ans2[t[i]]){
                return false;
            }
            ans1[s[i]]=i+11;
            ans2[t[i]]=i+11;
        }
        return true;
    }
};