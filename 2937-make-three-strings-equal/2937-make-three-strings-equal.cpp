class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0;
        int n = s1.size() , m=s2.size() , o = s3.size(); 
        while( i < n and i < m and i < o ){
            
            if( s1[i] == s2[i] and s2[i] == s3[i] ){
                i++; 
            }
            else{
                break; 
            }
           
        }
            return ( i == 0  ) ? -1 : (n+m+o -3*i);
    }
};