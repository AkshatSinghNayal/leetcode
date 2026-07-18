class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n  = vals.size();
        unordered_map<char,int>mp ; 
        for(int i = 0; i<n ;i++ ){
            mp[chars[i]] = vals[i]; 
        }
        // for(auto& it : mp ) cout<<it.second << " " ; 
        
        int maxi = -1e9 , global = -1e9 ; 

        for(int j = 0 ; j<s.size(); j++ ){
            if(mp.count(s[j])){
                maxi = max({maxi+mp[s[j]] , mp[s[j]] }); 
            }
            else{
                maxi = max({maxi+(s[j]-'a'+1) , (s[j]-'a'+1)}); 
            }
            global = max({global,maxi}); 
        }
        return max(0,global); 

    }
};