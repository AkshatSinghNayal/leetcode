class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(); 
        vector<bool> possible(n-1, false); 
        int count = 0;
        int col = strs[0].size(); 

        for(int i = 0 ; i< col ; i++){
            bool del = false; 
            for(int j = 1; j<n ; j++){
                if( !possible[j-1] and j-1>= 0 and  strs[j][i]<strs[j-1][i] ){
                    count++;
                    del = true; 
                    break; 
                }
            }
            if( del ){
                continue; 
            }
            else {
                for(int k =0 ; k< possible.size() ; k++){
                    possible[k] = possible[k] | (k+1 < n and strs[k][i] < strs[k+1][i] ); 
                
                }

            }
            
        }
        return count; 

    }
};