class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n  = words.size();
        int maxi = 0; 
        vector<int>bits(n);
        for(int i  = 0 ; i< n ; i++ ){
            int temp = 0; 
            for(int j  = 0 ; j<words[i].size(); j++ ){
                temp |= 1<<(words[i][j]-'a'); 
            }
            bits[i] = temp; 
        }

        for(int i  = 0 ;i< n-1 ; i++ ){
            for(int j=i+1; j< n ; j++ ){
                if( !(bits[i]&bits[j])){
                    maxi = max(maxi , (int)(words[i].size()*words[j].size()) ); 
                }
            }
        }
        return maxi; 
    }
};