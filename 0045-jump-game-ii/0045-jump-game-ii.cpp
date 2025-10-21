class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(); 
        if(n<=1 ) return 0; 
        int far = 0 , i = 0 , index = 0 , jump = 0 ; 
        while( i< n){

            far = max( far , i+nums[i]); 
            if(i == index ){
                jump++; 
                index = far ; 

                if( index >= n-1 ) break ;

            }


            i++;
        }
        return jump ; 
    }
};