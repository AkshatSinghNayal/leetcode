class Solution {
public:
    string frequencySort(string s) {
        string result = "" ;
       unordered_map< char,int> mp ;
       for ( auto it : s ){
        mp[it]++; 
       }
       vector<pair<int,char>> ans ; 
       
       for( auto it : mp ){
            if( it.second >0 ){
                ans.push_back({it.second ,it.first}); 
            }
       }
       sort(ans.begin(),ans.end() , greater<pair<int,char>>()); 

       for( auto it : ans){
            if(it.second >= 1 ){
                
                result+=string(it.first , it.second); 
            }
       }
       return result ; 
    }
};