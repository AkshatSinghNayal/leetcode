class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() ;
        int count = 0 ; 
        int m = strs[0].size(); 
        for( int i  = 0  ; i< m ; i++){
            string s= "" ; 
            bool fine = true; 
            for( int j = 0  ; j< n ; j++){
                char c = strs[j][i]; 
                if(!s.empty()){
                    if(s.back() > c ) {
                        fine = false; 
                        break; 
                    }
                    else{
                        s.push_back(c); 
                    }
                }
                else if( s.empty()){
                    s.push_back(c); 
                }

            }
                if( !fine ) count++; 

        }
        return count; 
    }
};