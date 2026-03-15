////// I bow to Lord Satyanarayan and Lord Hanuman ///////////
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int countCommas(int n) {
        return ( n<= 999 ) ? 0 : n-1000+1; 
    }
};