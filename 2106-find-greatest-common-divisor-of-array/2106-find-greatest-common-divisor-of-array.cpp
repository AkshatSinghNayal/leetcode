class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end()); 
        int size = nums.size()-1 ; 
        int a = nums[0]; 
        int b = nums[size]; 
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