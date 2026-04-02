class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        unordered_map<int,string>mp;
        vector<int>ans = score;
        int n  = score.size();
        sort(ans.begin(),ans.end(),greater<>()); 

        for(int i  = 0; i<score.size() ;i++ ){
            mp[ans[i]] = to_string(i+1); 
        }
        mp[ans[0]] = "Gold Medal";
        if(n>=2) mp[ans[1]] = "Silver Medal"; 
        if(n>=3) mp[ans[2]] =  "Bronze Medal";
        vector<string>result(score.size());

        for(int i= 0 ;i<score.size() ;i++ ){
            int temp = score[i];
            result[i]=mp[temp]; 
        }

        return result;
        
    }
};