class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi  = INT_MIN ;
        for( int i = 0 ; i<sentences.size() ;i++){
            string s = sentences[i] ;
        int count = 1 ; 
            int j = 0 ; 
            while(j<s.size()){

                if(s[j] == ' '){
                    count++; 
                }
                maxi = max( count , maxi );
                j++;
            }
        }
        return maxi ; 
    }
};