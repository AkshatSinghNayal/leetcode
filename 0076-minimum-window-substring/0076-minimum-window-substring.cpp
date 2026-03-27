class Solution {
public:
    string minWindow(string s, string t) {
        int start = 0 , maxi = INT_MAX , left= 0 , right = 0 , n = s.size() ; 
        unordered_map<char , int > needed , current ; 
        for(auto& it : t ) needed[it]++; 
        int count = needed.size();
        while( right < n and left < n ){
            char ch = s[right]; 
            current[ch]++; 
            if( needed.count(ch )) {

                if( current[ch] == needed[ch]){
                    count--;
                }
            }
            
            while( left < n and count == 0  ){

                if(right - left + 1 < maxi){
                    start = left;
                    maxi = right - left + 1;
                }
                
                current[s[left]]--; 
                if( needed.count(s[left])){
                    if( current[s[left]] < needed[s[left]] ){
                        count++; 
                    }
                }
                left++; 
            }
            right++; 
        }
        return ( maxi == INT_MAX) ? "" : s.substr( start , maxi ); 
    }
};