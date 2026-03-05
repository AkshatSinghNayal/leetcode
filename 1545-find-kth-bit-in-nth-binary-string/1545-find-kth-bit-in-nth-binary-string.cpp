#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    char findKthBit(int n, int k) {
        if( n ==  1 ) return '0'; 
        string s="0" ; 
        for(int i = 1  ; i<n; i++   ){
            s+='1'; 
            for( int j = s.size()-2 ; j>=0 ;j-- ){
                s+= ( s[j] == '0') ? '1' : '0';
            }
        } 
        cout << s ; 
        return s[k-1]; 
    }
};