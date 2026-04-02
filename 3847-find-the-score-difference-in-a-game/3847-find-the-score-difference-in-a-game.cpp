class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int first =0 ; 
        int second = 0; 
        bool active = true ; 
        int indexToMaintain = 5; 
        int n  =  nums.size();
        int i  =  0  ; 
        while( i< n ){
            
            if(  nums[i]%2!=0 ){
                active = !active;
            }
             if( i == indexToMaintain) {
                    indexToMaintain+=6;
                    active = !active;
                }
            if(active){
                first+=nums[i]; 
            }
            else{
                second+=nums[i]; 
            }

            i++; 
        }   

        cout << first << "hi" << second ; 
        return ( first - second ) ; 

    }
};