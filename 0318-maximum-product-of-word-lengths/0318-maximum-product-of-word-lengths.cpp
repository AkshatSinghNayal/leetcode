////// I bow to Lord Satyanarayan and Lord Hanuman ///////////
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n =  words.size();
        vector<int>bits(n);
        for(int i = 0 ;i< n; i++ ){
            int num = 0; 
            for(int j = 0  ; j<words[i].size() ; j++ ){
                num |= 1<<(words[i][j]-'a'); 
            }
            bits[i] = num; 
        }
        int maxi = 0; 
        for(int i = 0 ;i< n-1 ;i++ ){
            for( int j =i+1; j<n ;j++ ){
                if( (bits[i] & bits[j]) == 0  ){
                    maxi = max( maxi , (int)words[i].size()*(int)words[j].size());
                }
            }
        }
        return maxi ; 
    }
};


// video link ->>> https://www.youtube.com/watch?v=3XHAikDnB2w