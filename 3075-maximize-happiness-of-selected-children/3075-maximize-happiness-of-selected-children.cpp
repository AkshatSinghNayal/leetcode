class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum = 0 ; 
        int index =  0; 
        int n = happiness.size(); 
        sort(happiness.begin(),happiness.end()) ; 

        for( int i = n-1 ; (i>= 0 and k>0 ) ; i--){
            long long value = happiness[i]-index ; 
            if( value <0 ) break;
            sum+=value; 
            k--; 
            index++; 
        }
        return sum ; 
    }
};