class Solution {
public:
    string frequencySort(string s) {
       map<char , int , greater<int>> mp ; 
        for(auto it : s){
            mp[it]++; 
        }
        vector<pair<int,char>> freq ;
        for(auto it : mp){
            freq.push_back({it.second,it.first});
        }
        sort(freq.rbegin(),freq.rend());
       
        string result="";
        for(auto it : freq){
            result+=string(it.first,it.second);
        }
        return result;
    }
};