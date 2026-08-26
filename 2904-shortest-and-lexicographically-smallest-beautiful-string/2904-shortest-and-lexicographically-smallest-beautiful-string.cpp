class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0 , right = 0 ; 
        pair<string,int>ans; 
        ans = { "" , INT_MAX } ; 

        int n = s.size(); 
        
        int countk= 0; 
        while( right < n ){
            auto ele = s[right]; 
            if( ele == '1') countk++; 

            while( left <= right and countk == k ){
                int len = right-left+1; 
                string temp = s.substr( left , len);

                if( ans.second == len ){
                    ans.first = min(ans.first , temp ); 
                }
                else if( ans.second > len ){
                    ans = { temp , len }; 
                }

                if( s[left] == '1') countk--; 
                left++; 
            }
            right++; 
        }
        return ans.first;
    }
};