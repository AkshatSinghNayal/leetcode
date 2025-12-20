class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<string,int>> arr ; 
        for( int i = 0 ; i< names.size() ; i++){
            arr.push_back({names[i] , heights[i]}); 
        }
        sort( arr.begin(), arr.end() , [](auto& a, auto& b){
            return a.second>b.second ; 
        }); 
        vector<string> s ; 
        for( auto& it : arr){
            s.push_back( it.first ) ; 
        }
        return s ; 
    }
};