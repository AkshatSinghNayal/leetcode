class Solution {
public:
    int countDigits(int num) {
        int count  = 0 ; 
        int experiment = num; 
        while(experiment>0){
            int digit = experiment%10 ; 
            if(( num % digit) == 0 )count++; 
            experiment/=10; 
        }
        return count ; 
    }
};