class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& num1, vector<int>& num2) {
        int const MOD = 1e9 + 7 ; 
        int total = 0; 
        int maxiDiff = 0 ; 
        int n  = num1.size();

        vector<int>sorted(num1.begin() , num1.end());
        sort(sorted.begin(), sorted.end()); 

        for(int i = 0 ;i < n ;i++ ){
            int a = num1[i] , b = num2[i]; 
            int diff = abs(a-b);
            total = (total+diff)%MOD;

            auto it = lower_bound(sorted.begin() , sorted.end() , b );
            // cout << *it << " " ; 
            if( it!= sorted.end()){
                int value = *it ;
                maxiDiff=max(maxiDiff , diff- abs(value-b)); 
            }

            if( it!=sorted.begin()){
                it--;
                int value = *it;
                maxiDiff=max(maxiDiff , diff- abs(value-b) );
            }
            // cout << *it << " " ; 


            // cout<< maxiDiff << "  "; 

        }
        
        return ( total-maxiDiff +MOD )%MOD;


    }
};