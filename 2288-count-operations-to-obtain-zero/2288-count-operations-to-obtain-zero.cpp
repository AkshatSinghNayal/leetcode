class Solution {
public:
    int countOperations(int num1, int num2) {
        int count = 0; 
        while( num1>0 && num2>0 ){
            if(num1>=num2){ // if num1 is greater like 19 > 5 then pattern is 14-9-4 is 3   becaues 19 / 5  = 3 gives the count, no. of operation
                count+= num1/num2 ; 
                num1=num1%num2 ; 
            }
            else{
                count+=num2/num1 ; 
                num2 = num2%num1 ; 
            }
        }
        return count ; 
    }
};