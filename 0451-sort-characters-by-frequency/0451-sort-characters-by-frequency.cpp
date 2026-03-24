class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        vector<pair<int,char>>ans;
        for(auto& it : s) mp[it]++;
        for(auto& it : mp ){
            ans.push_back({it.second , it.first}); 
        }
        sort(ans.rbegin(),ans.rend());
        string result = "";
        for(auto& it : ans ){
            result+=string(it.first,it.second);
        }
        return result;
    }
};