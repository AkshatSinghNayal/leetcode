class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size() ; 
        int col = strs[0].size(); 
        int count= 0; 

        for(int i= 0 ; i<col ; i++){
            for(int j=1 ; j<n ; j++){
                if( j-1>=0 and strs[j][i]<strs[j-1][i] ){
                    count++; 
                    break; 
                }
            }
        }
        return count ;
    }
};