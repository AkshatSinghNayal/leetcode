class Solution {
public:
    string largestGoodInteger(string nums) { 
        int right = 0 ;
       char ele ; int left=0;
       string result ;
       int maxi = -1;
        while(right<nums.size()){
            
            if( nums[left] == nums[right]){
                result+=nums[left];
            }

           else if(nums[left]!=nums[right]){
                left=right;
                result="";
                result+=nums[left];
            }
           
           if(result.size() == 3){
             int temp = stoi(result);
             maxi = max(maxi , temp);
             result="";
           }
            

            
            right++;
        }
        if( maxi == -1){
            return "";

        }else{
            if(maxi == 0){
                return "000";
            }
            else return to_string(maxi);
        }
    }
};