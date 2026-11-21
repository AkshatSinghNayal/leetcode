class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>mp;
        int n  = s.size();
        for(int i  =0 ;i<n; i++ ){
            char ch = s[i]; 
            if(!mp.count(ch)) mp[ch] = { i , i}; 
            else{
                mp[ch].second = i;
            }
        }

        vector<int>ans;

        int left =0 , right = 0;
        while(right < n ){
            int start = left;
            int end = mp[s[right]].second; 
            while(right <n  ){
                if(mp[s[right]].second <= end ){
                    right++; 
                    continue;
                }
                else if( end >= right ){
                    end = max(end , mp[s[right]].second ); 
                    right++; 
                    continue;
                }
                else break;
                
            }
            left = right;
            ans.push_back(right-start);
        }
        return ans;
    }
};