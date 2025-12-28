class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0]; int b = nums[1] ; int c = nums[2]; 
        
        return (a+b>c and a+c>b and b+c > a) ? ( a== b and b== c) ? "equilateral" : ( a==b or b== c or a== c) ? "isosceles" : "scalene" : "none";
       
    }
};