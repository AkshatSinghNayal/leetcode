class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int correct =0 , notCorrect = 0;

        int operations = 0;
        vector<int>temp = nums; 
        sort(temp.begin(), temp.end()); 

        for(int i = 0;i<n ;i++ ){
            for(int j =0; j< n-i-1 ; j++ ){

                if(nums[j] > nums[j+1]){
                     if( locked[j] ==1 and locked[j+1]and k >=2){
                        operations+=2;
                        locked[j] = 0; 
                        locked[j+1] =0 ;
                        k-=2; 
                    }
                    else if( locked[j] == 1 and k >0){
                        locked[j]=0; 
                        operations++; 
                        k-=1;
                    }
                    else if( locked[j+1] == 1 and k >0){
                        locked[j+1]=0; 
                        operations++; 
                        k-=1;
                    }
                }
                if( nums[j] > nums[j+1] and locked[j] == 0 and locked[j+1] == 0  ){
                    swap(nums[j], nums[j+1]); 
                    operations++; 
                }
            }
            if( temp == nums ) return operations;
        }        
        return -1;
    }
};
