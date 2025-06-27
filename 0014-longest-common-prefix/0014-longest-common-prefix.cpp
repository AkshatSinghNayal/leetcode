class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s[0].size();
        int m = s.size();
        int tempcount = 0 ; 
        string result="" ;
        for(int i= 0; i<n ; i++){
            char sample=s[0][i];
            for(int j= 0; j<m; j++){
                if( s[j][i] == sample){
                   
                   tempcount++;
                }
                else{
                    return result ;
                }
                if(tempcount==m){
                    result+=sample;
                    tempcount=0;
                }
                
            }
        }
        return result ;
        
    }
};