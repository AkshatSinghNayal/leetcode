////// I bow to Lord Satyanarayan and Lord Hanuman ///////////
#include<bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int boatCount =0 , n =  people.size(); 
        sort( people.begin() , people.end()); 
        int left = 0 , right = n-1 ;

        while( left <= right ){

            int sum = people[left]+people[right]; 
            if( sum<= limit ){
                boatCount++;
                left++; right--;
            }
            else{
                right--; 
                boatCount++;
            }
        
        }
        return boatCount;
    }
};