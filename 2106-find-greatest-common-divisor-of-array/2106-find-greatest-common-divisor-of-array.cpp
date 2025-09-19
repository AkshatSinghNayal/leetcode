class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = *min_element( nums.begin(),nums.end());
        int b = *max_element( nums.begin(),nums.end());
        int gcd = 1; 
        while(a>0 && b > 0){
            if(a > b){
                a = a % b; 
            }
            else{
                b=b%a ; 
            }
        }
        if( a == 0 ) return b;  
        return a; 
    }
};