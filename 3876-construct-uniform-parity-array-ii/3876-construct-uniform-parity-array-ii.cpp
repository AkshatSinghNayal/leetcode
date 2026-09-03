class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n = nums.size();
        int odd  = 0 , even = 0 , mini = INT_MAX  ; 
        for(auto& it : nums ){
            if(it&1){
                mini = min( mini , it ); 
                odd++;
            }
            else even++;
        }

        if( odd == n or even == n  ) return true;

        int temp = n; 
        for(auto& it : nums ){
            if( it& 1 ){
                temp--; 
            }
            else{
                if( it - mini >= 1 ){
                    temp--;
                }
            }
        }
        return temp == 0 ;
    }
};

