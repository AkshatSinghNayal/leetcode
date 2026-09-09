////// I bow to Lord Satyanarayan and Lord Hanuman ///////////
#include <bits/stdc++.h>
using namespace std; 

class Solution {
public:
    long long countCommas(long long n) {
       long long ans = 0;

        if (n >= 1000)
            ans += n - 999;          // numbers with at least 1 comma

        if (n >= 1000000)
            ans += n - 999999;       // numbers with at least 2 commas

        if (n >= 1000000000)
            ans += n - 999999999;    // numbers with at least 3 commas

        if( n>= 1000000000000)
            ans+= n-999999999999;  // numbers with at least 4 commas
                
        if(n>=1000000000000000)
            ans+=n-999999999999999;  // numbers with at least 5 commas
        return ans;
    }
};